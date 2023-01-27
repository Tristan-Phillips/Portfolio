#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "hotel.h"
#include "bookinginterface.h"
#include "transactioninterface.h"
#include "checkoutinterface.h"
#include "availabilityinterface.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_roomBooking_clicked();
    void on_pushButton_checkOut_clicked();
    void on_pushButton_checkAvailability_clicked();
    void on_pushButton_transactions_clicked();

private:
    void setupUI();
    void styleQPushButtons();
    void setupConnections();

    // Widgets
    QPushButton *m_pushButton_roomBooking = new QPushButton("Room Booking");
    QPushButton *m_pushButton_checkOut = new QPushButton("Check Out");
    QPushButton *m_pushButton_checkAvailability = new QPushButton("Check Availability");
    QPushButton *m_pushButton_transactions = new QPushButton("Transactions");

    // Objects
    Hotel *m_hotel;
    BookingInterface *m_bookingInterface;
    TransactionInterface *m_transactionInterface;
    CheckOutInterface *m_checkOutInterface;
    AvailabilityInterface *m_availabilityInterface;
};
#endif // MAINWINDOW_H
