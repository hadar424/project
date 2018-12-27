#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H

#include "Command.h"
#include "Server.h"

using namespace std;

class OpenServerCommand : public Command {
    int parametersNum;
    double port;
    double hertz;
    Server *myServer = nullptr;

    bool isnumber(string);

public:
    OpenServerCommand();
    int doCommand(vector<string>);

    Server *getServer();
    ~OpenServerCommand();
};


#endif //PROJECT_OPENSERVERCOMMAND_H
