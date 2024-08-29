#ifndef CONTAINER_H
#define CONTAINER_H

//Includes
#include <QObject>

class Container : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString code READ getContainerCode CONSTANT)
    Q_PROPERTY(int weight READ getWeight CONSTANT)
    Q_PROPERTY(int volume READ getVolume CONSTANT)
    Q_PROPERTY(int height READ getHeight CONSTANT)
    /*Properties are only used to read the values
     * Setters are deliberately not used*/

public:
    Container(int serialCode, int weight, int height);
    ~Container();
    //Getters
        int getSerialCode() const;
        int getWeight() const;
//        int getVolume() const;
        int getHeight() const;
    //Pure Virtual
        virtual int getVolume() const = 0;
        virtual QString getContainerCode() const = 0;
    //To String is purely for testing purposes
        virtual QString toString() const = 0;

private:
    //Member Variables
        int m_serialCode;
        int m_weight;
        int m_height;
};

#endif // CONTAINER_H
