#ifndef CARETAKER_H
#define CARETAKER_H

//Not implemented

#include "momento.h"

class Caretaker
{
public:
    Caretaker();

    void setMomento(Momento *momento);
    Momento *getMomento();

private:
    Momento *momento;
};

#endif // CARETAKER_H
