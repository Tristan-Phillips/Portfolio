#include "gui.h"
#include "xmlreader.h"
#include "data.h"
#include "model.h"

#include <QPushButton>
#include <QTableView>
#include <QGridLayout>
#include <QLabel>
#include <QHeaderView>
#include <QIcon>

GUI::GUI(QWidget *parent)
    : QDialog(parent),
      server{new Server},
      m_model{Model::getInstance()},
      btnStart{new QPushButton{"Start Listening"}},
      view{new QTableView{this}}
{
    setupUI();
    btnStart->setObjectName("WAITING");
    m_model = Model::getInstance();
    view->setModel(m_model);

    connect(btnStart, &QPushButton::clicked, this, &GUI::buttonRouter);
    connect(&server, &Server::xmlReady, this, &GUI::xmlReady);
}

GUI::~GUI()
{}

void GUI::setupUI()
{
    setWindowIcon(QIcon(":/images/server_icon.ico"));
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    QGridLayout *layout{new QGridLayout{this}};
    QLabel *lstnPort{new QLabel{"Listening on port: "}};
    lstnPort->setText(lstnPort->text() += QString::number(port));

    view->resizeColumnsToContents();
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    layout->addWidget(btnStart, 0, 0);
    layout->addWidget(lstnPort, 0, 1);
    layout->addWidget(view, 1, 0, 1, 2);

    this->setMinimumWidth(800);

    btnState();

    this->setLayout(layout);
}

void GUI::xmlReady()
{
    m_model->clear();
    XMLReader *reader{new XMLReader{server.getData()}};
    for(int i = 0; i < reader->getDataList().size(); i++){
        m_model->addData(reader->getDataList().at(i));
    }
}

void GUI::btnState()
{
    if(server.isListening()){
        btnStart->setText("Stop Listening");
        view->setStyleSheet("border: 1px solid #19f500");
    }else{
        btnStart->setText("Start Listening");
        view->setStyleSheet("border: 1px solid #f50a00");
    }
}

void GUI::startListening()
{
    if(!server.listen(QHostAddress::LocalHost, port)){
        QMessageBox::critical(this, "ERROR", "Unable to start the server: " + server.errorString());
        return;
    }
    btnState();
}

void GUI::stopListening()
{
    server.close();
    btnState();
}

void GUI::buttonRouter()
{
    QString sender = QObject::sender()->objectName();
    if(sender.toUpper() == "WAITING"){
        QObject::sender()->setObjectName("RUNNING");
        startListening();
    }else if(sender.toUpper() == "RUNNING"){
        QObject::sender()->setObjectName("WAITING");
        stopListening();
    }else{
        QMessageBox::critical(this, "ERROR", "Incorrect sender trying to call the buttonRouter slot");
    }
}
