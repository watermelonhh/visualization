#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filewindow.h"
#include "serialwindow.h"
#include "networkwindow.h"
#include "QDebug"
#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>
#include <QFile>
#include <QString>
#include <QThread>
#include <QDebug>
#include <basedefine.h>
#include <vector>
#include <qstring.h>
#include <qtimer.h>
#include <qcustomplot.h>
#include "global.h" //全局变量，用来处理的filedatalist放在里面了
#include "autoue.h"
#include "udpsender.h"

UPLOAD_COMPLEX_PACKET g_processbuffer = {0};
void get_dsp(R232_MODULE *pr232Module);//解包
R232_MODULE g_r232Module;
//std::vector<three_DOUBLE_ARRAY> filedataList;  //存储文件解包的数据 x,y,z
std::vector<THREE_DOUBLE_ARRAY_QT> filedatatextList;  //存储文件解包的数据
std::vector<QString> timelist;  //存放时间

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
//    , fileWindowptr(new FileWindow(this))
//    , serialWindowptr(new SerialWindow(this))
//    , networkWindowptr(new NetworkWindow(this))
    , fileWindowptr(nullptr)
    , serialWindowptr(nullptr)
    , networkWindowptr(nullptr)  // 延迟创建，点了按钮之后才会出现窗口
{
    ui->setupUi(this);
    udpSender = new UDPSender(this);  // 初始化UDP发送器

     QAction *actionFileptr = ui->actionFile->addAction("Open File");
     QAction *actionSerialptr = ui->actionSerial->addAction("Open File");
     connect(actionFileptr, &QAction::triggered, this, &MainWindow::openFile);
     //QAction *actionNetworkptr = ui->actionNetwork->addAction("Open File");
    // 连接菜单栏的 QAction
    connect(actionFileptr, &QAction::triggered, this, &MainWindow::openFileWindow);
    connect(actionSerialptr, &QAction::triggered, this, &MainWindow::openSerialWindow);
    //connect(actionNetworkptr, &QAction::triggered, this, &MainWindow::openNetworkWindow);
    connect(ui->actionNetwork, &QMenu::aboutToShow, this, &MainWindow::openNetworkWindow);
    udpSender->sendPosition(23915,23990,8765);

    if(ui->mytextEdit) {
           ui->mytextEdit->setPlainText("UI初始化成功！");
       } else {
           qDebug() << "错误：未找到mytextEdit控件";
       }


}

MainWindow::~MainWindow()
{
    delete ui;
    delete fileWindowptr;
    delete serialWindowptr;
    delete networkWindowptr;
}

void MainWindow::openFileWindow() {
    if (!fileWindowptr) {
           fileWindowptr = new FileWindow(this);
       }
    fileWindowptr->show();

}

void MainWindow::openSerialWindow() {
    if (!serialWindowptr) {
           serialWindowptr = new SerialWindow(this);
       }
    serialWindowptr->show();
}

void MainWindow::openNetworkWindow() {
    qDebug() << "openNetworkWindow() called";
    if (!networkWindowptr) {
         networkWindowptr = new NetworkWindow(this);//新建 网口助手的窗口
        }
    networkWindowptr->show();
}

