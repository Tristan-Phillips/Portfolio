//Local Includes
#include "mainclient.h"
#include "popupview.h"
#include "mainwidget.h"
#include "clienttcp.h"
#include "caretaker.h"

//External Includes
#include <QMenu>
#include <QMenuBar>
#include <QAction> 
#include <QToolBar>
#include <QLayout>
#include <QStatusBar>
#include <QMessageBox>
#include <QCloseEvent>
#include <QLabel>

MainClient::MainClient(QWidget *parent)
    : QMainWindow(parent),
    m_mainWidget{new MainWidget{this}},
    m_caretaker{new Caretaker}
{
    //Sets everything prior to the application being shown
        preSetup();
    //Central Widget - Adds the mainWidget to the mainWindow
        setCentralWidget(m_mainWidget);
}

MainClient::~MainClient()
{}

//Pre-Application setups
void MainClient::preSetup()
{
    this->setWindowIcon(QIcon(":/images/box_icon.ico"));
    slot_updateStatusBar(mc_defaultStatusText);
    setupActions();
    setupMenu();
    setupToolBar();
    setupObjectNames();
    setupConnections();
}

void MainClient::setupObjectNames()
{
    //Action and Help action names to utilize the same slot
    m_actAbout->setObjectName("about");
    m_actHelp->setObjectName("help");
}

void MainClient::setupActions()
{
    //Actions
    m_actExit = new QAction(QIcon(":/images/info.png"), tr("E&xit"), this);
    /*Status*/m_actExit->setStatusTip(tr(mc_exitTip));
    /*ToolTip*/m_actExit->setToolTip(tr(mc_exitTip));
    m_actBackup = new QAction(QIcon(":/images/backup.png"), tr("&Backup"), this);
    /*Status*/m_actBackup->setStatusTip(tr(mc_backupTip));
    /*ToolTip*/m_actBackup->setToolTip(tr(mc_backupTip));
    m_actRestore = new QAction(QIcon(":/images/restore.png"), tr("&Restore"), this);
    /*Status*/m_actRestore->setStatusTip(tr(mc_restoreTip));
    /*ToolTip*/m_actRestore->setToolTip(tr(mc_restoreTip));
    m_actPostXML = new QAction(QIcon(":/images/xml.png"), tr("&Post XML"), this);
    /*Status*/m_actPostXML->setStatusTip(tr(mc_postXMLTip));
    /*ToolTip*/m_actPostXML->setToolTip(tr(mc_postXMLTip));
    m_actAbout = new QAction(QIcon(":/images/info.png"), tr("&About"), this);
    /*Status*/m_actAbout->setStatusTip(tr(mc_aboutTip));
    /*ToolTip*/m_actAbout->setToolTip(tr(mc_aboutTip));
    m_actHelp = new QAction(QIcon(":/images/help.png"), tr("&Help"), this);
    /*Status*/m_actHelp->setStatusTip(tr(mc_helpTip));
    /*ToolTip*/m_actHelp->setToolTip(tr(mc_helpTip));
}

void MainClient::setupMenu()
{
    m_mnuFile = menuBar()->addMenu(tr("&File"));
    /*Act*/m_mnuFile->addAction(m_actExit);

    m_mnuBackup = menuBar()->addMenu(tr("&Backup"));
    /*Act*/m_mnuBackup->addAction(m_actBackup);
    /*Act*/m_mnuBackup->addAction(m_actRestore);

    m_mnuPost = menuBar()->addMenu(tr("&Post"));
    /*Act*/m_mnuPost->addAction(m_actPostXML);

    m_mnuHelp = menuBar()->addMenu(tr("&Help"));
    /*Act*/m_mnuHelp->addAction(m_actAbout);
    /*Act*/m_mnuHelp->addAction(m_actHelp);
}

void MainClient::setupToolBar()
{
    m_tlbMain = addToolBar(tr("&Main"));
    m_tlbMain->layout()->setSpacing(mc_tooblarSpacing);
    //Actions to ToolBar
        m_tlbMain->addAction(m_actBackup);
        m_tlbMain->addAction(m_actRestore);
        m_tlbMain->addAction(m_actPostXML);
}

void MainClient::setupConnections()
{
    //Connections
        connect(m_actExit, &QAction::triggered, this, &QMainWindow::close);
        connect(m_actAbout, &QAction::triggered, this, &MainClient::slot_popupView);
        connect(m_actHelp, &QAction::triggered, this, &MainClient::slot_popupView);
    //Connect to widget slots
        connect(m_actPostXML, &QAction::triggered, m_mainWidget, &MainWidget::slot_postXML);
        connect(m_actBackup, &QAction::triggered, this, &MainClient::addMomento);
        connect(m_actRestore, &QAction::triggered, this, &MainClient::restoreMomento);
        connect(m_mainWidget, &MainWidget::signal_updateStatusBar, this, &MainClient::slot_updateStatusBar);
    //Momento Connect
        connect(m_mainWidget, &MainWidget::signal_addMomento, this, &MainClient::addMomento);
        connect(m_mainWidget, &MainWidget::signal_restoreMomento, this, &MainClient::restoreMomento);
}

//End Pre-Application setups

//Slot implementations
void MainClient::slot_updateStatusBar(QString text)
{
    //Used to conveniently send text that updates the status bar
        statusBar()->showMessage(text);
}

void MainClient::slot_popupView()
{
    /* PopupView is a class that is used to create a popup window 
     * that can be used to display information to the user */
        PopupView *pv = new PopupView;
        pv->setAttribute(Qt::WA_DeleteOnClose);
        QString objName = sender()->objectName();
        if(objName == "about"){
            pv->setWindowIcon(QIcon(":/images/info.png"));
            pv->setWindowTitle(tr("About"));
            pv->display(":/html/about.html");
        }else if(objName == "help"){
            pv->setWindowIcon(QIcon(":/images/help.png"));
            pv->setWindowTitle(tr("Help"));
            pv->display(":/html/help.html");
        }else{
            delete pv;
            QMessageBox::critical(this, tr("Error"), tr("Unknown object name"));
        }
}

void MainClient::addMomento()
{
    m_caretaker->setMomento(m_mainWidget->createMomento());

}

void MainClient::restoreMomento()
{
    m_mainWidget->restoreMomento(m_caretaker->getMomento());
}

void MainClient::closeEvent(QCloseEvent *event)
{
    //Assert that the user intends to close the application
        QMessageBox::StandardButton response = QMessageBox::question(this, "Exit?",
                                                                    tr("Are you sure?\n"),
                                                                    QMessageBox::No | QMessageBox::Yes,
                                                                    QMessageBox::Yes);
        if (response == QMessageBox::Yes){
            event->accept();
        }
        else{
            event->ignore();
        }
}

//End Slot implementations
