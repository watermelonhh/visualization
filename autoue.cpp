#include "autoue.h"
#include <QDebug>
#include <QMessageBox> // 提示框
#include <cmath>
#include "mainwindow.h"
#include "global.h"
autoue::autoue(QObject *parent) : QObject(parent)
{

}

class Point3f {
public:
    int x, y, z;
    Point3f(int x, int y, int z) : x(x), y(y), z(z) { }
};

void autoue::UnderwaterGuideTrajectoryGenerator()
{
    // 生成水下引导轨迹

    // 螺旋沉降
    // 圆半径、圆心坐标、z轴步长
    //int r = 3000, center_x = 6000, center_y = 11070, center_z=-2030;
    int r = 3000, center_x = 23915, center_y = 23915, center_z=0;
    for (size_t i = 0; i < filedataList.size(); i++) {
        qDebug() << "x:" << filedataList[i].Value1
                 << "y:" << filedataList[i].Value2
                 << "z:" << filedataList[i].Value3;
        //trajectory->push_back(Point3f((filedataList[i].Value1-center_x), (filedataList[i].Value2-center_y),(filedataList[i].Value3+center_z)));
        trajectory->push_back(Point3f((filedataList[i].Value1*35+center_x), (filedataList[i].Value2*35+center_y),(filedataList[i].Value3*35)));
    }


    return;
}

void autoue::TrajectoryGenerator()
{
    UnderwaterGuideTrajectoryGenerator();
}

std::string autoue::GenerateSendDataFromPoint3d(Point3f& point)
{
    return std::to_string(point.x) + "+" +
           std::to_string(point.y) + "#" +
           std::to_string(point.z) + "*";
}

void autoue::CopyStringToCharArray(std::string str, char* arr)
{
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < str.size(); i++)
        arr[i] = str[i];
    arr[str.size()] = '\0';
}


//void autoue::appendOutput(const QString& text)
//{
//    // 将文本追加到 QTextEdit 中
//    ui->outputTextEdit->append(text);
//}

void autoue::on_pushButton_clicked()
{
    // 初始化socket库
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData)) {
        QMessageBox::critical(nullptr, "错误", "Failed to initialize socket library!");
        return;
    }

    // 创建socket
    SOCKET clientSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (clientSocket == INVALID_SOCKET) {
        QMessageBox::critical(nullptr, "错误", "Failed to create socket!");
        WSACleanup();
        return;
    }

    // 配置端口信息
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(1623);
    serverAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    // 清空发送缓冲区
    memset(sendBuf, 0, sizeof(sendBuf));

    // 生成轨迹
    TrajectoryGenerator();

    // 定义轨迹数据指针
    std::vector<Point3f>::iterator it = trajectory->begin();

    // 发送数据
    while (it != trajectory->end()) {
        CopyStringToCharArray(GenerateSendDataFromPoint3d(*it), sendBuf);

        int sendLen = strlen(sendBuf);
        int ret = sendto(clientSocket, sendBuf, sendLen, 0,
                         (SOCKADDR*)&serverAddr, sizeof(serverAddr));

        if (ret == SOCKET_ERROR) {
            QMessageBox::critical(nullptr, "错误", "Failed to send data!");
            closesocket(clientSocket);
            WSACleanup();
            return;
        }


        // delay some time
        for (int i = -5000000; i < 5000000; i++);

        qDebug() << "Send data:" << sendBuf;
        // 将发送的数据显示在 QTextEdit 上
        //appendOutput(QString("Send data: %1").arg(sendBuf));
        it++;
    }

    //QMessageBox::information(this, "完成", "轨迹发送完成！");
    //appendOutput("轨迹发送完成！");
    closesocket(clientSocket);
    WSACleanup();
}
