#include "booking.h"

Booking::Booking(int roomno, QString name, QString address, QString phone, QString email, QDate checkin, QDate checkout)
: m_roomno(roomno), m_name(name), m_address(address), m_phone(phone), m_email(email), m_checkin(checkin), m_checkout(checkout)
{
    m_transaction = generateTransaction();
}

Booking::~Booking()
{
}

int Booking::getRoomNo() const
{
    return m_roomno;
}

QString Booking::getName() const
{
    return m_name;
}

QString Booking::getAddress() const
{
    return m_address;
}

QString Booking::getPhone() const
{
    return m_phone;
}

QString Booking::getEmail() const
{
    return m_email;
}

QDate Booking::getCheckIn() const
{
    return m_checkin;
}

QDate Booking::getCheckOut() const
{
    return m_checkout;
}

QString Booking::getTransaction() const
{
    return m_transaction;
}

QString Booking::generateTransaction()
{
    return QString::number(m_roomno) + m_name + m_address + m_phone + m_email + m_checkin.toString() + m_checkout.toString();
}
