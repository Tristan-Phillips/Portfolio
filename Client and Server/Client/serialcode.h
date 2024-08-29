#ifndef SERIALCODE_H
#define SERIALCODE_H

class SerialCode
{
public:
    //Manages the serial code for the containers
        SerialCode(int begin = 1);
    
    //Getters and Setters
        int getSerialCode() const;
        void setSerialCode(int serialCode);

    //Overload to increment the serial code
        SerialCode operator++(int);
        SerialCode& operator++();

private:
    //If over 9999 reset to 0
        bool overflow();
    int m_serialCode;
};

#endif // SERIALCODE_H
