//
// Created by sharon on 22/12/18.
//

#ifndef UNTITLED_MAKEITDOUBLE_H
#define UNTITLED_MAKEITDOUBLE_H

#include "Command.h"
#include "CalculateExpression.h"
#include "SymbolTable.h"

class MakeItDouble {
    double value;
    SymbolTable *myTable;
    string var;

    Expression *IsExpression(string);

    Expression *IsVar(string s);

public:
    MakeItDouble(SymbolTable *);

    double getValue();

    double calculateValue(string);

    bool IsOperator(char c);
};


#endif //UNTITLED_MAKEITDOUBLE_H
