#include "Data.h"

Data::Data(SymbolTable* table) {
    assignC = new AssignCommand();
    defineC = new DefineVarCommand();
    printC = new PrintCommand();
    sleepC = new SleepCommand();
    connectC = new ConnectCommand();
    loopC = new LoopCondition();
    ifConditionC = new IfCondition();
    serverC = new OpenServerCommand();
    server = new CommandExpression(serverC);
    connect = new CommandExpression(connectC);
    define = new CommandExpression(defineC);
    loop = new CommandExpression(loopC);
    ifCondition = new CommandExpression(ifConditionC);
    print = new CommandExpression(printC);
    sleep = new CommandExpression(sleepC);
    assign = new CommandExpression(assignC);

    myTable = table;
    commandMap.insert(pair<string, CommandExpression *>("openDataServer", server));
    commandMap.insert(pair<string, CommandExpression *>("connect", connect));
    commandMap.insert(pair<string, CommandExpression *>("var", define));
    commandMap.insert(pair<string, CommandExpression *>("while", loop));
    commandMap.insert(pair<string, CommandExpression *>("if", ifCondition));
    commandMap.insert(pair<string, CommandExpression *>("print", print));
    commandMap.insert(pair<string, CommandExpression *>("sleep", sleep));
    commandMap.insert(pair<string, CommandExpression *>("=", assign));
    myTable->setServer(serverC->getServer());
    defineC->setSymbolTable(myTable);
    loopC->setSymbolTable(myTable);
    loopC->setCommandMap(commandMap);
    ifConditionC->setSymbolTable(myTable);
    ifConditionC->setCommandMap(commandMap);
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
    delete server;
    delete connect;
    delete define;
    delete loop;
    delete ifCondition;
    delete print;
    delete sleep;
    delete assign;
    delete defineC;
    delete printC;
    delete sleepC;
    delete assignC;
    delete loopC;
    delete ifConditionC;
}