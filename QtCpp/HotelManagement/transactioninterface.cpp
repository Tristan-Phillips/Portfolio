#include "transactioninterface.h"
#include <QVBoxLayout>

TransactionInterface::TransactionInterface(Hotel *hotel, QWidget *parent)
    : QDialog(parent),
        m_hotel(hotel)
{
    setupUI();
    updateTransactions();
}

void TransactionInterface::setupUI()
{
    setWindowTitle("Transactions");
    setFixedSize(400, 400);
    setModal(true);

    m_textEdit_transactions->setReadOnly(true);

    m_pushButton_close->setFixedSize(100, 30);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_textEdit_transactions);
    mainLayout->addWidget(m_pushButton_close);
    setLayout(mainLayout);

    connect(m_pushButton_close, &QPushButton::clicked, this, &TransactionInterface::close);
}

void TransactionInterface::updateTransactions()
{
    m_textEdit_transactions->clear();
    m_textEdit_transactions->append("Transactions:");
    m_textEdit_transactions->append("-------------");
    for(int i = 0; i < m_hotel->getBookings().size() ; i++)
    {
        m_textEdit_transactions->append(m_hotel->getBookings()[i]->getTransaction());
    }
}