#ifndef PROJECT_PARSER_H
#define PROJECT_PARSER_H

#include <string>
#include <iostream>
#include "ConnectCommand.h"
#include "OpenServerCommand.h"
#include <vector>
#include "DefineVarCommand.h"

using namespace std;

class MyParser {
    //int arraySize;
    vector<string> commandArray;
    unordered_map<string,Command*> commandMap;
    unordered_map<string,Command*>::iterator mapIt;
public:
    MyParser(vector<string>);
    void parser();
};


#endif //PROJECT_PARSER_H
