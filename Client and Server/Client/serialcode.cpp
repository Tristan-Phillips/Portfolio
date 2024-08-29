#include "serialcode.h"

SerialCode::SerialCode(int begin)
{
    m_serialCode = begin;
}

int SerialCode::getSerialCode() const
{
    return m_serialCode;
}

void SerialCode::setSerialCode(int serialCode)
{
    m_serialCode = serialCode;
}

SerialCode& SerialCode::operator++()
{
    if(overflow()){
        m_serialCode = 0;
    }else{
        ++m_serialCode;
    }
    return *this;
}

SerialCode SerialCode::operator++(int)
{
    SerialCode temp = *this;

    if(overflow()){
        m_serialCode = 0;
    }else{
        ++m_serialCode;
    }
    return temp;
}

bool SerialCode::overflow()
{
    if(m_serialCode > 9999){
        return true;
    }
    return false;
}
