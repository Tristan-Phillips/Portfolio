#include "data.h"
#include "codevalidation.h"

Data::Data(int palletNumber, QString containerType, QString containerCode, int height, int breadthDiameter, int length, int weight)
    : m_palletNumber{palletNumber},
      m_containerType{containerType},
      m_containerCode{containerCode},
      m_height{height},
      m_breadthDiameter{breadthDiameter},
      m_length{length},
      m_weight{weight}
{}

int Data::getPalletNumber() const
{
    return m_palletNumber;
}

void Data::setPalletNumber(int newPalletNumber)
{
    m_palletNumber = newPalletNumber;
}

const QString &Data::getContainerType() const
{
    return m_containerType;
}

void Data::setContainerType(const QString &newContainerType)
{
    m_containerType = newContainerType;
}

const QString &Data::getContainerCode() const
{
    return m_containerCode;
}

void Data::setContainerCode(const QString &newContainerCode)
{
    if(CodeValidation::isValidCode(newContainerCode)){
        m_containerCode = newContainerCode;
    }else{
        m_containerCode = "****";
    }
}

int Data::getHeight() const
{
    return m_height;
}

void Data::setHeight(int newHeight)
{
    m_height = newHeight;
}

int Data::getBreadthDiameter() const
{
    return m_breadthDiameter;
}

void Data::setBreadthDiameter(int newBreadthDiameter)
{
    m_breadthDiameter = newBreadthDiameter;
}

int Data::getLength() const
{
    return m_length;
}

void Data::setLength(int newLength)
{
    m_length = newLength;
}

int Data::getWeight() const
{
    return m_weight;
}

void Data::setWeight(int newWeight)
{
    m_weight = newWeight;
}
