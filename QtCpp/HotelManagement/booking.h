#ifndef BOOKING_H
#define BOOKING_H

#include <QString>
#include <QDate>

class Booking
{
public:
    Booking(int roomno, QString name, QString address, QString phone, QString email, QDate checkin, QDate checkout);
    ~Booking();

    // Getters
    int getRoomNo() const;
    QString getName() const;
    QString getAddress() const;
    QString getPhone() const;
    QString getEmail() const;
    QDate getCheckIn() const;
    QDate getCheckOut() const;
    QString getTransaction() const;

    // Setter for updating the record
    void updateRecord(int roomno, QString name, QString address, QString phone, QString email, QDate checkin, QDate checkout);

private:
    // Generate a transaction string
    QString generateTransaction();

    // Data members
    int m_roomno;
    QString m_name;
    QString m_address;
    QString m_phone;
    QString m_email;
    QDate m_checkin;
    QDate m_checkout;
    QString m_transaction;
};

#endif // BOOKING_H
