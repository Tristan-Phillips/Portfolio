#ifndef BOX_H
#define BOX_H

//Parent Class
#include "container.h"

class Box : public Container
{
    Q_OBJECT
    Q_PROPERTY(int length READ getLength CONSTANT)
    Q_PROPERTY(int breadth READ getBreadth CONSTANT)
    /*Properties are only used to read the values
     * Setters are deliberately not used*/

public:
    Box(int serialCode, int weight, int height, int length, int breadth);
    ~Box();
    //Getters
        int getLength() const;
        int getBreadth() const;
    
    //Virtual from base class
        QString getContainerCode() const;
        QString toString() const;
        int getVolume() const;

signals:
    //Removes annoying NOTIFY warning from Q_PROP
        void fooBar();
private:
    //Member Variables
        QString m_containerCode;
    /*Difference between ContainerCode and serialCode
     * Container code is the full xx/xx/xx
     * Serial Code is only the 0000 - 9999*/
        int m_length;
        int m_breadth;

};

#endif // BOX_H
