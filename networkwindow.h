#ifndef NETWORKWINDOW_H
#define NETWORKWINDOW_H

#include <QWidget>
//#include "ui_networkwindow.h"
#include <vector>   // 用于存储轨迹
#include <string>   // 用于生成发送数据
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>

namespace Ui {
class NetworkWindow;
}

class NetworkWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NetworkWindow(QWidget *parent = nullptr);
    ~NetworkWindow();

private:
    Ui::NetworkWindow *ui;
    void on_pushButton_clicked();// 发送数据 按钮
    // 你的代码中的成员变量和函数
    char sendBuf[65536];
    std::vector<class Point3f> trajectory;

    void CircleTrajectoryGenerator();
    void UnderwaterRecycleTrajectoryGenerator();
    void UnderwaterGuideTrajectoryGenerator();
    void TrajectoryGenerator();
    std::string GenerateSendDataFromPoint3d(Point3f& point);
    void CopyStringToCharArray(std::string str, char* arr);

    void appendOutput(const QString& text);  // 用于追加输出到 QTextEdit
};

#endif // NETWORKWINDOW_H
