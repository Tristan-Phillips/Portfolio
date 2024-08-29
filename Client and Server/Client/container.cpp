//Local Includes
#include "container.h"
#include "calculations.h"

Container::Container(int serialCode, int weight, int height)
    :   m_serialCode{serialCode},
    m_weight{weight},
    m_height{height}
{
    /*Values can only be set during object creation and cannot be changed*/
}

Container::~Container()
{}

//Getters
int Container::getSerialCode() const
{
    return m_serialCode;
}

int Container::getWeight() const
{
    return m_weight;
}

int Container::getHeight() const
{
    return m_height;
}
