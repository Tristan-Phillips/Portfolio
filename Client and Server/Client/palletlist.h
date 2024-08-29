#ifndef PALLETLIST_H
#define PALLETLIST_H

//Includes
#include "pallet.h"

class PalletList
{
public:
    PalletList();
    ~PalletList();
    //Standard List Functions
        void addPallet(Pallet* pallet);
        void removePallet(Pallet* pallet);
        int getSize() const; 
        Pallet* getPallet(int index) const;
        void clear();
        void setPalletList(PalletList* palletList);

private:
    QList<Pallet*> m_palletList;
};

#endif // PALLETLIST_H
