#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setMinimumSize(800, 500);
    this->setWindowTitle("Desert Hotel");
    this->setWindowIcon(QIcon(":/src/img/deserthotel.png"));
    m_hotel = new Hotel(10);
    m_bookRoomDialog = new BookRoomDialog(m_hotel);

    setupConnections();
    styleQPushButtons();
    setupUI();
}

MainWindow::~MainWindow()
{
    m_pushButton_checkAvailability->deleteLater();
    m_pushButton_checkOut->deleteLater();
    m_pushButton_roomBooking->deleteLater();
    m_pushButton_transactions->deleteLater();
}

void MainWindow::on_pushButton_roomBooking_clicked()
{
    m_bookRoomDialog->display();
}

void MainWindow::on_pushButton_checkOut_clicked()
{
    m_checkOutDialog->display();
}

void MainWindow::setupUI()
{
    QHBoxLayout *hbox = new QHBoxLayout;
    QVBoxLayout *vbox = new QVBoxLayout;

    // VBox selection buttons
    vbox->addWidget(m_pushButton_roomBooking);
    vbox->addWidget(m_pushButton_checkOut);
    vbox->addWidget(m_pushButton_checkAvailability);
    vbox->addWidget(m_pushButton_transactions);

    // HBox selection buttons and stacked widget
    hbox->addLayout(vbox);

    // Label for image
    QLabel *label = new QLabel;
    label->setPixmap(QPixmap(":/src/img/deserthotel.png"));
        label->setScaledContents(true);
        label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    hbox->addWidget(label);

    // Set central widget
    QWidget *widget = new QWidget;
    widget->setLayout(hbox);
    setCentralWidget(widget);
}

void MainWindow::styleQPushButtons()
{
    m_pushButton_checkAvailability->setMaximumWidth(200);
    m_pushButton_checkAvailability->setMinimumHeight(80);
    m_pushButton_checkAvailability->setStyleSheet("QPushButton {"
                                                 "background-color: #4CAF50;"
                                                 "color: white;"
                                                 "border: none;"
                                                 "border-radius: 5px;"
                                                 "padding: 10px;"
                                                 "font-size: 16px;"
                                                 "}"
                                                 "QPushButton:pressed {"
                                                 "background-color: #3e8e41;"
                                                 "}"
                                                 "QPushButton:hover {"
                                                 "background-color: #3e8e41;"
                                                 "}"); // Green

    m_pushButton_checkOut->setMaximumWidth(200);
    m_pushButton_checkOut->setMinimumHeight(80);
    m_pushButton_checkOut->setStyleSheet("QPushButton {"
                                            "background-color: #f44336;"
                                            "color: white;"
                                            "border: none;"
                                            "border-radius: 5px;"
                                            "padding: 10px;"
                                            "font-size: 16px;"
                                            "}"
                                            "QPushButton:pressed {"
                                            "background-color: #da190b;"
                                            "}"
                                            "QPushButton:hover {"
                                            "background-color: #da190b;"
                                            "}"); // Red

    m_pushButton_roomBooking->setMaximumWidth(200);
    m_pushButton_roomBooking->setMinimumHeight(80);
    m_pushButton_roomBooking->setStyleSheet("QPushButton {"
                                            "background-color: #2196F3;"
                                            "color: white;"
                                            "border: none;"
                                            "border-radius: 5px;"
                                            "padding: 10px;"
                                            "font-size: 16px;"
                                            "}"
                                            "QPushButton:pressed {"
                                            "background-color: #0b7dda;"
                                            "}"
                                            "QPushButton:hover {"
                                            "background-color: #0b7dda;"
                                            "}"); // Blue

    m_pushButton_transactions->setMaximumWidth(200);
    m_pushButton_transactions->setMinimumHeight(80);
    m_pushButton_transactions->setStyleSheet("QPushButton {"
                                            "background-color: #ff9800;"
                                            "color: white;"
                                            "border: none;"
                                            "border-radius: 5px;"
                                            "padding: 10px;"
                                            "font-size: 16px;"
                                            "}"
                                            "QPushButton:pressed {"
                                            "background-color: #e68a00;"
                                            "}"
                                            "QPushButton:hover {"
                                            "background-color: #e68a00;"
                                             "}"); // Orange
}

void MainWindow::setupConnections()
{
    connect(m_pushButton_roomBooking, &QPushButton::clicked, this, &MainWindow::on_pushButton_roomBooking_clicked);
    connect(m_pushButton_checkOut, &QPushButton::clicked, this, &MainWindow::on_pushButton_checkOut_clicked);
}

