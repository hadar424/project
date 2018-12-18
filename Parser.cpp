#include "Parser.h"

MYParser::MYParser(vector<string> v) {
    commandArray = v;
    commandMap.insert(pair<string,Command*>("openDataServer",new OpenServerCommand));
    commandMap.insert(pair<string,Command*>("connect",new ConnectCommand));
}

void MYParser::parser() {
    for(vector<string>::iterator it = commandArray.begin();
    it<commandArray.end(); it++) {
        Command *temp = commandMap.find(*it)->second;
        commandArray.erase(commandArray.begin());
        it++;
        if (temp != NULL) {
            it += temp->doCommand(commandArray);
        }
    }
}