// 打开文件的槽函数
void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Data Files (*.dat);;All Files (*.*)");

    if (!fileName.isEmpty()) {
        QMessageBox::information(this, "Selected File", "You selected: " + fileName);
    } else {
        QMessageBox::warning(this, "No File Selected", "Please select a file.");
        return;
    }

    QFile m_replayfile(fileName);
       if (!m_replayfile.open(QIODevice::ReadOnly)) {
           QMessageBox::critical(this, "Error", "Failed to open the selected file.");
           return;
       }

       // ✅ 清空旧数据
          filedataList.clear(); //画图的写在了全局变量
          filedatatextList.clear();
          timelist.clear();

          // ✅ 清空图表和文本显示
          ui->qcustomplot->clearGraphs();
          ui->xplotwidget->clearGraphs();
          ui->yplotwidget->clearGraphs();
          ui->zplotwidget->clearGraphs();
          ui->mytextEdit->clear();

       int counttest = 0;
       unsigned char TransferBuffer[2048];
       qint64 m_replydatalen = static_cast<qint64>(sizeof(UPLOAD_COMPLEX_PACKET) + RAY_PACKET_LEN + POSFIER_PACKET_LEN);

       while (true)
       {
           counttest++;
           qDebug() << counttest;
           char recvbuffer[1108] = {0};  //问题出在这里，加了结构体之后变长了，所以原来的1036内存溢出了
           //char recvbuffer[1036] = {0};
           int readlen = static_cast<int>(m_replayfile.read(recvbuffer, m_replydatalen));
           if (readlen <= 0)
           {
               qDebug() << "file EOF " << readlen;
               break;
           }

           int bufferlen = sizeof(g_r232Module.TransferBuffer);
           /*******自己加的安全检查**********/
           if (readlen > bufferlen || readlen <= 0) {
               qDebug() << "Read length error: " << readlen;
               break;
           }
           memcpy(g_r232Module.TransferBuffer,
                  g_r232Module.TransferBuffer + readlen,
                  static_cast<size_t>(bufferlen - readlen));
           memcpy(g_r232Module.TransferBuffer + bufferlen - readlen,
                  recvbuffer, static_cast<size_t>(readlen));
           qDebug("here1");
           get_dsp(&g_r232Module);//对TransferBuffer数据检包每次检包的数据存放在g_processbuffer中
           //QThread::msleep(100);  // 1秒延时
        }
       qDebug("good!");
       for (size_t i = 0; i < filedataList.size(); i++) {
           qDebug() << "x:" << filedataList[i].Value1
                    << "y:" << filedataList[i].Value2
                    << "z:" << filedataList[i].Value3;
       }
//       for (size_t i = 0; i < timelist.size(); i++) {
//           qDebug() << "Value1:" << timelist[i];

//       }




//       QTimer* timer = new QTimer(ui->mytextEdit);
//          int index = 0;

//          QObject::connect(timer, &QTimer::timeout, [=]() mutable {
//              if (index >= filedatatextList.size()) {
//                  timer->stop();
//                  timer->deleteLater();
//                  return;
//              }

//              ui->mytextEdit->clear();
//              QString displayText = QString("时间： %1\n东向: %2\n北向: %3\n天向: %4\n").arg(timelist[index]).arg(filedatatextList[index].Value1)
//                                                       .arg(filedatatextList[index].Value2)
//                                                       .arg(filedatatextList[index].Value3);
//              ui->mytextEdit->setPlainText(displayText);
//              index++;
//          });

        //timer->start(1000); // 每秒更新一次
        m_replayfile.close();

       plotGraph();  //调用绘图函数
       startTextTimer();//显示左上角那个框框的
       //自动ue中显示
       autoue a;  //实例化了才能用里面的函数
       a.on_pushButton_clicked();
       return;
}


// 将 8 字节数据转换为 double 的函数
double convertToDouble(const char* data) {
    double result;
    memcpy(&result, data, sizeof(double));
    return result;
}

