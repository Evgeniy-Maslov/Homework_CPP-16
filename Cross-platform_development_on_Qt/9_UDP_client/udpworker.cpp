#include "udpworker.h"

UDPworker::UDPworker(QObject *parent) : QObject(parent)
{



}

/*!
 * @brief Метод инициализирует UDP сервер
 */
void UDPworker::InitSocket()
{
    serviceUdpSocket = new QUdpSocket(this);
    userUdpSocket = new QUdpSocket(this);
    /*
     * Соединяем присваиваем адрес и порт серверу и соединяем функцию
     * обраотчик принятых пакетов с сокетом
     */
    serviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT_1);
    userUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT_2);

    connect(serviceUdpSocket, &QUdpSocket::readyRead, this, [=](){readPendingDatagrams(serviceUdpSocket);});
    QObject::connect(userUdpSocket, &QUdpSocket::readyRead, this, [=](){readPendingDatagrams(userUdpSocket);});
}

/*!
 * @brief Метод осуществляет обработку принятой датаграммы
 */
void UDPworker::ReadDatagram(QNetworkDatagram &datagram)
{
    QByteArray data;
    data = datagram.data();

    QDataStream inStr(&data, QIODevice::ReadOnly);
    if(datagram.senderPort() == BIND_PORT_1){
        QDateTime dataTime;
        inStr >> dataTime;
        emit sig_sendTimeToGUI(dataTime);
    }
    else{
        QString dataInfo;
        inStr >> dataInfo;
        emit sig_sendInfoToGUI(dataInfo);
    }
}
/*!
 * @brief Метод осуществляет опередачу датаграммы
 */
void UDPworker::SendDatagram(QByteArray data, bool x)
{
    /*
     *  Отправляем данные на localhost и задефайненный порт
     */
    if (x)
    {
        serviceUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT_1);
    }
    else
        userUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT_2);
}

/*!
 * @brief Метод осуществляет чтение датаграм из сокета
 */
void UDPworker::readPendingDatagrams(QUdpSocket *UdpSocket)
{
    /*
     *  Производим чтение принятых датаграмм
     */
    while(UdpSocket->hasPendingDatagrams())
    {
        localAddress = UdpSocket->localAddress();
        localHost =  UdpSocket->localPort();
        DatagramSize = UdpSocket->pendingDatagramSize();
        QNetworkDatagram datagram = UdpSocket->receiveDatagram();
        ReadDatagram(datagram);
    }
}

QHostAddress UDPworker::get_localAddress()
{
    return localAddress;
}

quint16 UDPworker::get_localHost()
{
    return localHost;
}

quint64 UDPworker::get_DatagramSize()
{
    return DatagramSize;
}
