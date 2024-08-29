#include "momento.h"
#include "containerfactory.h"

//External includes
#include <QString>
#include <QMetaObject>
#include <QMetaProperty>
#include <QVariant>

Momento::Momento()
    : m_containerList(new ContainerList),
    m_palletList(new PalletList)
{}

Momento::~Momento()
{
    delete m_containerList;
    delete m_palletList;
}

bool Momento::isNull()
{
    return (m_containerList->getSize() == 0 && m_palletList->getSize() == 0) ? true : false;
}

void Momento::setState(ContainerList *containerList, PalletList *palletList)
{
    m_containerList->clear();
    for(int i = 0; i < containerList->getSize(); i++)
    {
        Container *containerCopy = nullptr;
        containerCopy = containerList->getContainer(i);
        m_containerList->addContainer(containerCopy);
    }

    m_palletList->clear();
    for(int i = 0; i < palletList->getSize(); i++)
    {
        Pallet *palletCopy = nullptr;
        palletCopy = palletList->getPallet(i);
        m_palletList->addPallet(palletCopy);
    }
}

//Getters
ContainerList *Momento::getContainerList() const
{
    return m_containerList;
}

PalletList *Momento::getPalletList() const
{
    return m_palletList;
}

