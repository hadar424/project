#include "Parser.h"

MyParser::MyParser(vector<string> v) {
    commandArray = v;
    commandMap.insert(pair<string,Command*>("openDataServer",new OpenServerCommand()));
    commandMap.insert(pair<string,Command*>("connect",new ConnectCommand()));
    commandMap.insert(pair<string,Command*>("var",new DefineVarCommand()));
}

void MyParser::parser() {
    vector<string>::iterator it;
    while( (it = commandArray.begin() )<commandArray.end()) {
        if((mapIt=commandMap.find(*it))!= commandMap.end()) {
            Command *temp = commandMap.find(*it)->second;
            commandArray.erase(commandArray.begin());
            it += temp->doCommand(commandArray);
            commandArray.erase(commandArray.begin(),it);
        } else {
            it++;
        }
    }
}
