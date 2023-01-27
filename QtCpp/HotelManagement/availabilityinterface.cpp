#include "availabilityinterface.h"
#include <QVBoxLayout>
#include <QMessageBox>

AvailabilityInterface::AvailabilityInterface(Hotel *hotel, QWidget *parent) : QDialog(parent), m_hotel(hotel)
{
    setupUI();
    connect(m_pushButton_checkAvailability, &QPushButton::clicked, this, &AvailabilityInterface::checkAvailability);
}

void AvailabilityInterface::setupUI()
{
    setWindowTitle("Check Availability");
    setFixedSize(400, 400);
    setModal(true);

    m_comboBox_room->setFixedSize(200, 30);
    m_dateEdit_checkin->setFixedSize(200, 30);
    m_dateEdit_checkout->setFixedSize(200, 30);
    m_pushButton_checkAvailability->setFixedSize(200, 30);

    for(int i = 0; i < m_hotel->getMaxRooms(); i++)
    {
        m_comboBox_room->addItem(QString::number(i+1));
    }

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_comboBox_room);
    mainLayout->addWidget(m_dateEdit_checkin);
    mainLayout->addWidget(m_dateEdit_checkout);
    mainLayout->addWidget(m_pushButton_checkAvailability);
    setLayout(mainLayout);
}

void AvailabilityInterface::checkAvailability()
{
    // Get the dates
    QDate checkin = m_dateEdit_checkin->date();
    QDate checkout = m_dateEdit_checkout->date();

    // Get the room number
    int roomNum = m_comboBox_room->currentText().toInt();

    // Check if the room is available
    for(int i = 0; i < m_hotel->getBookings().size(); i++)
    {
        if(m_hotel->getBookings()[i]->getRoomNo() == roomNum)
        {
            if(checkin >= m_hotel->getBookings()[i]->getCheckIn() && checkin <= m_hotel->getBookings()[i]->getCheckOut())
            {
                QMessageBox::warning(this, "Check Availability", "Room " + QString::number(roomNum) + " is not available on " + checkin.toString("dd/MM/yyyy"));
                return;
            }
            else if(checkout >= m_hotel->getBookings()[i]->getCheckIn() && checkout <= m_hotel->getBookings()[i]->getCheckOut())
            {
                QMessageBox::warning(this, "Check Availability", "Room " + QString::number(roomNum) + " is not available on " + checkout.toString("dd/MM/yyyy"));
                return;
            }
        }
    }
    QMessageBox::information(this, "Check Availability", "Room " + QString::number(roomNum) + " is available from " + checkin.toString("dd/MM/yyyy") + " to " + checkout.toString("dd/MM/yyyy"));
}
