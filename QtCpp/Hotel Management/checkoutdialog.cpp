#include "checkoutdialog.h"
#include <QVBoxLayout>

CheckOutDialog::CheckOutDialog()
{
    setupUI();
}

CheckOutDialog::~CheckOutDialog()
{
}

void CheckOutDialog::display()
{
    show();
}

void CheckOutDialog::setupUI()
{
    // Set the window title
    setWindowTitle("Check Out");

    // Set the window size
    setFixedSize(300, 100);

    // Set the layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    // Add the widgets to the layout
    mainLayout->addWidget(m_comboBox_room);
    mainLayout->addWidget(m_btnCheckOut);
    mainLayout->addWidget(m_btnCancel);
}
