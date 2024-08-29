#ifndef CODEVALIDATION_H
#define CODEVALIDATION_H

/*
    This class is used to check if the container code sent to the server is valid
*/

//Forward Declearation
class QStringList;
class QString;

class CodeValidation
{
public:
    CodeValidation();
    static bool isValidCode(QString code);
};

#endif // CODEVALIDATION_H
