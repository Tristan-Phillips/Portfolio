#ifndef HOTEL_H
#define HOTEL_H

#include <QString>
#include <QList>

#include "booking.h"

class Hotel
{
public:
    Hotel(int totalRooms);
    static Hotel *instance;
    QList<Booking> *getRooms() const;
    bool isRoomAvailable(int roomno) const;

private:
    void checkIn(int roomno, QString name, QString contactno, QString govid, QString address);
    int checkOut(int roomno);

    static Hotel *getInstance();

    // Room Data
    QList<Booking> *rooms = new QList<Booking>;
    int m_totalRooms;
};

#endif // HOTEL_H
