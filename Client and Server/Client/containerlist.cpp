//Local Includes
#include "containerlist.h"
#include "box.h"

ContainerList::ContainerList()
{}

ContainerList::~ContainerList()
{}

void ContainerList::addContainer(Container *container)
{
    m_containerList.append(container);
}

void ContainerList::removeContainer(int location)
{
    m_containerList.removeAt(location);
}

Container *ContainerList::getContainer(int location)
{
    return m_containerList.at(location);
}

int ContainerList::getSize() const
{
    return m_containerList.size();
}

void ContainerList::setContainerList(ContainerList *containerList)
{
    m_containerList = containerList->m_containerList;
}

void ContainerList::clear()
{
    m_containerList.clear();
}
