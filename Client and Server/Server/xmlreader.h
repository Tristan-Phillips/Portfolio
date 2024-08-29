#ifndef XMLREADER_H
#define XMLREADER_H

/*
    This class is used to read the XML file sent from the client.
*/

class QByteArray;
#include "data.h"

class XMLReader
{
public:
    XMLReader(QByteArray data);
    QList<Data*> getDataList() const;
private:
    QList<Data*> *m_dataList;
};

#endif // XMLREADER_H
