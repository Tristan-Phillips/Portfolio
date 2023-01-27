#ifndef HOTEL_H
#define HOTEL_H

#include "booking.h"

class Hotel
{
public:
    Hotel();
    ~Hotel();

    // Add a booking
    void addBooking(Booking *booking);
    // Remove a booking
    void removeBooking(Booking *booking);
    // Checkouts
    bool checkOutRoom(int roomNo);

    // Getters
    QList<Booking*> getBookings() const;
    int getMaxRooms() const;

private:
    QList<Booking*> m_bookings;
    // Constants
    const int m_maxRooms = 10;
};

#endif // HOTEL_H
