#ifndef MAINCLIENT_H
#define MAINCLIENT_H

//Includes
#include <QMainWindow>

//Forward Declerations
class QAction;
class QMenu;
class QToolBar;
class QTabWidget;
class MainWidget;
class Caretaker;

class MainClient : public QMainWindow
{
    Q_OBJECT

public:
    MainClient(QWidget *parent = nullptr);
    ~MainClient();
    //Override close event
        void closeEvent(QCloseEvent *event);

public slots:
    //Slot is used to display any sent text in the status bar
        void slot_updateStatusBar(QString text);
    //Slot is used to display a popup window for about or help specifically in this case
        void slot_popupView();

private slots:
        void addMomento();
        void restoreMomento();

private:
    /*Custom class objects*/
        MainWidget *m_mainWidget;
        Caretaker *m_caretaker;
    /*Pre-Application setups
    for Actions + Menu + Toolbar + object Names*/
        void preSetup();
            void setupObjectNames();
            void setupActions();
            void setupMenu(); 
            void setupToolBar();
            void setupConnections();
    /*End Pre-Application setups*/
    //Pre-Application Member Variables
        //Actions
            QAction *m_actExit;
            QAction *m_actBackup;
            QAction *m_actRestore;
            QAction *m_actPostXML;
            QAction *m_actAbout;
            QAction *m_actHelp;
        //Menu
            QMenu *m_mnuFile;
            QMenu *m_mnuBackup;
            QMenu *m_mnuPost;
            QMenu *m_mnuHelp;
        //Toolbar
            QToolBar *m_tlbMain;

    //Constraints - to help minimize 'magic numbers'
        int mc_tooblarSpacing = 20;
        const char *mc_exitTip = "Exit the application";
        const char *mc_backupTip = "Backup the application";
        const char *mc_restoreTip = "Restore the application";
        const char *mc_postXMLTip = "Post XML to the server";
        const char *mc_aboutTip = "Show the application's About box";
        const char *mc_helpTip = "Show the application's Help box";
        QString mc_defaultStatusText = "Ready";
};
#endif // MAINCLIENT_H
