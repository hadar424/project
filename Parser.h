#ifndef PROJECT_PARSER_H
#define PROJECT_PARSER_H

#include <string>
#include <unordered_map>
#include <iostream>
#include "ConnectCommand.h"
#include "OpenServerCommand.h"
#include <vector>
#include "DefineVarCommand.h"

using namespace std;

class MYParser {
    //int arraySize;
    vector<string> commandArray;
    unordered_map<string,Command*> commandMap;
public:
    MYParser(vector<string>);
    void parser();
};


#endif //PROJECT_PARSER_H
