#include "Parser.h"

MyParser::MyParser(vector<string> v) {
    commandArray = v;
    define->setSymbolTable(myTable);
    condition->setSymbolTable(myTable);
    printV->setSymbolTable(myTable);
    sleepV->setSymbolTable(myTable);
    assignC->setSymbolTable(myTable);
    assignC->setServer(server->getServer());
    assignC->setClient(connect->getClient());
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
    Command *temp;
    while ((it = commandArray.begin()) < commandArray.end() - 1) {
        if((commandMap.find(*it))!= commandMap.end()) {
            temp = commandMap.find(*it)->second;
            commandArray.erase(commandArray.begin());
            it += temp->doCommand(commandArray);
            commandArray.erase(commandArray.begin(), it);
        } else if ((*(it + 1)).compare("=") == 0) {
            it++;
            temp = commandMap.find(*it)->second;
            it += temp->doCommand(commandArray);
            commandArray.erase(commandArray.begin(), it);
        } else {
            commandArray.erase(commandArray.begin(),it+1);
        }
    }
}

MyParser::~MyParser() {
    delete myTable;
    delete server;
    delete connect;
    delete define;
    delete condition;
    delete loop;
    delete ifCondition;
    delete printV;
    delete sleepV;
    delete assignC;
}
