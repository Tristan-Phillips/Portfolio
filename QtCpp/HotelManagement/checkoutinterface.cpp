#include "checkoutinterface.h"
#include <QMessageBox>
#include <QVBoxLayout>

CheckOutInterface::CheckOutInterface(Hotel *hotel, QWidget *parent)
{
    m_hotel = hotel;
    setupUI();
}

void CheckOutInterface::setupUI()
{
    updateComboBoxRooms();
    setWindowTitle("Check Out");
    setFixedSize(400, 400);
    setModal(true);

    m_comboBox_room->setFixedSize(200, 30);
    m_pushButton_checkOut->setFixedSize(100, 30);
    m_pushButton_cancel->setFixedSize(100, 30);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_comboBox_room);
    mainLayout->addWidget(m_pushButton_checkOut);
    mainLayout->addWidget(m_pushButton_cancel);
    setLayout(mainLayout);

    connect(m_pushButton_checkOut, &QPushButton::clicked, this, &CheckOutInterface::checkOutRoom);
    connect(m_pushButton_cancel, &QPushButton::clicked, this, &CheckOutInterface::close);
}

void CheckOutInterface::updateComboBoxRooms()
{
    m_comboBox_room->clear();
    for(int i = 0; i < m_hotel->getBookings().size(); i++)
    {
        m_comboBox_room->addItem(QString::number(m_hotel->getBookings()[i]->getRoomNo()));
    }
}

void CheckOutInterface::checkOutRoom()
{
    int roomNum = m_comboBox_room->currentText().toInt();
    if(m_hotel->checkOutRoom(roomNum))
    {

        QMessageBox::information(this, "Check Out", "Room " + QString::number(roomNum) + " has been checked out.");
        updateComboBoxRooms();
    }
    else
    {
        QMessageBox::warning(this, "Check Out", "Room " + QString::number(roomNum) + " is not booked.");
    }
}

void CheckOutInterface::clearFields()
{
    m_comboBox_room->setCurrentIndex(0);
}
