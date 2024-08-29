
//Local Includes
#include "mainwidget.h"
#include "containerlist.h"
#include "palletlist.h"
#include "containerfactory.h"
#include "writexml.h"
#include "momento.h"
#include "clienttcp.h"
#include "serialcode.h"
#include "validator.h"

//External Includes
#include <QSpinBox>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTextEdit>
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QTabWidget>
#include <QThread>
#include <QMessageBox>
#include <QTimer>

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent},
    m_containerList{new ContainerList},
    m_palletList{new PalletList},
    m_boxBreadth{new QSpinBox{this}},
    m_boxLength{new QSpinBox{this}},
    m_boxHeight{new QSpinBox{this}},
    m_boxWeight{new QSpinBox{this}},
    m_cylinderDiameater{new QSpinBox{this}},
    m_cylinderHeight{new QSpinBox{this}},
    m_cylinderWeight{new QSpinBox{this}},
    m_btnAddBox{new QPushButton{tr("Add Box"), this}},
    m_btnAddCylinder{new QPushButton{tr("Add Cylinder"), this}},
    m_displayUnallocated{new QListWidget{this}},
    m_palletNumber{new QSpinBox{this}},
    m_btnMoveToPallet{new QPushButton{tr("Move to Pallet"), this}},
    m_btnBackupRestore{new QPushButton{tr("Backup"), this}},
    m_btnRollbackRestore{new QPushButton{tr("Rollback"), this}},
    m_btnPostXML{new QPushButton{tr("Post XML"), this}},
    m_displayPalletXML{new QTextEdit{this}},
    m_loopThread{true}
{
    //Sets up the application
    preSetup();
}

MainWidget::~MainWidget()
{
    m_loopThread = false;
    delete m_containerList;
    delete m_palletList;
    delete m_boxBreadth;
    delete m_boxLength;
    delete m_boxHeight;
    delete m_boxWeight;
    delete m_cylinderDiameater;
    delete m_cylinderHeight;
    delete m_cylinderWeight;
    delete m_btnAddBox;
    delete m_btnAddCylinder;
    delete m_displayUnallocated;
    delete m_palletNumber;
    delete m_btnMoveToPallet;
    delete m_btnBackupRestore;
    delete m_btnRollbackRestore;
    delete m_btnPostXML;
    delete m_displayPalletXML;
}

Momento *MainWidget::createMomento()
{
    Momento *newMomento = new Momento;
    newMomento->setState(m_containerList, m_palletList);
    return newMomento;
}

void MainWidget::restoreMomento(Momento *momento)
{
    if(momento->isNull()){
        QMessageBox::warning(this, "Rollback", "No backup to rollback to");
        emit signal_updateStatusBar(tr("No backup to rollback"));
    }else if(QMessageBox::Yes == QMessageBox::question(this, "Rollback", "Are you sure you want to rollback to the last backup?")){
        m_displayUnallocated->clear();
        m_containerList->clear();
        m_palletList->clear();
        m_displayPalletXML->clear();

        m_containerList->setContainerList(momento->getContainerList());
        m_palletList->setPalletList(momento->getPalletList());

        for(int i = 0; i < m_containerList->getSize(); i++){
            m_displayUnallocated->addItem(m_containerList->getContainer(i)->getContainerCode());
        }
        //Set the serial code to the last serial code in the container list
            m_serialCode.setSerialCode(m_containerList->getContainer(m_containerList->getSize()-1)->getSerialCode()+1);
    }
}

/*Pre application setups*/
void MainWidget::preSetup()
{
    setupObjectNames();
    setTips();
    //Two seperate widgets are created for the tab widget
        QWidget *widgetContainer = getWidgetContainer();
        QWidget *widgetPost = getWidgetPost();

    //Adds the two seperate widgets to the tab widget
        QTabWidget *tabWidget = new QTabWidget{this};
        tabWidget->addTab(widgetContainer, tr("Container"));
        tabWidget->addTab(widgetPost, tr("Post"));

    //Final Layout
        QGridLayout *layout = new QGridLayout{this};
        layout->addWidget(tabWidget, 0, 0);

    //Removes the margins auto created for a widget by Qt
        layout->setContentsMargins(0, 0, 0, 0);
        setLayout(layout);

    //Constraints
        setConstraints();

    //Tab Order
        setTabOrder();

    //Connections
        setConnections();

    //Starts the thread
        setGuiThread();
}

void MainWidget::setupObjectNames()
{
    /* Used to allow for the same slot connection
     * By performing the relevant fucntion
     * based on the object name*/

        m_btnAddBox->setObjectName("BoxButton");
        m_btnAddCylinder->setObjectName("CylinderButton");
}

