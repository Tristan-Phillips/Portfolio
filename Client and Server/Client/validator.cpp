#include "validator.h"
#include <QDate>
Validator::Validator()
{}

bool Validator::preContainerValidation(int serialCode, int weight, int height, int lenght, int breadth)
{
    if(serialCode < 0 || serialCode > 9999){
        return false;
    }
    if(weight < 0){
        return false;
    }
    if(height < 0){
        return false;
    }
    if(lenght < 0){
        return false;
    }
    if(breadth < 0){
        return false;
    }
    if(!dateValidator()){
        return false;
    }
    return true;
}

bool Validator::preContainerValidation(int serialCode, int weight, int height, int diameter)
{
    if(serialCode < 0 || serialCode > 9999){
        return false;
    }
    if(weight < 0){
        return false;
    }
    if(height < 0){
        return false;
    }
    if(diameter < 0){
        return false;
    }
    if(!dateValidator()){
        return false;
    }
    return true;
}

bool Validator::dateValidator()
{
    QDate date = QDate::currentDate();
    if(date.year() < 2000){
        return false;
    }else if(date.year() > 2099){
        return false;
    }

    if(date.month() < 1){
        return false;
    }else if(date.month() > 12){
        return false;
    }

    return true;
}
