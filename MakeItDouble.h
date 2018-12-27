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

    Expression *isVar(string s);

    bool isOperator(char c);

public:
    MakeItDouble();

    double calculateValue(string, SymbolTable *);
    ~MakeItDouble();
};


#endif //UNTITLED_MAKEITDOUBLE_H
