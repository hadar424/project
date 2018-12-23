
#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H

#include <string>
#include <vector>

using namespace std;

class Command{
public:
    int virtual doCommand(vector<string>) {};
};


#endif //PROJECT_COMMAND_H
