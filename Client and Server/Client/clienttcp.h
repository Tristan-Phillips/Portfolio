#ifndef CLIENTTCP_H
#define CLIENTTCP_H

//External Includes
#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QByteArray>

class clientTCP : public QObject
{
    Q_OBJECT
public:
    clientTCP();
    void send(QByteArray data);
private:
    QTcpSocket *m_socket;
    QHostAddress m_host = QHostAddress::LocalHost;
    quint16 m_port = 6164;
    /*Port and Host are permanent and cannot be changed*/
};

#endif // CLIENTTCP_H