void MainWidget::setTips()
{
    //Box
        /*Breadth*/m_boxBreadth->setToolTip(tr(mc_boxBreadthTip));
        m_boxBreadth->setStatusTip(tr(mc_boxBreadthTip));
        /*Length*/m_boxLength->setToolTip(tr(mc_boxLengthTip));
        m_boxLength->setStatusTip(tr(mc_boxLengthTip));
        /*Height*/m_boxHeight->setToolTip(tr(mc_boxHeightTip));
        m_boxHeight->setStatusTip(tr(mc_boxHeightTip));
        /*Weight*/m_boxWeight->setToolTip(tr(mc_boxWeightTip));
        m_boxWeight->setStatusTip(tr(mc_boxWeightTip));

    //Cylinder
        /*Diameater*/m_cylinderDiameater->setToolTip(tr(mc_cylinderDiameaterTip));
        m_cylinderDiameater->setStatusTip(tr(mc_cylinderDiameaterTip));
        /*Height*/m_cylinderHeight->setToolTip(tr(mc_cylinderHeightTip));
        m_cylinderHeight->setStatusTip(tr(mc_cylinderHeightTip));
        /*Weight*/m_cylinderWeight->setToolTip(tr(mc_cylinderWeightTip));
        m_cylinderWeight->setStatusTip(tr(mc_cylinderWeightTip));

    //Container Button
        /*Box*/m_btnAddBox->setToolTip(tr(mc_btnAddBoxTip));
        m_btnAddBox->setStatusTip(tr(mc_btnAddBoxTip));
        /*Cylinder*/m_btnAddCylinder->setToolTip(tr(mc_btnAddCylinderTip));
        m_btnAddCylinder->setStatusTip(tr(mc_btnAddCylinderTip));

    //Pallet
        m_displayUnallocated->setToolTip(tr(mc_displayUnallocatedTip));
        m_displayUnallocated->setStatusTip(tr(mc_displayUnallocatedTip));
        m_palletNumber->setToolTip(tr(mc_palletNumberTip));
        m_palletNumber->setStatusTip(tr(mc_palletNumberTip));
        m_btnMoveToPallet->setToolTip(tr(mc_btnMoveToPalletTip));
        m_btnMoveToPallet->setStatusTip(tr(mc_btnMoveToPalletTip));

    //Backup and Rollback
        m_btnBackupRestore->setToolTip(tr(mc_btnBackupRestoreTip));
        m_btnBackupRestore->setStatusTip(tr(mc_btnBackupRestoreTip));
        m_btnRollbackRestore->setToolTip(tr(mc_btnRollbackRestoreTip));
        m_btnRollbackRestore->setStatusTip(tr(mc_btnRollbackRestoreTip));

    //Post XML
        m_btnPostXML->setToolTip(tr(mc_btnPostXMLTip));
        m_btnPostXML->setStatusTip(tr(mc_btnPostXMLTip));
        m_displayPalletXML->setToolTip(tr(mc_displayPalletXMLTip));
        m_displayPalletXML->setStatusTip(tr(mc_displayPalletXMLTip));
}

void MainWidget::setGuiThread()
{
    /* The thread is used to update the GUI
     * continuously without the need for a timer
     */

    QThread *thread = new QThread;
    connect(thread, &QThread::started, [&](){slot_updateGUI();}); //Warning idk why?
    connect(thread, &QThread::finished, thread, &QThread::quit);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    thread->start();
}

void MainWidget::setConstraints()
{
    //Box
        /*Breadth*/m_boxBreadth->setMaximum(mc_boxBreadthMax);
        m_boxBreadth->setMinimum(mc_boxBreadthMin);
        /*Length*/m_boxLength->setMaximum(mc_boxLengthMax);
        m_boxLength->setMinimum(mc_boxLengthMin);
        /*Height*/m_boxHeight->setMaximum(mc_boxHeightMax);
        m_boxHeight->setMinimum(mc_boxHeightMin);
        /*Weight*/m_boxWeight->setMaximum(mc_boxWeightMax);
        m_boxWeight->setMinimum(mc_boxWeightMin);

    //Cylinder
        /*Diameater*/m_cylinderDiameater->setMaximum(mc_cylinderDiameaterMax);
        m_cylinderDiameater->setMinimum(mc_cylinderDiameaterMin);
        /*Height*/m_cylinderHeight->setMaximum(mc_cylinderHeightMax);
        m_cylinderHeight->setMinimum(mc_cylinderHeightMin);
        /*Weight*/m_cylinderWeight->setMaximum(mc_cylinderWeightMax);
        m_cylinderWeight->setMinimum(mc_cylinderWeightMin);
}

