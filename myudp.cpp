#include "myudp.h"

MyUDP::MyUDP(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::Any,1234);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}


void MyUDP::readyRead()
{
    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;
    socket-> readDatagram(Buffer.data(),Buffer.size(),&sender,&senderPort);

    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << Buffer;

}
