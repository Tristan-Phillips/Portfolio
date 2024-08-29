//Local Includes
#include "cylinder.h"
#include "calculations.h"
//External Includes
#include <QDate>

Cylinder::Cylinder(int serialCode, int weight, int height, int diameter)
    :   Container{serialCode, weight, height},
    m_diameter{diameter}
{
    /*Container Code gets auto generated on the instantiation of the class*/
        m_containerCode = QString("%1/%2/C%3")
                .arg(QString::number(QDate::currentDate().year()),
                    QDate::currentDate().toString("MM"),
                    QString::number(this->getSerialCode()));
}

Cylinder::~Cylinder()
{}

//Getters
int Cylinder::getDiameter() const
{
    return m_diameter;
}

//Virtual from base class
QString Cylinder::getContainerCode() const
{
    return m_containerCode;
}

QString Cylinder::toString() const
{
    /*To String Function is simply for testing purposes*/
        return QString("ContainerCode: %1 Weight: %2 Volume: %3 Height: %4 Diameter: %5")
                .arg(this->getContainerCode())
                .arg(this->getWeight())
                .arg(this->getVolume())
                .arg(this->getHeight())
                .arg(this->getDiameter());
}

int Cylinder::getVolume() const
{
    return Calculations::calculateVolume(this->getHeight(), this->getDiameter());
}
