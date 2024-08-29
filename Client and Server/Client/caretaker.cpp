#include "caretaker.h"

Caretaker::Caretaker()
{}

void Caretaker::setMomento(Momento *new_momento)
{
    momento = new_momento;
}

Momento *Caretaker::getMomento()
{
    return momento;
}