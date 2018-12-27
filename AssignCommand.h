#ifndef UNTITLED_ASSIGNCOMMAND_H
#define UNTITLED_ASSIGNCOMMAND_H

#include "Command.h"
#include "SymbolTable.h"
#include "Server.h"
#include "MakeItDouble.h"
#include "CalculateExpression.h"
#include <string>
#include "Client.h"

class AssignCommand : public Command {
    Server *myServer;
    Client *myClient;
    SymbolTable *myTable;
    string var;
    double value;
    string path;
    int parametersNum;
    MakeItDouble myMakeItDouble;
    string cleanPath(string s);

public:
    AssignCommand();
    int doCommand(vector<string>);
    void setSymbolTable(SymbolTable *);
    void setServer(Server *);
    void setClient(Client *);
    ~AssignCommand();
};


#endif //UNTITLED_ASSIGNCOMMAND_H
