#include "Data.h"

/*
 * Function Name: Data
 * Input: SymbolTable*
 * Output:
 * Function Operation: Data constructor
 */
Data::Data(SymbolTable* table) {
    // create all the commands.
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
    // insert all the commands to the map.
    commandMap.insert(pair<string, CommandExpression *>("openDataServer", server));
    commandMap.insert(pair<string, CommandExpression *>("connect", connect));
    commandMap.insert(pair<string, CommandExpression *>("var", define));
    commandMap.insert(pair<string, CommandExpression *>("while", loop));
    commandMap.insert(pair<string, CommandExpression *>("if", ifCondition));
    commandMap.insert(pair<string, CommandExpression *>("print", print));
    commandMap.insert(pair<string, CommandExpression *>("sleep", sleep));
    commandMap.insert(pair<string, CommandExpression *>("=", assign));

    // set the map and table to the commands that use it
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

/*
 * Function Name: Data
 * Input:
 * Output:
 * Function Operation: Data destructor
 */
Data::~Data() {
    if (server) {
        delete server;
    }
    if (connect) {
        delete connect;
    }
    if (define) {
        delete define;
    }
    if (loop) {
        delete loop;
    }
    if (ifCondition) {
        delete ifCondition;
    }
    if (print) {
        delete print;
    }
    if (sleep) {
        delete sleep;
    }
    if (assign) {
        delete assign;
    }
    if (defineC) {
        delete defineC;
    }
    if (printC) {
        delete printC;
    }
    if (sleepC) {
        delete sleepC;
    }
    if (assignC) {
        delete assignC;
    }
    if (loopC) {
        delete loopC;
    }
    if (ifConditionC) {
        delete ifConditionC;
    }
    if (serverC) {
        delete serverC;
    }
    if (connectC) {
        delete connectC;
    }
    if (commandMap.size() != 0) {
        commandMap.clear();
    }
}