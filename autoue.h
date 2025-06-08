#ifndef AUTOUE_H
#define AUTOUE_H

#include <QObject>
#include <vector>   // 用于存储轨迹
#include <string>   // 用于生成发送数据
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>

class Point3f; // 前向声明
class autoue : public QObject
{
    Q_OBJECT
public:
    explicit autoue(QObject *parent = nullptr);

signals:
private:

    // 你的代码中的成员变量和函数
    char sendBuf[65536];
    std::vector<Point3f>* trajectory;
    //std::vector<class Point3f> trajectory;

    void UnderwaterGuideTrajectoryGenerator();
    void TrajectoryGenerator();
    std::string GenerateSendDataFromPoint3d(Point3f& point);
    void CopyStringToCharArray(std::string str, char* arr);

    //void appendOutput(const QString& text);  // 用于追加输出到 QTextEdit
public:
    void on_pushButton_clicked();// 发送数据 按钮
};

#endif // AUTOUE_H