//////解包
void get_dsp(R232_MODULE *pr232Module)//解包
{
    //弹窗提示编写界面的人要换成非模态对话框！！！
    unsigned char *buffer =pr232Module->TransferBuffer;
    int buffer_len = sizeof(pr232Module->TransferBuffer);

    unsigned char *p_end = nullptr;
    unsigned char *pc = nullptr;
    unsigned char flag = 0;
    int j= 0,k = 0;

    while(flag == 0)
    {
        for(j=0;j<buffer_len-2;j++)
        {
            if(buffer[j] == '$' && buffer[j+1] == 'H' && buffer[j+2] == 'E' && buffer[j+3] == 'U' && flag == 0)
            {
                flag = 1;
                pc = buffer+j;
                break;
            }
        }
        if(flag == 1)
        {
             for(k=j+1;k<buffer_len;k++)
             {
                if(pc[9] == 'P' && pc[10] == 'O' && pc[11] == 'S' && buffer[k-1] == '*' && buffer[k] == 'F')
                {
                    flag = 2;
                    p_end = buffer+k;
                    break;
                }
             }
        }
        if(flag<= 1)
        {
            break;
        }
        else
        {

        }
        if(flag == 2) //定位包
        {
            /*******自己加的安全检查**********/
            if (pc == nullptr || p_end == nullptr) {
                qDebug() << "Invalid packet boundaries!";
                return;
            }
            if((p_end-pc+1) == sizeof(UPLOAD_COMPLEX_PACKET)) //数据包
            {
                memcpy(&g_processbuffer,pc,static_cast<size_t>(p_end-pc+1));
                qDebug("解包Here");
                //调试解包信息
//              qDebug("Value1: %s", g_processbuffer.ArrayCoordinateArray.Value1);
//              qDebug("Value2: %s", g_processbuffer.ArrayCoordinateArray.Value2);
//              qDebug("Value3: %s", g_processbuffer.ArrayCoordinateArray.Value3);

                  //显示16进制
//                for(int i = 0; i < 8; i++) {
//                    qDebug("%02X ", (unsigned char)g_processbuffer.ArrayCoordinateArray.Value1[i]);
//                }
//                for(int i = 0; i < 8; i++) {
//                    qDebug("%02X ", (unsigned char)g_processbuffer.ArrayCoordinateArray.Value2[i]);
//                }
//                for(int i = 0; i < 8; i++) {
//                    qDebug("%02X ", (unsigned char)g_processbuffer.ArrayCoordinateArray.Value3[i]);
//                }
                //arraycorordinate是回收装置相对于AUV的位置，AUV是原点。取负，让回收装置成为原点
                double value1 = convertToDouble(g_processbuffer.ArrayCoordinateArray.Value1)*(-1);
                double value2 = convertToDouble(g_processbuffer.ArrayCoordinateArray.Value2)*(-1);
                double value3 = convertToDouble(g_processbuffer.ArrayCoordinateArray.Value3)*(-1);

//               qDebug() << "Value1 (double):" << value1;
//               qDebug() << "Value2 (double):" << value2;
//               qDebug() << "Value3 (double):" << value3;
               //解包数据存进数组里
               three_DOUBLE_ARRAY data;

               // 赋值 Value1
               data.Value1=value1;
               data.Value2=value2;
               data.Value3=value3;

               // 添加到 vector
               //剔除野点
               if (g_processbuffer.Status>=1){
                   filedataList.push_back(data);
               }

               // 在 QTextEdit 中显示数据,是string格式
               THREE_DOUBLE_ARRAY_QT data1;
               data1.Value1 = QString::number(value1, 'f', 6);
               data1.Value2 = QString::number(value2, 'f', 6);
               data1.Value3 = QString::number(value3, 'f', 6);
               filedatatextList.push_back(data1);

               //把时间存到数组里面  注意：是GPS时间  GPS时间的典型格式：week + seconds_of_week 采用了无敌麻烦的这个格式

//              const qint64 GPS_UNIX_OFFSET = 315964800;  // GPS 起点相对于 Unix 时间戳的偏移（秒）

//               char* timedata = g_processbuffer.GpsArray.Value1;

//               uint16_t gpsWeek;
//               uint32_t secondsOfWeek;

//               // 从 Value1 中提取 week 和 seconds（确保是小端格式）
//               memcpy(&gpsWeek, timedata, sizeof(uint16_t));
//               memcpy(&secondsOfWeek, timedata + 2, sizeof(uint32_t));

//               // 计算总秒数
//               qint64 gpsSeconds = static_cast<qint64>(gpsWeek) * 7 * 24 * 60 * 60 + secondsOfWeek;

//               // 转换为 Unix 秒数
//               qint64 unixSeconds = gpsSeconds + GPS_UNIX_OFFSET;

//               // 转为人类可读时间
//               QDateTime dt = QDateTime::fromSecsSinceEpoch(unixSeconds, Qt::UTC);
//               QString timeStr = dt.toString("yyyy-MM-dd HH:mm:ss");
//               timelist.push_back(timeStr);
               const qint64 GPS_UNIX_OFFSET = 315964800;  // GPS 起点相对于 Unix 时间戳的偏移（秒）

               char* timedata = g_processbuffer.GpsArray.Value1;

               uint16_t gpsWeek;
               uint32_t secondsOfWeek;

               // 从 Value1 中提取 week 和 seconds（确保是小端格式）
               gpsWeek = qFromLittleEndian<quint16>(timedata);  // 使用 Qt 的大小端转换函数
               secondsOfWeek = qFromLittleEndian<quint32>(timedata + 2);  // 同样处理秒数

               qDebug() << "gpsWeek:" << gpsWeek;  // 调试输出 gpsWeek
               qDebug() << "secondsOfWeek:" << secondsOfWeek;  // 调试输出 secondsOfWeek

               // 计算总秒数
               qint64 gpsSeconds = static_cast<qint64>(gpsWeek) * 7 * 24 * 60 * 60 + secondsOfWeek;

               // 转换为 Unix 秒数
               qint64 unixSeconds = gpsSeconds + GPS_UNIX_OFFSET;

               qDebug() << "gpsSeconds:" << gpsSeconds;
               qDebug() << "unixSeconds:" << unixSeconds;

               // 转为人类可读时间
               QDateTime dt = QDateTime::fromSecsSinceEpoch(unixSeconds, Qt::UTC);
               QString timeStr = dt.toString("yyyy-MM-dd HH:mm:ss");
               timelist.push_back(timeStr);

               qDebug() << "Formatted time:" << timeStr;  // 最终输出的格式化时间
            }
            flag=0;
            memset(pc,0,static_cast<size_t>(p_end-pc+1));
        }
    }
}

