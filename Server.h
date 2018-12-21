//
// Created by sharon on 21/12/18.
//

#ifndef UNTITLED_SERVER_H
#define UNTITLED_SERVER_H

#include <pthread.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "SymbolTable.h"
#include <string.h>

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
#define VAR_13 "/instrumentation/heading-indicator/indicated-heading-deg"
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


using namespace std;

class Server {
    int listenSocket;
    int clientSocket;
    unordered_map<string, double> myTable;
    string restString = "";

public:
    Server(double);

    void initializeMap() {
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
    };
    int getClientSocket();
    void ParserOfVars(string);
};


#endif //UNTITLED_SERVER_H
