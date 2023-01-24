#include "booking.h"

Booking::Booking(int roomno, QString name, QString contactno, QString govid, QString address) : 
    roomno(roomno), name(name), contactno(contactno), govid(govid), address(address)
{}

Booking::~Booking()
{}

int Booking::getRoomno() const
{
    return roomno;
}
