#define _WIN32_WINNT 0x0600
#include <winsock2.h>      // 要放在最前面
#include <ws2tcpip.h>
#include <windows.h>
#include <QDebug>
#include "udpsender.h"
#pragma comment(lib, "ws2_32.lib")

UDPSender::UDPSender(QObject *parent) : QObject(parent)
{
    // 初始化Winsock（和您的代码一致）
       if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
           qCritical() << "WSAStartup failed:" << WSAGetLastError();
           return;
       }

       // 配置目标地址（改用inet_addr）
       RecvAddr.sin_family = AF_INET;
       RecvAddr.sin_port = htons(12345);
       RecvAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

       if (RecvAddr.sin_addr.s_addr == INADDR_NONE) {
           qCritical() << "Invalid IP address";
           WSACleanup();
           return;
       }

}

UDPSender::~UDPSender()
{
    if (SendSocket != INVALID_SOCKET) {
        closesocket(SendSocket);
    }
    WSACleanup();
}

bool UDPSender::initializeSocket()
{
    SendSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (SendSocket == INVALID_SOCKET) {
        qCritical() << "Socket creation failed:" << WSAGetLastError();
        return false;
    }
    return true;
}

void UDPSender::sendPosition(float x, float y, float z)
{
    if (SendSocket == INVALID_SOCKET) {
        if (!initializeSocket()) return;
    }

    // 格式化数据为字符串（X,Y,Z）
    QString data = QString("%1,%2,%3").arg(x).arg(y).arg(z);
    int bytesSent = sendto(
        SendSocket,
        data.toStdString().c_str(),
        data.size(),
        0,
        (sockaddr*)&RecvAddr,
        sizeof(RecvAddr)
    );

    if (bytesSent == SOCKET_ERROR) {
        qCritical() << "sendto failed:" << WSAGetLastError();
    } else {
        qDebug() << "Sent:" << data;
    }
    qDebug()<<"position initilized!";
}
