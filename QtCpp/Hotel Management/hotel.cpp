#include "hotel.h"

Hotel *Hotel::instance = nullptr;

Hotel::Hotel(int totalRooms) : m_totalRooms(totalRooms)
{
    if (instance == nullptr)
    {
        instance = this;
    }
}

QList<Booking> *Hotel::getRooms() const
{
    return rooms;
}

bool Hotel::isRoomAvailable(int roomno) const
{
    for (int i = 0; i < rooms->size(); i++)
    {
        if (rooms->at(i).getRoomno() == roomno)
        {
            return false;
        }
    }
    return true;
}

void Hotel::checkIn(int roomno, QString name, QString contactno, QString govid, QString address)
{
    Booking *booking = new Booking(roomno, name, contactno, govid, address);
    rooms->append(*booking);
}

int Hotel::checkOut(int roomno)
{
    for (int i = 0; i < rooms->size(); i++)
    {
        if (rooms->at(i).getRoomno() == roomno)
        {
            rooms->removeAt(i);
            return 0;
        }
    }
    return -1;
}