//void MainWindow::plotGraph()
//{
//    // 1. 获取 QCustomPlot 组件（已在 UI 里添加并提升为 QCustomPlot）,sideview是侧视图
//    QCustomPlot *sideview = ui->qcustomplot;

//    // 2. 创建数据容器
//    QVector<double> x(filedataList.size()), y(filedataList.size());

//    for (size_t i = 0; i < filedataList.size(); ++i) {
//        x[i] = filedataList[i].Value1;
//        y[i] = filedataList[i].Value2;
//    }

//    // 3. 添加数据到 QCustomPlot
//    sideview->addGraph();
//    sideview->graph(0)->setData(x, y);

//    // 4. 设置坐标轴标签
//    sideview->xAxis->setLabel("Value1 (X/E)");
//    sideview->yAxis->setLabel("Value2 (Y/N)");

//    // 5. 自动缩放
//    sideview->xAxis->setRange(*std::min_element(x.begin(), x.end()), *std::max_element(x.begin(), x.end()));
//    sideview->yAxis->setRange(*std::min_element(y.begin(), y.end()), *std::max_element(y.begin(), y.end()));

//    // 6. 重新绘制
//    sideview->replot();



//    // 1. 获取 QCustomPlot 组件（已在 UI 里添加并提升为 QCustomPlot），sideview 是侧视图
//    QCustomPlot *sideview = ui->qcustomplot;

//    // 2. 创建数据容器（一次性读取所有数据，但不一次性绘图）
//    QVector<double> xAll(filedataList.size()), yAll(filedataList.size());
//    for (int i = 0; i < static_cast<int>(filedataList.size()); ++i) {
//        xAll[i] = filedataList[i].Value1;
//        yAll[i] = filedataList[i].Value2;
//    }

