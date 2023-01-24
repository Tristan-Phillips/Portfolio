#include "bookroomdialog.h"
#include <QHBoxLayout>
#include <QDebug>

BookRoomDialog::BookRoomDialog(Hotel *hotel, QWidget *parent) :
    m_hotel(hotel),
    QDialog(parent)
{
    qDebug() << m_hotel->getRooms()->size();
    setupUI();
}

BookRoomDialog::~BookRoomDialog()
{}

void BookRoomDialog::on_btnCancel_clicked()
{
    close();
}

void BookRoomDialog::on_btnBook_clicked()
{

}

void BookRoomDialog::setupUI()
{
    // Set the title of the dialog
    setWindowTitle("Book Room");

    // Set the size of the dialog
    setFixedSize(400, 300);

    // Set the layout of the dialog
    setLayout(mainLayout);

    // Add the widgets to the layout
    mainLayout->addWidget(m_comboBox_room);
    fillComboBox();
    mainLayout->addWidget(m_lineEdit_name);
    mainLayout->addWidget(m_lineEdit_contactNo);
    mainLayout->addWidget(m_lineEdit_govtId);
    mainLayout->addWidget(m_lineEdit_address);

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget(m_btnBook);
    hbox->addWidget(m_btnCancel);

    mainLayout->addLayout(hbox);

    // Set the text of the widgets
    m_comboBox_room->setPlaceholderText("Room No.");
    m_comboBox_room->addItem("Plese select a room");

    m_lineEdit_name->setPlaceholderText("Name");
    m_lineEdit_contactNo->setPlaceholderText("Contact No.");
    m_lineEdit_govtId->setPlaceholderText("Govt. ID");
    m_lineEdit_address->setPlaceholderText("Address");

    // Set the size of the widgets
    m_btnBook->setFixedSize(100, 30);
    m_btnCancel->setFixedSize(100, 30);

    // Set the alignment of the widgets
    m_lineEdit_name->setAlignment(Qt::AlignCenter);
    m_lineEdit_contactNo->setAlignment(Qt::AlignCenter);
    m_lineEdit_govtId->setAlignment(Qt::AlignCenter);
    m_lineEdit_address->setAlignment(Qt::AlignCenter);
}

void BookRoomDialog::fillComboBox()
{
    for(int i = 0; i < m_hotel->getRooms()->size(); i++)
    {
        m_comboBox_room->addItem("Room: " + QString::number(m_hotel->getRooms()->at(i).getRoomno()));
    }
}

void BookRoomDialog::display()
{
    show();
}
