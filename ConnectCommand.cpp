//
// Created by hadar on 12/18/18.
//

#include "ConnectCommand.h"

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
    for (int i = 0; i < s.length(); i++) {
        if (((s[i] < '0') || (s[i] > '9'))) {
            return false;
        }
    }
    return true;
}

bool ConnectCommand::IsIpValid(string s) {
    int counter = 0;
    string temp;
    for (int i = 0; i < s.length(); i++) {
        if (s.find('.') != -1) {
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