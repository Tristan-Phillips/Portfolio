#include "hotel.h"
#include <QMessageBox>

Hotel::Hotel()
{
}

Hotel::~Hotel()
{
}

void Hotel::addBooking(Booking *booking)
{
    for(int i = 0; i < m_bookings.size(); i++)
    {
        if(m_bookings[i]->getRoomNo() == booking->getRoomNo())
        {
            QMessageBox::warning(nullptr, "Error", "Room already booked!");
            return;
        }
    }
    QMessageBox::information(nullptr, "Success", "Room booked!");
    m_bookings.append(booking);
}

void Hotel::removeBooking(Booking *booking)
{
    for(int i = 0; i < m_bookings.size(); i++)
    {
        if(m_bookings[i]->getRoomNo() == booking->getRoomNo())
        {
            m_bookings.removeAt(i);
            return;
        }
    }
    QMessageBox::warning(nullptr, "Error", "Room not booked!");
}

bool Hotel::checkOutRoom(int roomNo)
{
    for(int i = 0; i < m_bookings.size(); i++)
    {
        if(m_bookings[i]->getRoomNo() == roomNo)
        {
            m_bookings.removeAt(i);
            return true;
        }
    }
    return false;
}

QList<Booking*> Hotel::getBookings() const
{
    return m_bookings;
}

int Hotel::getMaxRooms() const
{
    return m_maxRooms;
}
