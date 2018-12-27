#include "OpenServerCommand.h"

/*
 * Function Name: OpenServerCommand
 * Input: -
 * Output: -
 * Function Operation: constructor, initialize members
 */
OpenServerCommand::OpenServerCommand() {
    parametersNum = 2;
    port = -1;
    hertz = -1;
    myServer = new Server();
}

/*
 * Function Name: doCommand
 * Input: vector<string> array
 * Output: -
 * Function Operation: create sever according the parameters
 */
int OpenServerCommand::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    // get the port and hertz
    if (isnumber(*it)) {
        port = stoi(*it);
    }
    it++;
    if (isnumber(*it)) {
        hertz = stoi(*it);
    }
    // create the sever
    if((port != -1) && (hertz != -1)) {
        myServer->createServer(port);
    }
    return parametersNum + 1;
}

/*
 * Function Name: isnumber
 * Input: string s
 * Output: bool
 * Function Operation: check if string is all digits - positive number
 */
bool OpenServerCommand::isnumber(string s) {
    // loop over the string
    for (unsigned int i = 0; i < s.length(); i++) {
        // check if char is between 0 to 9
        if (((s[i] < '0') || (s[i] > '9'))) {
            return false;
        }
    }
    return true;
}

/*
 * Function Name: getServer
 * Input: -
 * Output: Server*
 * Function Operation: return pointer to the server
 */
Server *OpenServerCommand::getServer() {
    return myServer;
}

/*
 * Function Name: ~OpenServerCommand
 * Input: -
 * Output: -
 * Function Operation: destructor
 */
OpenServerCommand::~OpenServerCommand() {
    if (myServer) {
        delete myServer;
    }
}