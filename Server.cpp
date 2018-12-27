#include "Server.h"

/*
 * Function Name: threadFunc
 * Input: void* arg
 * Output: void*
 * Function Operation: read as long as the simulator is on
 */
void *threadFunc(void *arg) {
    // get this (threadFunc is C function, and we want to have Server functions)
    Server *myServer = (Server *) arg;
    char buffer[1025] = {0};
    int readVars;
    while (myServer->continueThread) {
        // read from simulator
        readVars = read(myServer->getClientSocket(), buffer, 1024);
        if (readVars > 0) {
            // use it as string, after the num of bits it is not relevant
            buffer[readVars] = 0;
            // parser the buffer (format: double, double.....)
            myServer->parserOfVars(buffer);
        }
    }
    // return null pointer
    return nullptr;
}

/*
 * Function Name: Server
 * Input: -
 * Output: -
 * Function Operation: constructor, initialize array of vars from server
 */
Server::Server() {
    clientSocket = -1;
    stringToParse = "";
    bReceivedDataFromServer = false;
    numOfMessagesFromServer = 0;
    ArrBindAddresses[0] = VAR_1;
    ArrBindAddresses[1] = VAR_2;
    ArrBindAddresses[2] = VAR_3;
    ArrBindAddresses[3] = VAR_4;
    ArrBindAddresses[4] = VAR_5;
    ArrBindAddresses[5] = VAR_6;
    ArrBindAddresses[6] = VAR_7;
    ArrBindAddresses[7] = VAR_8;
    ArrBindAddresses[8] = VAR_9;
    ArrBindAddresses[9] = VAR_10;
    ArrBindAddresses[10] = VAR_11;
    ArrBindAddresses[11] = VAR_12;
    ArrBindAddresses[12] = VAR_13;
    ArrBindAddresses[13] = VAR_14;
    ArrBindAddresses[14] = VAR_15;
    ArrBindAddresses[15] = VAR_16;
    ArrBindAddresses[16] = VAR_17;
    ArrBindAddresses[17] = VAR_18;
    ArrBindAddresses[18] = VAR_19;
    ArrBindAddresses[19] = VAR_20;
    ArrBindAddresses[20] = VAR_21;
    ArrBindAddresses[21] = VAR_22;
    ArrBindAddresses[22] = VAR_23;

}

/*
 * Function Name: createServer
 * Input: double port
 * Output: -
 * Function Operation: create the sockets and thread
 */
void Server::createServer(double port) {
    struct sockaddr_in address;
    int addrLen = sizeof(address);

    // creating socket file descriptor
    if ((listenSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        throw runtime_error("socket failed");
    }

    memset(&address, '0', sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // do the bind
    if (bind(listenSocket, (struct sockaddr *) &address, sizeof(address)) < 0) {
        throw runtime_error("bind failed");
    }
    // listen
    if (listen(listenSocket, 1) < 0) {
        throw runtime_error("listen failed");
    }
    // accept
    if ((clientSocket = accept(listenSocket, (struct sockaddr *) &address,
                               (socklen_t *) &addrLen)) < 0) {
        throw runtime_error("accept failed");
    }

    // create the thread
    pthread_t waitForClient;
    pthread_create(&waitForClient, nullptr, threadFunc, this);

    close(listenSocket);
    // block until get data
    while (bReceivedDataFromServer == false);
}

/*
 * Function Name: getCompleteMessage
 * Input: -
 * Output: string
 * Function Operation: return the message until \n and update the remain
 */
string Server::getCompleteMessage() {
    int rc = stringToParse.find('\n');
    string temp = "";
    // if there is no '\n', return empty string
    if (rc < 0)
        return temp;
    // otherwise, we have a message
    temp = stringToParse.substr(0, rc + 1);
    // update the remain
    stringToParse = stringToParse.substr(rc + 1, stringToParse.length());
    // return the message until \n
    return temp;
}

/*
 * Function Name: getParam
 * Input: string &Message
 * Output: string
 * Function Operation: return the param (format from buffer: ...,param,...)
 */
string Server::getParam(string &message) {
    string param;
    int rc = message.find(',');
    // check if there is ','
    if (rc > 0) {
        // the param is until ','
        param = message.substr(0, rc);
        // update the rest of the message
        message = message.substr(rc + 1, message.length());
    } else {
        // if this is the last param
        param = message.substr(0, message.find('\n'));
        message = "";
    }
    // return param
    return param;
}

/*
 * Function Name: parserOfVars
 * Input: string &Message
 * Output: void
 * Function Operation: parse the buffer and update the map
 */
void Server::parserOfVars(string buffer) {
    stringToParse += buffer;
    string completeMessage;
    double value = 0;
    // check if receive buffer has a complete message
    completeMessage = getCompleteMessage();
    while (completeMessage.length() > 0) {
        numOfMessagesFromServer++;
        // the values are right from second time, the first is all 0
        if (bReceivedDataFromServer == false) {
            if (numOfMessagesFromServer == SECOND_TIME_DATA)
                // this will allow create server to continue
                bReceivedDataFromServer = true;
        }
        // get one parameter
        string param = getParam(completeMessage);
        int i = 0;
        while (param.length() > 0) {
            value = stod(param);
            // start of lock
            mtxForMyTable.lock();
            // update in table
            if (myTable.find(ArrBindAddresses[i]) != myTable.end())
                myTable[ArrBindAddresses[i]] = value;
                // insert to table
            else {
                myTable.insert(make_pair(ArrBindAddresses[i], value));
            }
            // unlock
            mtxForMyTable.unlock();
            i++;
            // get next param
            param = getParam(completeMessage);
        }
        // check if more complete messages in buffer
        completeMessage = getCompleteMessage();
    }
}

/*
 * Function Name: getClientSocket
 * Input: -
 * Output: int
 * Function Operation: return client socket
 */
int Server::getClientSocket() {
    return clientSocket;
}

/*
 * Function Name: getValueFromMap
 * Input: -
 * Output: -
 * Function Operation: return the value of the var we looked for in map
 */
Expression *Server::getValueFromMap(string s) {
    char temp[1000];
    strcpy(temp, s.c_str());
    Expression *exp = nullptr;
    mtxForMyTable.lock();
    // check if var is in my server map
    if ((myTable.find(s)) != myTable.end()) {
        exp = new Number(myTable.find(s)->second);
    }
    mtxForMyTable.unlock();
    // return the expression (value)
    return exp;
}

/*
 * Function Name: ~Server
 * Input: -
 * Output: -
 * Function Operation: destructor
 */
Server::~Server() {
    continueThread = false;
    if (clientSocket != -1) {
        close(clientSocket);
    }
}