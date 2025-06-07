#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>


#define BIND_PORT_1 12345
#define BIND_PORT_2 23456

class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void InitSocket( void );
    void ReadDatagram( QNetworkDatagram &datagram);
    void SendDatagram(QByteArray data, bool);
    QHostAddress get_localAddress();
    quint16 get_localHost();
    quint64 get_DatagramSize();

Q_SIGNALS:
    void sig_sendTimeToGUI(QDateTime data);
    void sig_sendInfoToGUI(QString data);

private Q_SLOTS:
    void readPendingDatagrams(QUdpSocket *UdpSocket);

private:
    QUdpSocket* serviceUdpSocket;
    QUdpSocket *userUdpSocket;
    QHostAddress localAddress;
    quint16 localHost;
    quint64 DatagramSize;

};

#endif // UDPWORKER_H
