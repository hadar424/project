//
// Created by sharon on 21/12/18.
//


#include "Server.h"

void *thread_func(void *arg) {
    cout << "yay! thread_func" << endl;
    Server *myServer = (Server *) arg;
    char buffer[1025] = {0};
    int readVars;
    while (myServer->continueThread) {
        readVars = read(myServer->getClientSocket(), buffer, 1024);
        if (readVars > 0) {
            buffer[readVars] = 0;// make sure nul terminated string
            myServer->ParserOfVars(buffer);
        }
    }
}

Server::Server() {
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

void Server::createServer(double port) {
    struct sockaddr_in address;
    int addrLen = sizeof(address);

    // Creating socket file descriptor
    if ((listenSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        throw runtime_error("socket failed");
    }

    memset(&address, '0', sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(listenSocket, (struct sockaddr *) &address, sizeof(address)) < 0) {
        throw runtime_error("bind failed");
    }
    if (listen(listenSocket, 1) < 0) {
        throw runtime_error("listen failed");
    }
    if ((clientSocket = accept(listenSocket, (struct sockaddr *) &address, (socklen_t *) &addrLen)) < 0) {
        throw runtime_error("accept failed");
    }
    pthread_t waitForClient;
    pthread_create(&waitForClient, nullptr, thread_func, this);

    close(listenSocket);

    cout << "waiting for data from server\n";
    while (bReceivedDataFromServer == false);
    cout << "data ready" << endl;
}


string Server::getCompleteMessage() {
    int rc = StringToParse.find('\n');
    if (rc < 0)
        return "";

    //we have a message
    string temp = StringToParse.substr(0, rc + 1);
    StringToParse = StringToParse.substr(rc + 1, StringToParse.length());

    return temp;

}


string Server::GetParam(string &Message) {
    string temp;
    int rc = Message.find(',');
    if (rc > 0) {
        temp = Message.substr(0, rc);
        Message = Message.substr(rc + 1, Message.length());
    } else {
        temp = Message.substr(0, Message.find('\n'));
        Message = "";
    }

    return temp;
}



void Server::ParserOfVars(string buffer) {
    StringToParse += buffer;
    string CompleteMessage;
    int i = 0;
    double value = 0;

    // check if receive buffer has a complete message
    CompleteMessage = getCompleteMessage();
    while (CompleteMessage.length() > 0) {
        numOfMessagesFromServer++;
        if (bReceivedDataFromServer == false) {
            cout << "received " << numOfMessagesFromServer << " messages from server\n";
            if (numOfMessagesFromServer == 2)
                bReceivedDataFromServer = true;//this will allow createserver to continue
        }


        string Param = GetParam(CompleteMessage);
        int i = 0;
        while (Param.length() > 0) {
            value = stod(Param);
            if (myTable.find(ArrBindAddresses[i]) != myTable.end())
                myTable[ArrBindAddresses[i]] = value;
            else {
                myTable.insert(make_pair(ArrBindAddresses[i], value));
            }
            //cout << ArrBindAddresses[i] << "=" + Param << endl;
            i++;
            Param = GetParam(CompleteMessage);
        }

        // check if more complete messages in buffer
        CompleteMessage = getCompleteMessage();
    }//end while complete message
}

int Server::getClientSocket() {
    return clientSocket;
}


void Server::initializeMap() {
    myTable.insert(make_pair(VAR_1, 0));
    myTable.insert(make_pair(VAR_2, 0));
    myTable.insert(make_pair(VAR_3, 0));
    myTable.insert(make_pair(VAR_4, 0));
    myTable.insert(make_pair(VAR_5, 0));
    myTable.insert(make_pair(VAR_6, 0));
    myTable.insert(make_pair(VAR_7, 0));
    myTable.insert(make_pair(VAR_8, 0));
    myTable.insert(make_pair(VAR_9, 0));
    myTable.insert(make_pair(VAR_10, 0));
    myTable.insert(make_pair(VAR_11, 0));
    myTable.insert(make_pair(VAR_12, 0));
    myTable.insert(make_pair(VAR_13, 0));
    myTable.insert(make_pair(VAR_14, 0));
    myTable.insert(make_pair(VAR_15, 0));
    myTable.insert(make_pair(VAR_16, 0));
    myTable.insert(make_pair(VAR_17, 0));
    myTable.insert(make_pair(VAR_18, 0));
    myTable.insert(make_pair(VAR_19, 0));
    myTable.insert(make_pair(VAR_20, 0));
    myTable.insert(make_pair(VAR_21, 0));
    myTable.insert(make_pair(VAR_22, 0));
    myTable.insert(make_pair(VAR_23, 0));
}

Expression *Server::getValueFromMap(string s) {
    char temp[1000];
    strcpy(temp, s.c_str());


    if ((myTable.find(s)) != myTable.end()) {
        Expression *exp = new Number(myTable.find(s)->second);
        return exp;
    } else {
        return nullptr;
    }
}

Server::~Server() {
    continueThread = false;
    close(clientSocket);
}