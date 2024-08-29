#ifndef CALCULATIONS_H
#define CALCULATIONS_H

class Calculations
{
public:
    //Return the volume for a box
        static int calculateVolume(int length, int width, int height);
    //Return the volume for a cylinder
        static int calculateVolume(int diameter, int height);
private:
    Calculations();
};

#endif // CALCULATIONS_H
