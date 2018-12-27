#ifndef UNTITLED_SLEEPCOMMAND_H
#define UNTITLED_SLEEPCOMMAND_H

#include "Command.h"
#include "CalculateExpression.h"
#include "SymbolTable.h"
#include <string>
#include <unistd.h>
#include "MakeItDouble.h"

class SleepCommand : public Command {
    SymbolTable *myTable = nullptr;
    double numOfSeconds;
    MakeItDouble myMakeItDouble;
    int parametersNum;
public:
    SleepCommand();
    int doCommand(vector<string>);

    void setSymbolTable(SymbolTable *);
};


#endif //UNTITLED_SLEEPCOMMAND_H
