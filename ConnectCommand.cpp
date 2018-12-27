#include "ConnectCommand.h"

/*
 * Function Name: ConnectCommand
 * Input:
 * Output:
 * Function Operation: ConnectCommand constructor
 */
ConnectCommand::ConnectCommand() {
    ip = "";
    port = -1;
    parametersNum = 2;
    myClient = new Client();
}

/*
 * Function Name: doCommand
 * Input: vector<string> array
 * Output: int
 * Function Operation: the function set the ip and port data as members from
 * the vector and call to createClient function. returnd the parameters number.
 */
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

/*
 * Function Name: IsNumberValid
 * Input: string
 * Output: bool
 * Function Operation: the function get a string and checks if all his chars
 * are numeric digits so it is a number or not.
 */
bool ConnectCommand::IsNumberValid(string s) {
    for (unsigned int i = 0; i < s.length(); i++) {
        if (((s[i] < '0') || (s[i] > '9'))) {
            return false;
        }
    }
    return true;
}

/*
 * Function Name: IsIpValid
 * Input: string
 * Output: bool
 * Function Operation: the function get a string and checks if all his chars
 * are numeric digits and verified it has only 3 dots so it is a valid ip.
 */
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

/*
 * Function Name: getClient
 * Input:
 * Output: Client*
 * Function Operation: the function returnd the Client* member.
 */
Client* ConnectCommand::getClient() {
    return myClient;
}

/*
 * Function Name: ~ConnectCommand
 * Input:
 * Output:
 * Function Operation: ConnectCommand destructor
 */
ConnectCommand::~ConnectCommand() {
    if (myClient) {
        delete myClient;
    }
}