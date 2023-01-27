#ifndef CHECKOUTINTERFACE_H
#define CHECKOUTINTERFACE_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>

#include "hotel.h"

class CheckOutInterface : public QDialog
{
    Q_OBJECT
public:
    CheckOutInterface(Hotel *hotel, QWidget *parent = nullptr);
    void updateComboBoxRooms();
private:
    void setupUI();
    void checkOutRoom();
    void clearFields();
    // Widgets
    QComboBox *m_comboBox_room = new QComboBox;
    QPushButton *m_pushButton_checkOut = new QPushButton("Check Out");
    QPushButton *m_pushButton_cancel = new QPushButton("Cancel");
    // Hotel
    Hotel *m_hotel;
};

#endif // CHECKOUTINTERFACE_H
