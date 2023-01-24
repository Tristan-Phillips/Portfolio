#ifndef BOOKING_H
#define BOOKING_H

#include <QString>

class Booking
{
public:
    Booking(int roomno, QString name, QString contactno, QString govid, QString address);
    ~Booking();

    int getRoomno() const;
    bool isRoomAvailable() const;

private:
    int roomno;
    QString name;
    QString contactno;
    QString govid;
    QString address;
};

#endif // BOOKING_H
