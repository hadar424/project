//
// Created by hadar on 12/18/18.
//

#include "ConnectCommand.h"

int ConnectCommand::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    if (IsIpValid(*it)) {
        ip = *it;
    }
    if (IsNumberValid(*(it + 1))) {
        port = stoi(*(it + 1));
    }
    if ((port != -1) && (ip.length() > 0)) {

        struct sockaddr_in address;
        int sock = 0, valread;
        struct sockaddr_in serv_addr;
        string hello = "Hello from client";
        char buffer[1024] = {0};
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            throw runtime_error("Socket creation error");
        }

        memset(&serv_addr, '0', sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons((uint16_t) port);

        // Convert IPv4 and IPv6 addresses from text to binary form
        if (inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr) <= 0) {
            cout << "Invalid address/ Address not supported \n";
            return -1;
        }

        if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <
            0) {
            throw runtime_error("Connection Failed");
        }
        send(sock, hello.c_str(), hello.length(), 0);
        cout << "Hello message sent\n";
        valread = read(sock, buffer, 1024);
        cout << buffer << endl;
        return 0;
    }
    return parametersNum + 1;
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
        if (s[i] == '.') {
            counter++;
            temp = s.substr(0, s.find('.'));
            s.erase(0, s.find('.') + 1);
            if (IsNumberValid(temp)) {
                int num = stoi(temp);
                if ((num < 0) || (num > 255)) {
                    return false;
                }
            }
        }
    }
    if (counter != 3) {
        return false;
    }
    return true;
}