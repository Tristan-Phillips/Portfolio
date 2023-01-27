#ifndef AVAILABILITYINTERFACE_H
#define AVAILABILITYINTERFACE_H

#include <QDialog>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>

#include "hotel.h"

class AvailabilityInterface : public QDialog
{
    Q_OBJECT
public:
    AvailabilityInterface(Hotel *hotel, QWidget *parent = nullptr);

private:
    void setupUI();
    void checkAvailability();
    QComboBox *m_comboBox_room = new QComboBox;
    QDateEdit *m_dateEdit_checkin = new QDateEdit;
    QDateEdit *m_dateEdit_checkout = new QDateEdit;
    QPushButton *m_pushButton_checkAvailability = new QPushButton("Check Availability");

    // Hotel
    Hotel *m_hotel;
};

#endif // AVAILABILITYINTERFACE_H
