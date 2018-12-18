//
// Created by hadar on 12/18/18.
//

#ifndef UNTITLED_CONNECTCOMMAND_H
#define UNTITLED_CONNECTCOMMAND_H

#include "Command.h"


using namespace std;


class ConnectCommand : public Command {
    string ip = "";
    double port = -1;
    int parametersNum = 2;
public:
    int doCommand(vector<string>);

    bool IsIpValid(string);

    bool IsNumberValid(string);
};


#endif //UNTITLED_CONNECTCOMMAND_H
