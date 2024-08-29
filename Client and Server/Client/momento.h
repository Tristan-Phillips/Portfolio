#ifndef MOMENTO_H
#define MOMENTO_H

#include "containerlist.h"
#include "palletlist.h"

class Momento
{
public:
    ~Momento();
    bool isNull();
private:
    friend class MainWidget;
    Momento();
    void setState(ContainerList *containerList, PalletList *palletList);
    ContainerList *getContainerList() const;
    PalletList *getPalletList() const;
    //Member Variables
        ContainerList *m_containerList;
        PalletList *m_palletList;
};

#endif // MOMENTO_H
