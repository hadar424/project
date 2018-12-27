#ifndef UNTITLED_NUMBER_H
#define UNTITLED_NUMBER_H

#include "Expression.h"

class Number : public Expression{
    double value;
public:
    Number(double);
    double calculate();
};


#endif //UNTITLED_NUMBER_H