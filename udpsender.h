#ifndef UDPSENDER_H
#define UDPSENDER_H
#pragma once
#include <QObject>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <QObject>

class UDPSender : public QObject
{
    Q_OBJECT
public:
    explicit UDPSender(QObject *parent = nullptr);
    bool initializeSocket();  // 初始化Socket
    void sendPosition(float x, float y, float z);  // 发送位置数据
    ~UDPSender();  // 声明析构函数
signals:

private:
    SOCKET SendSocket = INVALID_SOCKET;
    sockaddr_in RecvAddr;
    WSADATA wsaData;  // 添加这行声明成员变量
};

#endif // UDPSENDER_H
