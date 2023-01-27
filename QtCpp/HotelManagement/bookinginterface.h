#ifndef BOOKINGINTERFACE_H
#define BOOKINGINTERFACE_H

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDateEdit>

#include "hotel.h"

class BookingInterface : public QDialog
{
    Q_OBJECT
public:
    BookingInterface(Hotel *hotel, QWidget *parent = nullptr);
    ~BookingInterface();

private:
    void setupUI();
    void setComboBoxRoom();
    void setupConnections();
    void bookRoom();
    void clearFields();
    bool checkFields();
    void inputMask();
    // Widgets
    QComboBox *m_comboBox_room = new QComboBox;
    QLineEdit *m_lineEdit_name = new QLineEdit;
    QLineEdit *m_lineEdit_address = new QLineEdit;
    QLineEdit *m_lineEdit_phone = new QLineEdit;
    QLineEdit *m_lineEdit_email = new QLineEdit;
    QDateEdit *m_dateEdit_checkin = new QDateEdit;
    QDateEdit *m_dateEdit_checkout = new QDateEdit;

    QPushButton *m_pushButton_book = new QPushButton("Book");
    QPushButton *m_pushButton_cancel = new QPushButton("Cancel");

    // Hotel
    Hotel *m_hotel;
};

#endif // BOOKINGINTERFACE_H
