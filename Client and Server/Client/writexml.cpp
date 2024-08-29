//Local Includes
#include "writexml.h"
#include "palletlist.h"
#include "pallet.h"
#include "container.h"
#include "containerlist.h"

//External Includes
#include <QDomDocument>
#include <QDomElement>
#include <QMetaObject>
#include <QMetaProperty>

WriteXML::WriteXML(PalletList *palletList)
    :m_palletList{palletList}
{}

void WriteXML::write(){
    QDomDocument document;
    QDomElement root = document.createElement("pallets");
    root.setAttribute("NumberOfPallets", m_palletList->getSize());
    document.appendChild(root);

    //Cycles thorugh the pallet list and gets each individual pallet
        for(int i = 0; i < m_palletList->getSize(); i++){
            Pallet *palletObj = m_palletList->getPallet(i);
            QDomElement pallet = document.createElement("pallet");
            pallet.setAttribute("weight", palletObj->getPalletWeight());
            pallet.setAttribute("volume", palletObj->getPalletVolume());
            pallet.setAttribute("number", palletObj->getPalletNumber());
            root.appendChild(pallet);

        //Cycles through the container list and gets each individual container
            for(int j = 0; j < palletObj->getSize(); j++){
                Container *containerObj = palletObj->getContainer(j);
                QString containerName = QString(containerObj->metaObject()->className());
                QDomElement container = document.createElement(containerName);
                pallet.appendChild(container);
            //Cycles through the properties of the container using QMetaObjects and adds them to the xml
                for(int k = 1; k < containerObj->metaObject()->propertyCount(); k++){
                    QMetaProperty property = containerObj->metaObject()->property(k);
                    QString propertyName = QString(property.name());
                    QString propertyValue = QString(property.read(containerObj).toString());

                    QDomElement containerProperty = document.createElement(propertyName);
                    QDomText value = document.createTextNode(propertyValue);
                    containerProperty.appendChild(value);
                    container.appendChild(containerProperty);
                }
            }
        }
    //Emits result in form of signal to be used by MainWidget to sent to server and display
        emit signal_result(document.toString());
    //Emits finished signal to indicate that the thread can stop
        emit signal_finished();
}
