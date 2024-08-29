//Local Includes
#include "box.h"
#include "calculations.h"
//External Includes
#include <QDate>
#include <QMessageBox>

Box::Box(int serialCode, int weight, int height, int length, int breadth)
    : Container{serialCode, weight, height},
    m_length{length},
    m_breadth{breadth}
{
    /*Member variables can only be set during object creation and cannot be changed*/
    /*Container Code gets auto generated on the instantiation of the class*/
        m_containerCode = QString("%1/%2/B%3")
                .arg(QString::number(QDate::currentDate().year()),
                    QDate::currentDate().toString("MM"),
                    QString::number(this->getSerialCode()));
}

Box::~Box()
{}

//Getters
int Box::getLength() const
{
    return m_length;
}

int Box::getBreadth() const
{
    return m_breadth;
}

//Virtual from base class
QString Box::getContainerCode() const
{
    return m_containerCode;
}

QString Box::toString() const
{
    /*To String Function is simply for testing purposes*/
        return QString("ContainerCode: %1 Weight: %2 Volume: %3 Height: %4 Length: %5 Breadth: %6")
                .arg(this->getContainerCode())
                .arg(this->getWeight())
                .arg(this->getVolume())
                .arg(this->getHeight())
                .arg(this->getLength())
                .arg(this->getBreadth());
}

int Box::getVolume() const
{
    return Calculations::calculateVolume(this->getBreadth(), this->getLength(), this->getHeight());
}
