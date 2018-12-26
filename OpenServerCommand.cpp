#include "OpenServerCommand.h"

OpenServerCommand::OpenServerCommand() {
    parametersNum = 2;
    port = -1;
    hertz = -1;
    myServer = new Server();
}

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
        myServer->createServer(port);
    }
    return parametersNum + 1;
}

bool OpenServerCommand::Isnumber(string s) {
    for (unsigned int i = 0; i < s.length(); i++) {
        if(((s[i]<'0') || (s[i]>'9'))) {
            return false;
        }
    }
    return true;
}

Server *OpenServerCommand::getServer() {
    return myServer;
}

OpenServerCommand::~OpenServerCommand() {
    delete myServer;
}