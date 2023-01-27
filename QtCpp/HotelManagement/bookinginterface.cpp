#include "bookinginterface.h"
#include <QVBoxLayout>
#include <QMessageBox>

BookingInterface::BookingInterface(Hotel *hotel, QWidget *parent)
{
    m_hotel = hotel;
    setupConnections();
    setupUI();
}

BookingInterface::~BookingInterface()
{
}

void BookingInterface::setupUI()
{
    // Set window title and size
    this->setWindowTitle("Booking Interface");
    this->setFixedSize(300, 300);

    // Add widgets to layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_comboBox_room);
    layout->addWidget(m_lineEdit_name);
    layout->addWidget(m_lineEdit_address);
    layout->addWidget(m_lineEdit_phone);
    layout->addWidget(m_lineEdit_email);
    layout->addWidget(m_dateEdit_checkin);
    layout->addWidget(m_dateEdit_checkout);
    layout->addWidget(m_pushButton_book);
    layout->addWidget(m_pushButton_cancel);

    // Input mask
    inputMask();

    // Set placeholder text
    m_lineEdit_name->setPlaceholderText("Name");
    m_lineEdit_address->setPlaceholderText("Address");
    m_lineEdit_phone->setPlaceholderText("Phone");
    m_lineEdit_email->setPlaceholderText("Email");

    // Fill the combo box with room numbers
    setComboBoxRoom();

    // Set layout
    setLayout(layout);
}

void BookingInterface::setComboBoxRoom()
{
    m_comboBox_room->clear();
    for(int i = 1; i <= m_hotel->getMaxRooms(); i++)
    {
        m_comboBox_room->addItem(QString::number(i));
    }
}

void BookingInterface::setupConnections()
{
    connect(m_pushButton_book, &QPushButton::clicked, this, &BookingInterface::bookRoom);
    connect(m_pushButton_cancel, &QPushButton::clicked, this, &BookingInterface::close);
}

void BookingInterface::bookRoom()
{
    if(!checkFields())
    {
        return;
    }
    // Get the room number
    int roomno = m_comboBox_room->currentText().toInt();

    // Get the name
    QString name = m_lineEdit_name->text();

    // Get the address
    QString address = m_lineEdit_address->text();

    // Get the phone
    QString phone = m_lineEdit_phone->text();

    // Get the email
    QString email = m_lineEdit_email->text();

    // Get the checkin date
    QDate checkin = m_dateEdit_checkin->date();

    // Get the checkout date
    QDate checkout = m_dateEdit_checkout->date();

    // Create a booking object
    Booking *booking = new Booking(roomno, name, address, phone, email, checkin, checkout);

    // Add the booking to the hotel
    m_hotel->addBooking(booking);

    // Clear the fields
    clearFields();
    setComboBoxRoom();
}

void BookingInterface::clearFields()
{
    m_comboBox_room->setCurrentIndex(0);
    m_lineEdit_name->clear();
    m_lineEdit_address->clear();
    m_lineEdit_phone->clear();
    m_lineEdit_email->clear();
    m_dateEdit_checkin->setDate(QDate::currentDate());
    m_dateEdit_checkout->setDate(QDate::currentDate());
}

bool BookingInterface::checkFields()
{
    if(m_lineEdit_name->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Name field is empty");
        return false;
    }else if(m_lineEdit_name->text().contains(QRegExp("[0-9]")))
    {
        QMessageBox::warning(this, "Error", "Name field contains numbers");
        return false;
    }
    if(m_lineEdit_address->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Address field is empty");
        return false;
    }
    if(m_lineEdit_phone->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Phone field is empty");
        return false;
    }else if(m_lineEdit_phone->text().contains(QRegExp("[a-zA-Z]")))
    {
        QMessageBox::warning(this, "Error", "Phone field contains letters");
        return false;
    }
    if(m_lineEdit_email->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Email field is empty");
        return false;
    }else if(!m_lineEdit_email->text().contains(QRegExp("[@]")))
    {
        QMessageBox::warning(this, "Error", "Email field is invalid");
        return false;
    }
    if(m_dateEdit_checkin->date() > m_dateEdit_checkout->date())
    {
        QMessageBox::warning(this, "Error", "Checkin date is greater than checkout date");
        return false;
    }
    return true;
}

void BookingInterface::inputMask()
{
    m_lineEdit_phone->setInputMask("0000000000");
}
