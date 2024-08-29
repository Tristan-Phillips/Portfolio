#ifndef DATA_H
#define DATA_H

#include <QString>

/*
    The purpose of this class is to store the data from the XML file.
    It has a constructor that takes in all the data and sets the member variables.
    It has getters and setters for each member variable.
*/

class Data
{
public:
    Data(int palletNumber = 0, QString containerType = "", QString containerCode = "", int height = 0, int breadthDiameter = 0, int length = 0, int weight = 0);
    //Getter and Setter
        int getPalletNumber() const;
        const QString &getContainerType() const;
        const QString &getContainerCode() const;
        int getHeight() const;
        int getBreadthDiameter() const;
        int getLength() const;
        int getWeight() const;

protected:
    friend class XMLReader;
    friend class Model;
        void setPalletNumber(int newPalletNumber);
        void setContainerType(const QString &newContainerType);
        void setContainerCode(const QString &newContainerCode);
        void setHeight(int newHeight);
        void setBreadthDiameter(int newBreadthDiameter);
        void setLength(int newLength);
        void setWeight(int newWeight);
private:
    int m_palletNumber;
    QString m_containerType;
    QString m_containerCode;
    int m_height;
    int m_breadthDiameter;
    int m_length;
    int m_weight;
};

#endif // DATA_H
