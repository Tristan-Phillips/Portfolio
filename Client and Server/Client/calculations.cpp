#include "calculations.h"

Calculations::Calculations()
{}

int Calculations::calculateVolume(int length, int width, int height)
{
    //Volume for a box
        return length * width * height;
}

int Calculations::calculateVolume(int diameter, int height)
{
    //Volume for a cylinder
        return 3.14 * (diameter / 2) * (diameter / 2) * height;
}
