#ifndef TRANSACTIONINTERFACE_H
#define TRANSACTIONINTERFACE_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>

#include "hotel.h"

class TransactionInterface : public QDialog
{
    Q_OBJECT
public:
    TransactionInterface(Hotel *hotel, QWidget *parent = nullptr);

public slots:
    void updateTransactions();

private:
    void setupUI();
    QTextEdit *m_textEdit_transactions = new QTextEdit;
    QPushButton *m_pushButton_close = new QPushButton("Close");
    // Hotel
    Hotel *m_hotel;
};

#endif // TRANSACTIONINTERFACE_H
