#ifndef BOOKROOMDIALOG_H
#define BOOKROOMDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "hotel.h"

class BookRoomDialog : public QDialog
{
    Q_OBJECT
public:
    explicit BookRoomDialog(Hotel *hotel ,QWidget *parent = nullptr);
    ~BookRoomDialog();
    void readData();
    void display();

private slots:
    void on_btnCancel_clicked();
    void on_btnBook_clicked();

private:
    void setupUI();
    void fillComboBox();

    // Widgets
    QComboBox *m_comboBox_room = new QComboBox;
    QLineEdit *m_lineEdit_name = new QLineEdit;
    QLineEdit *m_lineEdit_contactNo = new QLineEdit;
    QLineEdit *m_lineEdit_govtId = new QLineEdit;
    QLineEdit *m_lineEdit_address = new QLineEdit;

    // Buttons
    QPushButton *m_btnBook = new QPushButton("Book");
    QPushButton *m_btnCancel = new QPushButton("Cancel");

    // layout
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Object
    Hotel *m_hotel;
};

#endif // BOOKROOMDIALOG_H
