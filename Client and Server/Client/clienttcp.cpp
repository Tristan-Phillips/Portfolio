5//Local Includes
#include "clienttcp.h"

//External Includes
#include <QMessageBox>

clientTCP::clientTCP()
    : m_socket{new QTcpSocket}
{}

void clientTCP::send(QByteArray data)
{
    /*Connection is made
     * then data is sent
     * then connection is closed*/

        m_socket->connectToHost(m_host, m_port);
    //Only wait 3 seconds to connect
        if(m_socket->waitForConnected(3000))
        {
            m_socket->write(data);
            QMessageBox::information(nullptr, "Delivered", "The data has sucessfully been sent to the server");
            m_socket->close();
            return;
        }
        else
        {
            /*The connection could not be made to the host
            * or the host could not be found*/
            QMessageBox::critical(nullptr, "Error", "The data could not be sent to the server");
            m_socket->close();
            return;
        }
    m_socket->close();
}
