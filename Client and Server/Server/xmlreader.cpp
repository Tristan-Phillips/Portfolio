//Local Includes
#include "xmlreader.h"
#include "data.h"

//External Includes
#include <QByteArray>
#include <QXmlStreamReader>

XMLReader::XMLReader(QByteArray data)
    : m_dataList{new QList<Data*>}
{
    QXmlStreamReader xml(data);
    Data *dataCopy = new Data;
    while(!xml.atEnd()){
        xml.readNext();
        if(xml.isStartElement()){
            if(xml.name() == "pallet"){
                dataCopy->setPalletNumber(xml.attributes().value("number").toString().toInt());
            }
            if(xml.name() == "Box"){
                dataCopy->setContainerType("Box");
            }   
            if(xml.name() == "Cylinder"){
                dataCopy->setContainerType("Cylinder");
            }
            if(xml.name() == "code"){
                dataCopy->setContainerCode(xml.readElementText());
            }
            if(xml.name() == "weight"){
                dataCopy->setWeight(xml.readElementText().toInt());
            }
            if(xml.name() == "height"){
                dataCopy->setHeight(xml.readElementText().toInt());
            }
            if(xml.name() == "breadth" || xml.name() == "diameter"){
                dataCopy->setBreadthDiameter(xml.readElementText().toInt());
            }
            if(xml.name() == "length"){
                dataCopy->setLength(xml.readElementText().toInt());
            }
        }
        if(xml.isEndElement()){
            if(xml.name() == "Box" || xml.name() == "Cylinder"){
                m_dataList->append(dataCopy);
                int lastPalletNumber = dataCopy->getPalletNumber();
                dataCopy = new Data;
                dataCopy->setPalletNumber(lastPalletNumber);
            }
        }
    }
    delete dataCopy;
}

QList<Data*> XMLReader::getDataList() const
{
    return *m_dataList;
}
