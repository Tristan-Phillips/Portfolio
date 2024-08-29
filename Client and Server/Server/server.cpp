#include "server.h"

Server::Server(QObject *parent)
    : QTcpServer{parent}
{}

void Server::close()
{
    QTcpServer::close();
}

QByteArray Server::getData() const
{
    return m_data;
}

void Server::disconnected()
{
    m_client->disconnect();
}

void Server::readyRead()
{
    m_data = m_client->readAll();
    if(!m_data.isEmpty()){
        emit xmlReady();
    }
}

void Server::incomingConnection(qintptr handle)
{
    QTcpSocket *socket = new QTcpSocket();
    socket->setSocketDescriptor(handle);

    if(!socket->waitForConnected(3000)){
        delete socket;
        return;
    }
    m_client = socket;
    connect(socket, &QTcpSocket::disconnected, this, &Server::disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &Server::readyRead);
}
