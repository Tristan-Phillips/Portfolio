#ifndef VALIDATOR_H
#define VALIDATOR_H

class Validator
{
public:
    Validator();
    //Validates input for a box
        bool preContainerValidation(int serialCode, int weight, int height, int lenght, int breadth);
    //Validates input for a cylinder
        bool preContainerValidation(int serialCode, int weight, int height, int diameter);
private:
    //Validate the date for the container code
        bool dateValidator();
};

#endif // VALIDATOR_H
