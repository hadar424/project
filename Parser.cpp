#include "Parser.h"

MyParser::MyParser(vector<string> v) {
    commandArray = v;
    OpenServerCommand *server = new OpenServerCommand();
    ConnectCommand *connect = new ConnectCommand();
    DefineVarCommand *define = new DefineVarCommand();
    ConditionParser *condition = new ConditionParser();
    LoopCondition* loop = new LoopCondition();
    define->setSymbolTable(myTable);
    condition->setSymbolTable(myTable);
    commandMap.insert(pair<string, Command *>("openDataServer", server));
    commandMap.insert(pair<string, Command *>("connect", connect));
    commandMap.insert(pair<string, Command *>("var", define));
    commandMap.insert(pair<string, Command *>("while", loop));
    condition->setCommandMap(commandMap);
}

void MyParser::parser() {
    vector<string>::iterator it;
    while( (it = commandArray.begin() )<commandArray.end()) {
        if((commandMap.find(*it))!= commandMap.end()) {
            Command *temp = commandMap.find(*it)->second;
            commandArray.erase(commandArray.begin());
            it += temp->doCommand(commandArray);
            commandArray.erase(commandArray.begin(),it);
        } else if(myTable->getValue(*it) != NULL) {
            Command *temp = commandMap.find("var")->second;
            it += temp->doCommand(commandArray);
            commandArray.erase(commandArray.begin(),it);
        } else {
            it++;
        }
    }
}
