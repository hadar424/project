//
// Created by hadar on 12/18/18.
//

#include "ConnectCommand.h"

ConnectCommand::ConnectCommand() {
    ip = "";
    port = -1;
    parametersNum = 2;
    myClient = new Client();
}

int ConnectCommand::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    if (IsIpValid(*it)) {
        ip = *it;
    }
    it++;
    if (IsNumberValid(*it)) {
        port = stoi(*it);
    }
    if ((port != -1) && (ip.length() > 0)) {
        myClient->createClient(port, ip);
    }
    return parametersNum +1;
}


bool ConnectCommand::IsNumberValid(string s) {
    for (unsigned int i = 0; i < s.length(); i++) {
        if (((s[i] < '0') || (s[i] > '9'))) {
            return false;
        }
    }
    return true;
}

bool ConnectCommand::IsIpValid(string s) {
    int counter = 0;
    string temp;
    for (unsigned int i = 0; i < s.length(); i++) {
        if (s.find('.') != string::npos) {
            temp = s.substr(0, s.find('.'));
            s.erase(0, s.find('.') + 1);
            if (IsNumberValid(temp)) {
                int num = stoi(temp);
                if ((num < 0) || (num > 255)) {
                    return false;
                }
            }
            counter++;
        }
    }
    if (counter != 3) {
        return false;
    }
    return true;
}

Client *ConnectCommand::getClient() {
    return myClient;
}

ConnectCommand::~ConnectCommand() {
    delete myClient;
}