void MainWidget::setTabOrder()
{
    //Box Tabs
        QWidget::setTabOrder(m_boxBreadth, m_boxLength);
        QWidget::setTabOrder(m_boxLength, m_boxHeight);
        QWidget::setTabOrder(m_boxHeight, m_boxWeight);
    //Add Box Button
        QWidget::setTabOrder(m_boxWeight, m_btnAddBox);
    //Cylinder Tabs
        QWidget::setTabOrder(m_btnAddBox, m_cylinderDiameater);
        QWidget::setTabOrder(m_cylinderDiameater, m_cylinderHeight);
        QWidget::setTabOrder(m_cylinderHeight, m_cylinderWeight);
    //Add Cylinder Button
        QWidget::setTabOrder(m_cylinderWeight, m_btnAddCylinder);
    //Pallet Tabs
        QWidget::setTabOrder(m_btnAddCylinder, m_palletNumber);
    //Move to Pallet Button
        QWidget::setTabOrder(m_palletNumber, m_btnMoveToPallet);
    //Backup and Rollback Tab
        QWidget::setTabOrder(m_btnMoveToPallet, m_btnBackupRestore);
}

void MainWidget::setConnections()
{
    //Button Connections
        connect(m_btnAddBox, &QPushButton::clicked, this, &MainWidget::slot_appendContainer);
        connect(m_btnAddCylinder, &QPushButton::clicked, this, &MainWidget::slot_appendContainer);
    //Clear Input
        connect(m_btnAddBox, &QPushButton::clicked, this, &MainWidget::slot_clearInput);
        connect(m_btnAddCylinder, &QPushButton::clicked, this, &MainWidget::slot_clearInput);
    //Move to Pallet
        connect(m_btnMoveToPallet, &QPushButton::clicked, this, &MainWidget::slot_moveToPallet);
    //Backup
        //connect(m_btnBackupRestore, &QPushButton::clicked, this, &MainWidget::slot_createBackup);
        connect(m_btnBackupRestore, &QPushButton::clicked, this, &MainWidget::signal_addMomento);
        connect(m_btnRollbackRestore, &QPushButton::clicked, this, &MainWidget::signal_restoreMomento);
    //Post XML
        connect(m_btnPostXML, &QPushButton::clicked, this, &MainWidget::slot_postXML);
    //Send XML
        connect(this, &MainWidget::signal_sendXML, this, &MainWidget::slot_sendXML);
}

QWidget *MainWidget::getWidgetContainer()
{
    /* Creates the widget for the tab widget*/

    //Tab 1 - Container
    QGroupBox *boxGroup = new QGroupBox{tr("Box")};
    QGridLayout *boxLayout = new QGridLayout{boxGroup};
    boxGroup->setLayout(boxLayout);
    boxLayout->addWidget(new QLabel{tr("Breadth"), boxGroup}, 0, 0);
    boxLayout->addWidget(m_boxBreadth, 0, 1);
    boxLayout->addWidget(new QLabel{tr("Length"), boxGroup}, 1, 0);
    boxLayout->addWidget(m_boxLength, 1, 1);
    boxLayout->addWidget(new QLabel{tr("Height"), boxGroup}, 2, 0);
    boxLayout->addWidget(m_boxHeight, 2, 1);
    boxLayout->addWidget(new QLabel{tr("Weight"), boxGroup}, 3, 0);
    boxLayout->addWidget(m_boxWeight, 3, 1);
    boxLayout->addWidget(m_btnAddBox, 4, 0, 1, 2);

    QGroupBox *cylinderGroup = new QGroupBox{tr("Cylinder")};
    QGridLayout *cylinderLayout = new QGridLayout{cylinderGroup};
    cylinderGroup->setLayout(cylinderLayout);
    cylinderLayout->addWidget(new QLabel{tr("Diameater"), cylinderGroup}, 0, 0);
    cylinderLayout->addWidget(m_cylinderDiameater, 0, 1);
    cylinderLayout->addWidget(new QLabel{tr("Height"), cylinderGroup}, 1, 0);
    cylinderLayout->addWidget(m_cylinderHeight, 1, 1);
    cylinderLayout->addWidget(new QLabel{tr("Weight"), cylinderGroup}, 2, 0);
    cylinderLayout->addWidget(m_cylinderWeight, 2, 1);
    cylinderLayout->addWidget(new QLabel{tr(""), cylinderGroup}, 3, 0);
    cylinderLayout->addWidget(m_btnAddCylinder, 4, 0, 1, 2);

    QWidget *bottomWidget = new QWidget{this};
    QGridLayout *bottomLayout = new QGridLayout{bottomWidget};
    bottomWidget->setLayout(bottomLayout);
    bottomLayout->addWidget(new QLabel{tr("List of unallocated containers"), bottomWidget}, 0, 0);
        QLabel *labelClickOn{new QLabel{tr("Click on item in list, choose a pallet number, and Move the container to that pallet"), bottomWidget}};
        labelClickOn->setWordWrap(true);
    bottomLayout->addWidget(m_displayUnallocated, 1, 0, 5, 1);
    bottomLayout->addWidget(labelClickOn, 1, 1);
    bottomLayout->addWidget(m_palletNumber, 2, 1);
    /*1pallet*/m_palletNumber->setMinimum(1);
    bottomLayout->addWidget(m_btnMoveToPallet, 3, 1);
    bottomLayout->addWidget(m_btnRollbackRestore, 4, 1);
    bottomLayout->addWidget(m_btnBackupRestore, 5, 1);

    QWidget *containerWidget = new QWidget{this};
    QGridLayout *containerLayout = new QGridLayout{containerWidget};
    containerLayout->addWidget(boxGroup, 0, 0);
    containerLayout->addWidget(cylinderGroup, 0, 1);
    containerLayout->addWidget(bottomWidget, 1, 0, 1, 2);
    containerWidget->setLayout(containerLayout);

    return containerWidget;
}

