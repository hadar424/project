#include "Parser.h"

MYParser::MYParser(vector<string> v) {
    commandArray = v;
    commandMap.insert(pair<string,Command*>("openDataServer",new OpenServerCommand));
    commandMap.insert(pair<string,Command*>("connect",new ConnectCommand));
    commandMap.insert(pair<string,Command*>("var",new DefineVarCommand));
}

void MYParser::parser() {
    vector<string>::iterator it;
    //for(vector<string>::iterator it = commandArray.begin();
    while( (it = commandArray.begin() )<commandArray.end()) {
        Command *temp = commandMap.find(*it)->second;
        commandArray.erase(commandArray.begin());
        if (temp != NULL) {
            it += temp->doCommand(commandArray);
            commandArray.erase(commandArray.begin(),it);
        }
    }
}
