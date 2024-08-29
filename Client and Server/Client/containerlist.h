#ifndef CONTAINERLIST_H
#define CONTAINERLIST_H

//Includes
#include "container.h"

class ContainerList
{
public:
    ContainerList();
    ~ContainerList();
    //Standard List Functions 
        void addContainer(Container *container);
        void removeContainer(int location);
        Container *getContainer(int location);
        int getSize() const;
        void clear();
        void setContainerList(ContainerList *containerList);

private:
    //Hold a list of containers while keeping the functions of a QList
        QList<Container*> m_containerList;
};

#endif // CONTAINERLIST_H
