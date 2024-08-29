#include "pallet.h"

Pallet::Pallet(int palletNumber)
    : m_containerList{new ContainerList},
    m_palletNumber{palletNumber},
    m_palletWeight{0},
    m_palletVolume{0}
{}

Pallet::~Pallet()
{
    delete m_containerList;
}

void Pallet::addContainer(Container* container)
{
    m_containerList->addContainer(container);
    //Adds the weight and volume of the container to the pallet
        setPalletVolume(getPalletVolume() + container->getVolume());
        setPalletWeight(getPalletWeight() + container->getWeight());
}

void Pallet::removeContainer(Container* container)
{
        setPalletVolume(getPalletVolume() - container->getVolume());
        setPalletWeight(getPalletWeight() - container->getWeight());
}

int Pallet::getSize() const
{
    return m_containerList->getSize();
}

Container *Pallet::getContainer(int index) const
{
    return m_containerList->getContainer(index);
}

//Getters
int Pallet::getPalletNumber() const
{
    return m_palletNumber;
}

int Pallet::getPalletVolume() const
{
    return m_palletVolume;
}

int Pallet::getPalletWeight() const
{
    return m_palletWeight;
}

//Private setters
void Pallet::setPalletVolume(int newPalletVolume)
{
    m_palletVolume = newPalletVolume;
}

void Pallet::setPalletWeight(int newPalletWeight)
{
    m_palletWeight = newPalletWeight;
}

void Pallet::setPalletNumber(int newPalletNumber)
{
    m_palletNumber = newPalletNumber;
}
