#ifndef UNTITLED_SERVER_H
#define UNTITLED_SERVER_H

#include <pthread.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <unordered_map>
#include <mutex>
#include "Number.h"

#define VAR_1 "/instrumentation/airspeed-indicator/indicated-speed-kt"
#define VAR_2 "/instrumentation/altimeter/indicated-altitude-ft"
#define VAR_3 "/instrumentation/altimeter/pressure-alt-ft"
#define VAR_4 "/instrumentation/attitude-indicator/indicated-pitch-deg"
#define VAR_5 "/instrumentation/attitude-indicator/indicated-roll-deg"
#define VAR_6 "/instrumentation/attitude-indicator/internal-pitch-deg"
#define VAR_7 "/instrumentation/attitude-indicator/internal-roll-deg"
#define VAR_8 "/instrumentation/encoder/indicated-altitude-ft"
#define VAR_9 "/instrumentation/encoder/pressure-alt-ft"
#define VAR_10 "/instrumentation/gps/indicated-altitude-ft"
#define VAR_11 "/instrumentation/gps/indicated-ground-speed-kt"
#define VAR_12 "/instrumentation/gps/indicated-vertical-speed"
#define VAR_13 "/instrumentation/heading-indicator/offset-deg"
#define VAR_14 "/instrumentation/magnetic-compass/indicated-heading-deg"
#define VAR_15 "/instrumentation/slip-skid-ball/indicated-slip-skid"
#define VAR_16 "/instrumentation/turn-indicator/indicated-turn-rate"
#define VAR_17 "/instrumentation/vertical-speed-indicator/indicated-speed-fpm"
#define VAR_18 "/controls/flight/aileron"
#define VAR_19 "/controls/flight/elevator"
#define VAR_20 "/controls/flight/rudder"
#define VAR_21 "/controls/flight/flaps"
#define VAR_22 "/controls/engines/engine/throttle"
#define VAR_23 "/engines/engine/rpm"
#define MAX_BIND_ENTRIES 23
#define SECOND_TIME_DATA 2


using namespace std;

class Server {
    int listenSocket;
    int clientSocket;
    unordered_map<string, double> myTable;
    string stringToParse;
    string getCompleteMessage();
    string getParam(string &);
    bool bReceivedDataFromServer;
    int numOfMessagesFromServer;
    string ArrBindAddresses[MAX_BIND_ENTRIES];
    mutex mtxForMyTable;

public:
    Server();
    bool continueThread = true;
    int getClientSocket();
    void parserOfVars(string);
    void createServer(double);

    Expression *getValueFromMap(string);
    ~Server();
};


#endif //UNTITLED_SERVER_H
