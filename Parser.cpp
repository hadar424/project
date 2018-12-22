#include "Parser.h"

MyParser::MyParser(vector<string> v) {
    commandArray = v;
    define->setSymbolTable(myTable);
    condition->setSymbolTable(myTable);
    printV->setSymbolTable(myTable);
    sleepV->setSymbolTable(myTable);
    assignC->setSymbolTable(myTable);
    assignC->setServer(server->getServer());
    commandMap.insert(pair<string, Command *>("openDataServer", server));
    commandMap.insert(pair<string, Command *>("connect", connect));
    commandMap.insert(pair<string, Command *>("var", define));
    commandMap.insert(pair<string, Command *>("while", loop));
    commandMap.insert(pair<string, Command *>("if", ifCondition));
    commandMap.insert(pair<string, Command *>("print", printV));
    commandMap.insert(pair<string, Command *>("sleep", sleepV));
    commandMap.insert(pair<string, Command *>("=", assignC));
    condition->setCommandMap(commandMap);
}

void MyParser::parser() {
    vector<string>::iterator it;
    while( (it = commandArray.begin() )<commandArray.end()) {
        if((commandMap.find(*it))!= commandMap.end()) {
            Command *temp = commandMap.find(*it)->second;
            commandArray.erase(commandArray.begin());
            it += temp->doCommand(commandArray);
            if ((*it).compare("=") == 0) {
                Command *temp = commandMap.find(*it)->second;
                it += temp->doCommand(commandArray);
                commandArray.erase(commandArray.begin(), it);
            } else {
                commandArray.erase(commandArray.begin(), it);
            }
        } else if (myTable->getValue(*it) != nullptr) {
            Command *temp = commandMap.find("var")->second;
            it += temp->doCommand(commandArray);
            commandArray.erase(commandArray.begin(),it);
        } else {
            commandArray.erase(commandArray.begin(),it+1);
        }
    }
}
