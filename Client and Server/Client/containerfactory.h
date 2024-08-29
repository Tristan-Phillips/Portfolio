#ifndef CONTAINERFACTORY_H
#define CONTAINERFACTORY_H

//Includes
#include "container.h"

class ContainerFactory
{
public:
    ContainerFactory();
    ~ContainerFactory();

    /* The functions vary in total parameters required to create the object
    * Box has 6 variables, namely serialCode, weight, volume, height, length, breadth
    * Cylinder has 5 variables, namely serialCode, weight, volume, height, diameter
    * Thus, the relevant container type will be returned based on the number of parameters passed
    */

        Container* createContainer(int serialCode, int weight, int height, int length, int width);
        Container* createContainer(int serialCode, int weight, int height, int diameter);
};

#endif // CONTAINERFACTORY_H