//    // 3. 创建图层并设置样式
//    sideview->addGraph();
//    sideview->graph(0)->setLineStyle(QCPGraph::lsNone);  // 连线风格
//    sideview->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5)); // 点风格
//    sideview->graph(0)->setPen(QPen(Qt::blue));

//    // 4. 设置坐标轴标签
//    sideview->xAxis->setLabel("Value1 (X/E)");
//    sideview->yAxis->setLabel("Value2 (Y/N)");

//    // 5. 设置坐标轴范围（可提前设置，也可以动态更新）
//    sideview->xAxis->setRange(*std::min_element(xAll.begin(), xAll.end()), *std::max_element(xAll.begin(), xAll.end()));
//    sideview->yAxis->setRange(*std::min_element(yAll.begin(), yAll.end()), *std::max_element(yAll.begin(), yAll.end()));

//    // 6. 动画绘图：每隔1秒加入一个点
//    QVector<double> xDraw, yDraw;
//    int currentIndex = 0;
//    QTimer *timer = new QTimer(this); // 确保在类里或构造函数中使用 this

//    connect(timer, &QTimer::timeout, this, [=]() mutable {
//        if (currentIndex < xAll.size()) {
//            xDraw.append(xAll[currentIndex]);
//            yDraw.append(yAll[currentIndex]);

//            sideview->graph(0)->setData(xDraw, yDraw);
//            sideview->replot();

//            currentIndex++;
//        } else {
//            timer->stop(); // 全部点画完后停止
//        }
//    });

//    timer->start(10); // 每1000ms绘制一个点

//    //overview是俯视图
//    QCustomPlot *overview = ui->qcustomplot1;

//    QVector<double> x1(filedataList.size()), y1(filedataList.size());

//    for (size_t i = 0; i < filedataList.size(); ++i) {
//        x1[i] = filedataList[i].Value1;
//        y1[i] = filedataList[i].Value3;
//    }

//    overview->addGraph();
//    overview->graph(0)->setData(x1, y1);

//    overview->xAxis->setLabel("Value1 (X/E)");
//    overview->yAxis->setLabel("Value2 (Z)");

//    overview->xAxis->setRange(*std::min_element(x1.begin(), x1.end()), *std::max_element(x1.begin(), x1.end()));
//    overview->yAxis->setRange(*std::min_element(y1.begin(), y1.end()), *std::max_element(y1.begin(), y1.end()));

//    overview->replot();
//    // 1. 获取 QCustomPlot 组件（已在 UI 里添加并提升为 QCustomPlot），sideview 是侧视图
//    QCustomPlot *overview = ui->qcustomplot1;

//    // 2. 创建数据容器（一次性读取所有数据，但不一次性绘图）
//    QVector<double> xAll1(filedataList.size()), yAll1(filedataList.size());
//    for (int i = 0; i < static_cast<int>(filedataList.size()); ++i) {
//        xAll1[i] = filedataList[i].Value1;
//        yAll1[i] = filedataList[i].Value3;
//    }

//    // 3. 创建图层并设置样式
//    overview->addGraph();
//    overview->graph(0)->setLineStyle(QCPGraph::lsNone);  // 连线风格
//    overview->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5)); // 点风格
//    overview->graph(0)->setPen(QPen(Qt::blue));

//    // 4. 设置坐标轴标签
//    overview->xAxis->setLabel("Value1 (X/E)");
//    overview->yAxis->setLabel("Value2 (Y/N)");

//    // 5. 设置坐标轴范围（可提前设置，也可以动态更新）
//    overview->xAxis->setRange(*std::min_element(xAll1.begin(), xAll1.end()), *std::max_element(xAll1.begin(), xAll1.end()));
//    overview->yAxis->setRange(*std::min_element(yAll1.begin(), yAll1.end()), *std::max_element(yAll1.begin(), yAll1.end()));

//    // 6. 动画绘图：每隔1秒加入一个点
//    QVector<double> xDraw1, yDraw1;
//    int currentIndex1 = 0;
//    //QTimer *timer1 = new QTimer(this); // 确保在类里或构造函数中使用 this

