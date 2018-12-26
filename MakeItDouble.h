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
    Expression *e;
    Expression *IsVar(string s);

public:
    MakeItDouble();

    double calculateValue(string, SymbolTable *);
    bool IsOperator(char c);

    ~MakeItDouble();
};


#endif //UNTITLED_MAKEITDOUBLE_H
