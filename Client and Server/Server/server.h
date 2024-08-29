#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

class Server : public QTcpServer
{
/*

    This class is used to listen for data from a client.

*/
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void close();
    QByteArray getData() const;

signals:
    void xmlReady();

public slots:
    void disconnected();
    void readyRead();
    void incomingConnection(qintptr handle);
    
private:
    //QList<QTcpSocket*> m_clientList;
    QTcpSocket* m_client;
    QString m_connectedMessage = "CONNECTED";
    QByteArray m_data;
};

#endif // SERVER_H