//    connect(timer, &QTimer::timeout, this, [=]() mutable {
//        if (currentIndex1 < xAll1.size()) {
//            xDraw1.append(xAll1[currentIndex1]);
//            yDraw1.append(yAll1[currentIndex1]);

//            overview->graph(0)->setData(xDraw1, yDraw1);
//            overview->replot();

//            currentIndex1++;
//        } else {
//            timer->stop(); // 全部点画完后停止
//        }
//    });

//    timer->start(10); // 每1000ms绘制一个点


//    // 获取 QCustomPlot 指针
//    QCustomPlot* xplotgraph = ui->xplotwidget;
//    QCustomPlot* yplotgraph = ui->yplotwidget;
//    QCustomPlot* zplotgraph = ui->zplotwidget;

//    // 1. 准备数据
//    int totalPoints = static_cast<int>(filedataList.size());
//    QVector<double> xAll2(totalPoints), y1All(totalPoints), y2All(totalPoints), y3All(totalPoints);
//    for (int i = 0; i < totalPoints; ++i) {
//        xAll2[i] = i;  // x 是点的编号
//        y1All[i] = filedataList[i].Value1;
//        y2All[i] = filedataList[i].Value2;
//        y3All[i] = filedataList[i].Value3;
//    }

//    // 2. 初始化三张图
//    auto setupGraph = [](QCustomPlot* plot, const QString& xlabel, const QString& ylabel, const QVector<double>& xData, const QVector<double>& yData) {
//        plot->addGraph();
//        plot->graph(0)->setLineStyle(QCPGraph::lsNone);
//        plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
//        plot->graph(0)->setPen(QPen(Qt::blue));
//        plot->xAxis->setLabel(xlabel);
//        plot->yAxis->setLabel(ylabel);
//        plot->xAxis->setRange(0, xData.size());
//        plot->yAxis->setRange(*std::min_element(yData.begin(), yData.end()), *std::max_element(yData.begin(), yData.end()));
//    };

//    setupGraph(xplotgraph, "Index", "x", xAll2, y1All);
//    setupGraph(yplotgraph, "Index", "y", xAll2, y2All);
//    setupGraph(zplotgraph, "Index", "z", xAll2, y3All);

//    // 3. 动态绘图（复用一个 QTimer）
//    QVector<double> xDraw2, y1Draw, y2Draw, y3Draw;
//    int currentIndex2 = 0;

//    //QTimer* timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, [=]() mutable {
//        if (currentIndex2 < xAll2.size()) {
//            double x = xAll2[currentIndex2];
//            xDraw2.append(x);
//            y1Draw.append(y1All[currentIndex2]);
//            y2Draw.append(y2All[currentIndex2]);
//            y3Draw.append(y3All[currentIndex2]);

//            xplotgraph->graph(0)->setData(xDraw2, y1Draw);
//            yplotgraph->graph(0)->setData(xDraw2, y2Draw);
//            zplotgraph->graph(0)->setData(xDraw2, y3Draw);

//            xplotgraph->replot();
//            yplotgraph->replot();
//            zplotgraph->replot();

//            currentIndex2++;
//        } else {
//            timer->stop();
//        }
//    });

//    timer->start(10);  // 每10ms绘制一个点

//}

