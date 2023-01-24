#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "bookroomdialog.h"
#include "checkoutdialog.h"
#include "hotel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private slots:
    void on_pushButton_roomBooking_clicked();
    void on_pushButton_checkOut_clicked();

private:
    void setupUI();
    void styleQPushButtons();
    void setupConnections();

    // Widgets
    QPushButton *m_pushButton_roomBooking = new QPushButton("Room Booking");
    QPushButton *m_pushButton_checkOut = new QPushButton("Check Out");
    QPushButton *m_pushButton_checkAvailability = new QPushButton("Check Availability");
    QPushButton *m_pushButton_transactions = new QPushButton("Transactions");

    // Dialogs
    Hotel *m_hotel;
    BookRoomDialog *m_bookRoomDialog;
    CheckOutDialog *m_checkOutDialog = new CheckOutDialog;
};
#endif // MAINWINDOW_H
