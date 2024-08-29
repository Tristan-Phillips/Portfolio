#include "palletlist.h"

PalletList::PalletList()
{}

PalletList::~PalletList()
{
    qDeleteAll(m_palletList);
}

void PalletList::addPallet(Pallet* pallet)
{
    /* Compares the pallet number of the pallet to the pallet number of the pallet in the list.
     * If the pallet number matches the pallet number in the list, the containers are added to the existing pallet.
     * If the pallet does not match any pallet number in the list, the pallet is added as a new pallet to the list.
     */
    
        for(int i = 0; i < m_palletList.size(); i++){
            if(m_palletList[i]->getPalletNumber() == pallet->getPalletNumber()){
                m_palletList.at(i)->addContainer(pallet->getContainer(0));
                return;
            }
        }
        if(pallet != nullptr){
            m_palletList.append(pallet);
        }
}

void PalletList::removePallet(Pallet* pallet)
{
    for(int i = 0; i < m_palletList.size(); i++){
        if(m_palletList[i]->getPalletNumber() == pallet->getPalletNumber()){
            m_palletList.removeAt(i);
            return;
        }
    }
}

void PalletList::setPalletList(PalletList* palletList)
{
    m_palletList = palletList->m_palletList;
}

//Getters
int PalletList::getSize() const
{
    return m_palletList.size();
}

Pallet* PalletList::getPallet(int index) const
{
    return m_palletList.at(index);
}

void PalletList::clear()
{
    m_palletList.clear();
}