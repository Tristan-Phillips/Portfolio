#ifndef WRITEXML_H
#define WRITEXML_H

//Includes
#include "palletlist.h"

//External includes
#include <QString>

class WriteXML : public QObject
{
    Q_OBJECT
public:
    //Initialise with a pallet list
        WriteXML(PalletList *palletList);
    
public slots:
    //Slot is used to generate xml to be sent to server and displayed
        void write();

signals: 
    //Signal is used to tansfer the xml generated
        void signal_result(QString document);
    //Signal indicates that the thread can stop
        void signal_finished();
private:
    PalletList *m_palletList;
};

#endif // WRITEXML_H