QWidget *MainWidget::getWidgetPost()
{
    /* Creates the widget for the tab widget*/

    //Tab 2 - Post
    QWidget *postWidget = new QWidget{this};
    QVBoxLayout *postLayout = new QVBoxLayout{postWidget};
    postWidget->setLayout(postLayout);
    postLayout->addWidget(m_btnPostXML);
    postLayout->addWidget(m_displayPalletXML);

    return postWidget;
}
/*End Pre application setups*/

/*Slot implmenetations*/
//Constant gui changes
void MainWidget::slot_updateGUI()
{
    /* This slot continues to loop in a seperate thread
     * to enable or disable the correct gui elements
     */

    //Backup and Restore functionality
    m_loopThread = true;

    m_btnBackupRestore->setDisabled(true);
    m_btnRollbackRestore->setDisabled(true);

    while(m_loopThread){
        /* This loops continuously in the background
         * untill the thread is stopped*/

        //Manage the GUI pushButtons
        //If any box spinboxes are empty, disable the add box button
            if(m_boxBreadth->value() > 0
                && m_boxLength->value() > 0
                && m_boxHeight->value() > 0
                && m_boxWeight->value() > 0){
                    m_btnAddBox->setEnabled(true);
            }else{
                m_btnAddBox->setDisabled(true);
            }
        //If any cylinder spinboxes are empty, disable the add cylinder button
            if(m_cylinderDiameater->value() > 0
                && m_cylinderHeight->value() > 0
                && m_cylinderWeight->value() > 0){
                    m_btnAddCylinder->setEnabled(true);
            }else{
                m_btnAddCylinder->setDisabled(true);
            }
        //Move to pallet button
            if(m_displayUnallocated->currentItem() != nullptr){
                m_btnMoveToPallet->setEnabled(true);
            }else{
                m_btnMoveToPallet->setDisabled(true);
            }
        //Backup Button
            if(m_displayUnallocated->count() > 0){
                //Only needs to be greater than 0 once,
                //then it implies even if zero there is something in the pallet list
                m_btnBackupRestore->setEnabled(true);
                m_btnRollbackRestore->setEnabled(true);
            }
    }
}

