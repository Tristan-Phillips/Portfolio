#ifndef GUI_H
#define GUI_H

#include <QDialog>
#include <QMessageBox>
#include "server.h"
#include "model.h"

/*
    This class is the GUI for the application.
    It has a table view to display the data from the server.
    It has a button to start listening for data from a client.
*/

class QPushButton;
class QTableView;

class GUI : public QDialog
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    ~GUI();
    void setupUI();

private slots:
    void btnState();
    void startListening();
    void stopListening();
    void buttonRouter();
    void xmlReady();

private:
    Server server;
    Model *m_model;
    QPushButton *btnStart;
    QTableView *view;
    quint16 port = 6164;
};
#endif // GUI_H