void MainWindow::plotGraph()
{
    // 清除旧图层
    auto clearPlot = [](QCustomPlot* plot) {
        plot->clearGraphs();
        plot->replot();
    };

    clearPlot(ui->qcustomplot);
    clearPlot(ui->qcustomplot1);
    clearPlot(ui->xplotwidget);
    clearPlot(ui->yplotwidget);
    clearPlot(ui->zplotwidget);

    // 构造数据
    QVector<double> xAll, yAll, zAll;
    for (const auto& item : filedataList) {
        xAll.append(item.Value1);
        yAll.append(item.Value2);
        zAll.append(item.Value3);
    }

    QVector<double> indexList(xAll.size());
    std::iota(indexList.begin(), indexList.end(), 0); // [0, 1, 2, ...]

    // 初始化所有图表
    auto initGraph = [](QCustomPlot* plot, const QString& xlabel, const QString& ylabel,
                        const QVector<double>& xData, const QVector<double>& yData) {
        plot->addGraph();
        plot->graph(0)->setLineStyle(QCPGraph::lsNone);//isnone是不连线
        plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));//ssDisc是实心点
        plot->graph(0)->setPen(QPen(Qt::blue));
        plot->xAxis->setLabel(xlabel);
        plot->yAxis->setLabel(ylabel);
        plot->xAxis->setRange(*std::min_element(xData.begin(), xData.end()), *std::max_element(xData.begin(), xData.end()));
        plot->yAxis->setRange(*std::min_element(yData.begin(), yData.end()), *std::max_element(yData.begin(), yData.end()));
    };

    initGraph(ui->qcustomplot, "x轴/m(前向为正)", "y轴/m(右向为正)", xAll, yAll);
    initGraph(ui->qcustomplot1, "x轴/m(前向为正)", "z轴/m(天向为正)", xAll, zAll);
    initGraph(ui->xplotwidget, "定位序号", "x轴/m(前向为正)", indexList, xAll);
    initGraph(ui->yplotwidget, "定位序号", "y轴/m(右向为正)", indexList, yAll);
    initGraph(ui->zplotwidget, "定位序号", "z轴/m(天向为正)", indexList, zAll);

    // 清空绘图缓存
    QVector<double> xDraw, yDraw, zDraw;
    QVector<double> indexDraw;
    QVector<double> x1Draw, y1Draw;
    QVector<double> x2Draw, z1Draw;

    int currentIndex = 0;
    QTimer* timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, [=]() mutable {
        if (currentIndex >= xAll.size()) {
            timer->stop();
            timer->deleteLater();
            return;
        }

        double x = xAll[currentIndex];
        double y = yAll[currentIndex];
        double z = zAll[currentIndex];

        // 所有图同步添加数据
        xDraw.append(x);
        yDraw.append(y);
        zDraw.append(z);
        indexDraw.append(currentIndex);

        // qcustomplot: x vs y
        ui->qcustomplot->graph(0)->setData(xDraw, yDraw);
        ui->qcustomplot->replot();

        // qcustomplot1: x vs z
        ui->qcustomplot1->graph(0)->setData(xDraw, zDraw);
        ui->qcustomplot1->replot();

        // xplot: index vs x
        ui->xplotwidget->graph(0)->setData(indexDraw, xDraw);
        ui->xplotwidget->replot();

        // yplot: index vs y
        ui->yplotwidget->graph(0)->setData(indexDraw, yDraw);
        ui->yplotwidget->replot();

        // zplot: index vs z
        ui->zplotwidget->graph(0)->setData(indexDraw, zDraw);
        ui->zplotwidget->replot();

        currentIndex++;
    });

    timer->start(10); // 每10ms画一个点
}

void MainWindow::startTextTimer()
{
    if (filedatatextList.empty()) return;

    static QTimer* textTimer = nullptr;

    if (textTimer) {
        textTimer->stop();
        textTimer->deleteLater();
    }

    textTimer = new QTimer(this);
    int index = 0;

    connect(textTimer, &QTimer::timeout, this, [=]() mutable {
        if (index >= filedatatextList.size()) {
            textTimer->stop();
            textTimer->deleteLater();
            return;
        }

        QString displayText = QString("时间： %1\n东向: %2\n北向: %3\n天向: %4")
                              .arg(timelist[index])
                              .arg(filedatatextList[index].Value1)
                              .arg(filedatatextList[index].Value2)
                              .arg(filedatatextList[index].Value3);

        ui->mytextEdit->setPlainText(displayText);
        index++;
    });

    textTimer->start(10);  // 每秒更新
}