void MainWidget::slot_appendContainer()
{
    /* This slot append a container type Box or Cylinder
     * to the container list, after first performing 
     * some basic validation checks
     */

    ContainerFactory *factory = new ContainerFactory{};
    QString senderName = QObject::sender()->objectName();
    if(senderName == "BoxButton"){
        //If the serialCode overflows past 9999 it resets to 0
        int serialCode = m_serialCode.getSerialCode();
        int weight = m_boxWeight->value();
        int height = m_boxHeight->value();
        int length = m_boxLength->value();
        int breadth = m_boxBreadth->value();

        //Checks if the pulled UI element values are valid
        Validator *validator = new Validator{};
        if(validator->preContainerValidation(serialCode, weight, height, length, breadth)){

            //Creates the container
            Container *newContainer = factory->createContainer(serialCode, weight, height, length, breadth);
            if(newContainer != nullptr){
                //Increments the serial code
                m_serialCode++;
                m_containerList->addContainer(newContainer);
                m_displayUnallocated->addItem(newContainer->getContainerCode());
                emit signal_updateStatusBar(tr("Box added"));
            }else{
                delete newContainer;
                emit signal_updateStatusBar(tr("Box not added"));
            }
        }else{
            emit signal_updateStatusBar(tr("Box not added"));
        }
    }else if(senderName == "CylinderButton"){
        //If the serialCode overflows past 9999 it resets to 0
        int serialCode = m_serialCode.getSerialCode();
        int weight = m_cylinderWeight->value();
        int height = m_cylinderHeight->value();
        int diameter = m_cylinderDiameater->value();
        
        //Checks if the pulled UI element values are valid
        Validator *validator = new Validator{};
        if(validator->preContainerValidation(serialCode, weight, height, diameter)){

            Container *newContainer = factory->createContainer(serialCode, weight, height, diameter);
            if(newContainer != nullptr){
                //Increments the serial code
                m_serialCode++;
                m_containerList->addContainer(newContainer);
                m_displayUnallocated->addItem(newContainer->getContainerCode());
                emit signal_updateStatusBar(tr("Cylinder added"));
            }else{
                delete newContainer;
                emit signal_updateStatusBar(tr("Cylinder not added"));
            }
        }else{
            emit signal_updateStatusBar(tr("Cylinder not added"));
        }
    }
}

void MainWidget::slot_moveToPallet()
{
    //Ensures the user wants to move the container to the pallet
    if(QMessageBox::Yes == QMessageBox::question(this, "Move Contianer", "Are you sure you want to move this container to pallet " + m_palletNumber->text() + "?")){
        //Gets all selected items
        QList<QListWidgetItem*> items = m_displayUnallocated->selectedItems();
        foreach(QListWidgetItem *item, items){
            //Acts upon the individually selected items
            int index = m_displayUnallocated->row(item);
            Pallet *pallet = new Pallet{m_palletNumber->value()};
            pallet->addContainer(m_containerList->getContainer(index));
            m_palletList->addPallet(pallet);
            delete m_displayUnallocated->takeItem(index);
            m_containerList->removeContainer(index);
            emit signal_updateStatusBar(tr("Container moved to pallet"));
        }
    }
}

void MainWidget::slot_postXML()
{
    //Post xml to server
    if(m_palletList->getSize() > 0){
        //Ensures the user truly wants to generate the xml
        if(QMessageBox::Yes == QMessageBox::question(this, "Post XML", "Are you sure you want to post the XML to the server?")){
            QThread *thread = new QThread{};
            WriteXML *writeXML = new WriteXML{m_palletList};

            //Runs the writeXML in a seperate thread
            writeXML->moveToThread(thread);
            connect(thread, &QThread::started, writeXML, &WriteXML::write);
            connect(writeXML, &WriteXML::signal_finished, thread, &QThread::quit);
            connect(writeXML, &WriteXML::signal_finished, writeXML, &WriteXML::deleteLater);
            connect(thread, &QThread::finished, thread, &QThread::deleteLater);
            connect(writeXML, SIGNAL(signal_result(QString)), this, SLOT(slot_appendXML(QString)));
            thread->start();

        }else{
            emit signal_updateStatusBar(tr("XML not posted"));
        }
    }else{
        //The passed pallet list is empty
        QMessageBox::warning(this, "Post XML", "There are no pallets to post");
    }
}

//Appends the generated xml to display on the pallet text box
void MainWidget::slot_appendXML(QString xml){
    m_displayPalletXML->clear();
    m_displayPalletXML->append(xml);
    m_displayPalletXML->setReadOnly(true);
    //m_displayPalletXML->append(xml);
    emit signal_sendXML(xml);
}

void MainWidget::slot_sendXML(QString xml){
    //Send xml to server
    QByteArray data = QString(xml).toUtf8();
    clientTCP *tcp = new clientTCP{};
    tcp->send(data);
}

void MainWidget::slot_clearInput()
{
    // Clears and resets the ui elements 
    QString senderName = QObject::sender()->objectName();
    //Stops the GUI thread to alter values manually
    m_loopThread = false;
    if(senderName == "BoxButton"){
        m_boxWeight->setValue(0);
        m_boxHeight->setValue(0);
        m_boxLength->setValue(0);
        m_boxBreadth->setValue(0);
        m_boxBreadth->setFocus();
    }else if(senderName == "CylinderButton"){
        m_cylinderWeight->setValue(0);
        m_cylinderHeight->setValue(0);
        m_cylinderDiameater->setValue(0);
        m_cylinderDiameater->setFocus();
    }
    //restarts GUI thread
    setGuiThread();
    emit signal_updateStatusBar(tr("Ready"));
}

/*End slot implmenetations*/
