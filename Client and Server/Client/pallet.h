#ifndef PALLET_H
#define PALLET_H

//Includes
#include "containerlist.h"

class Pallet
{
public:
    Pallet(int palletNumber);
    ~Pallet();
    void addContainer(Container* container);
    void removeContainer(Container* container);
    int getSize() const;
    Container* getContainer(int index) const;

    //Getters
        int getPalletNumber() const;
        int getPalletWeight() const;
        int getPalletVolume() const;

private:
    //Pallet can contain more than one container
        ContainerList* m_containerList;
    //Private setters
        void setPalletVolume(int newPalletVolume);
        void setPalletWeight(int newPalletWeight);
        void setPalletNumber(int newPalletNumber);

    //Pallet stats
        int m_palletNumber;
        int m_palletWeight;
        int m_palletVolume;
};

#endif // PALLET_H
