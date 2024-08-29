#ifndef CYLINDER_H
#define CYLINDER_H

//Includes
#include "container.h"

class Cylinder : public Container
{
    Q_OBJECT
    Q_PROPERTY(int diameter READ getDiameter CONSTANT)
    /*Properties are only used to read the values
     * Setters are deliberately not used*/

public:
    Cylinder(int serialCode, int weight, int height, int diameter);
    ~Cylinder();
    //Getters
        int getDiameter() const;

    //Virtual from base class
        QString getContainerCode() const;
    //To String is purely for testing purposes
        QString toString() const;
        int getVolume() const;

private:
    //Member Variables
        QString m_containerCode;
        int m_diameter;
};

#endif // CYLINDER_H
