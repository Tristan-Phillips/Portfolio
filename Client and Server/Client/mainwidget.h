#ifndef MAINWIDGET_H
#define MAINWIDGET_H

//Local Includes
#include "serialcode.h"

//Includes
#include <QWidget>
#include <QFuture>

//Forward Declerations
class QSpinBox;
class QPushButton;
class QListWidget;
class QTextEdit;
class ContainerList;
class PalletList;
class Momento;
class SerialCode;

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    //Control Momento
        Momento *createMomento();
        void restoreMomento(Momento *momento);

signals:
    //Signal is used to display any sent text in the status bar
        void signal_updateStatusBar(QString text);
    //Signal is used to send XML returned to server
        void signal_sendXML(QString xml);
        void signal_addMomento();
        void signal_restoreMomento();

public slots:
    //Slot is used to generate xml to be sent to server
        void slot_postXML();
    //Slot is used to append the XML to the text box
        void slot_appendXML(QString xml);
    //Slot is used to send XML to server
        void slot_sendXML(QString xml);

private slots:
    //Monitor GUI change requirements
        void slot_updateGUI();
    //Functionality for the buttons
        void slot_appendContainer();
        void slot_moveToPallet();
        void slot_clearInput();

private:
    //Pre setups
    void preSetup();
        void setupObjectNames();
        void setTips();
        void setGuiThread();
        void setConstraints();
        void setTabOrder();
        void setConnections();
        QWidget *getWidgetContainer();
        QWidget *getWidgetPost();

    //Custom Class Objects
        ContainerList *m_containerList;
        PalletList *m_palletList;
        //Momento *m_momento;

    //Member Variables
        /*Box*/QSpinBox *m_boxBreadth, *m_boxLength, *m_boxHeight, *m_boxWeight;
        /*Cylinder*/QSpinBox *m_cylinderDiameater, *m_cylinderHeight, *m_cylinderWeight;
        QPushButton *m_btnAddBox, *m_btnAddCylinder;
        QListWidget *m_displayUnallocated;
        QSpinBox *m_palletNumber;
        QPushButton *m_btnMoveToPallet, *m_btnBackupRestore, *m_btnRollbackRestore;
        QPushButton *m_btnPostXML;
        QTextEdit *m_displayPalletXML;

    //Control serial code
        SerialCode m_serialCode;

    //Loop stays true untill the application is stopped or closed
        bool m_loopThread;

    //Constraints - to help minimize 'magic numbers'
        const char *mc_boxBreadthTip = "Enter the breadth of the box";
        const char *mc_boxLengthTip = "Enter the length of the box";
        const char *mc_boxHeightTip = "Enter the height of the box";
        const char *mc_boxWeightTip = "Enter the weight of the box";
        const char *mc_cylinderDiameaterTip = "Enter the diameter of the cylinder";
        const char *mc_cylinderHeightTip = "Enter the height of the cylinder";
        const char *mc_cylinderWeightTip = "Enter the weight of the cylinder";
        const char *mc_btnAddBoxTip = "Add Box";
        const char *mc_btnAddCylinderTip = "Add Cylinder";
        const char *mc_displayUnallocatedTip = "Unallocated list of containers";
        const char *mc_palletNumberTip = "Enter the number of the desired pallet";
        const char *mc_btnMoveToPalletTip = "Move to Pallet";
        const char *mc_btnBackupRestoreTip = "Backup";
        const char *mc_btnRollbackRestoreTip = "Rollback";
        const char *mc_btnPostXMLTip = "Post XML to server";
        const char *mc_displayPalletXMLTip = "Pallet XML";
    //Constraints for spinBox Inlputs
        const int mc_boxBreadthMin = 0;
        const int mc_boxBreadthMax = 1000;
        const int mc_boxLengthMin = 0;
        const int mc_boxLengthMax = 1000;
        const int mc_boxHeightMin = 0;
        const int mc_boxHeightMax = 1000;
        const int mc_boxWeightMin = 0;
        const int mc_boxWeightMax = 1000;
        const int mc_cylinderDiameaterMin = 0;
        const int mc_cylinderDiameaterMax = 1000;
        const int mc_cylinderHeightMin = 0;
        const int mc_cylinderHeightMax = 1000;
        const int mc_cylinderWeightMin = 0;
        const int mc_cylinderWeightMax = 1000;
};
#endif // MAINWIDGET_H
