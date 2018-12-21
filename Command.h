
#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H

#include <array>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

class Command {
public:
    int virtual doCommand(vector<string>) {};
};


#endif //PROJECT_COMMAND_H
