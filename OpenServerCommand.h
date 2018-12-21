#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H

#include "Command.h"
#include "Server.h"

using namespace std;

class OpenServerCommand : public Command {
    int parametersNum = 2;
    double port = -1;
    double hertz = -1;

public:
    OpenServerCommand() = default;
    int doCommand(vector<string>);
    bool Isnumber(string);
};


#endif //PROJECT_OPENSERVERCOMMAND_H
