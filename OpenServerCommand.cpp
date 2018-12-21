#include "OpenServerCommand.h"

int OpenServerCommand::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    if(Isnumber(*it)) {
        port = stoi(*it);
    }
    it++;
    if(Isnumber(*it)) {
        hertz = stoi(*it);
    }
    if((port != -1) && (hertz != -1)) {
        Server *myServer = new Server(port, hertz);
    }
    return parametersNum + 1;
}

bool OpenServerCommand::Isnumber(string s) {
    for(int i =0; i<s.length(); i++) {
        if(((s[i]<'0') || (s[i]>'9'))) {
            return false;
        }
    }
    return true;
}