#include "Data.h"

Data::Data(SymbolTable* table) {
    myTable = table;
    commandMap.insert(pair<string, CommandExpression *>("openDataServer", server));
    commandMap.insert(pair<string, CommandExpression *>("connect", connect));
    commandMap.insert(pair<string, CommandExpression *>("var", define));
    commandMap.insert(pair<string, CommandExpression *>("while", loop));
    commandMap.insert(pair<string, CommandExpression *>("if", ifCondition));
    commandMap.insert(pair<string, CommandExpression *>("print", print));
    commandMap.insert(pair<string, CommandExpression *>("sleep", sleep));
    commandMap.insert(pair<string, CommandExpression *>("=", assign));
    defineC->setSymbolTable(myTable);
    conditionC->setSymbolTable(myTable);
    conditionC->setCommandMap(commandMap);
    printC->setSymbolTable(myTable);
    sleepC->setSymbolTable(myTable);
    assignC->setSymbolTable(myTable);
    assignC->setServer(serverC->getServer());
    assignC->setClient(connectC->getClient());
}

unordered_map<string,CommandExpression*> Data::getMap() {
    return commandMap;
}

Data::~Data() {
    delete myTable;
    delete server;
    delete connect;
    delete define;
    delete conditionC;
    delete loop;
    delete ifCondition;
    delete print;
    delete sleep;
    delete assign;
    delete serverC;
    delete connectC;
    delete defineC;
    delete printC;
    delete sleepC;
    delete assignC;
    delete loopC;
    delete ifConditionC;
}