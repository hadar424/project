#ifndef UNTITLED_MAKEITDOUBLE_H
#define UNTITLED_MAKEITDOUBLE_H

#include "Command.h"
#include "CalculateExpression.h"
#include "SymbolTable.h"

class MakeItDouble {
    double value;
    SymbolTable *myTable;
    string var;
    bool isOperator(char c);

public:
    MakeItDouble();

    double calculateValue(string, SymbolTable *);
};


#endif //UNTITLED_MAKEITDOUBLE_H
