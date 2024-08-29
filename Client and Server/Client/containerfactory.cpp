//Local Includes
#include "containerfactory.h"
#include "box.h"
#include "cylinder.h"

ContainerFactory::ContainerFactory()
{}

ContainerFactory::~ContainerFactory()
{}

Container* ContainerFactory::createContainer(int serialCode, int weight, int height, int length, int width)
{
    //Validation is done before even starting the creation of the object
    return new Box(serialCode, weight, height, length, width);
}

Container* ContainerFactory::createContainer(int serialCode, int weight, int height, int diameter)
{
    //Validation is done before even starting the creation of the object
    return new Cylinder(serialCode, weight, height, diameter);
}
