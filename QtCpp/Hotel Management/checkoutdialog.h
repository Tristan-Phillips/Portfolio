#ifndef CHECKOUTDIALOG_H
#define CHECKOUTDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>

class CheckOutDialog : public QDialog
{
    Q_OBJECT
public:
    CheckOutDialog();
    ~CheckOutDialog();
    void display();

private:
    void setupUI();

    // Widgets
    QComboBox *m_comboBox_room = new QComboBox;

    // Buttons
    QPushButton *m_btnCheckOut = new QPushButton("Check Out");
    QPushButton *m_btnCancel = new QPushButton("Cancel");
};

#endif // CHECKOUTDIALOG_H
