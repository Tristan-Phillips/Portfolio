//Local Includes
#include "codevalidation.h"

//External Includes
#include <QRegularExpression>

CodeValidation::CodeValidation()
{}

bool CodeValidation::isValidCode(QString code)
{
    QRegularExpression regex{"^(20\\d\\d)/((0?\\d)|(1(1|2)))/(B|C)(\\d){1,4}$"};
    return regex.match(code).hasMatch();
}
