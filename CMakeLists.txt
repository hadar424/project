cmake_minimum_required(VERSION 3.12)
project(untitled)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(untitled main.cpp Expression.h BinaryExpression.cpp BinaryExpression.h Number.cpp Number.h Plus.cpp Plus.h Minus.cpp Minus.h Mul.cpp Mul.h Div.cpp Div.h CalculateExpression.cpp CalculateExpression.h Neg.cpp Neg.h UnaryExpression.cpp UnaryExpression.h OpenServerCommand.cpp OpenServerCommand.h Command.h MyParser.cpp MyParser.h ConnectCommand.cpp ConnectCommand.h Lexer.cpp Lexer.h ConditionParser.cpp ConditionParser.h SymbolTable.cpp SymbolTable.h DefineVarCommand.cpp DefineVarCommand.h test.txt test2.txt Data.h LoopCondition.cpp LoopCondition.h Server.cpp Server.h PrintCommand.cpp PrintCommand.h IfCondition.cpp IfCondition.h SleepCommand.cpp SleepCommand.h Client.cpp Client.h MakeItDouble.cpp MakeItDouble.h AssignCommand.cpp AssignCommand.h CommandExpression.cpp CommandExpression.h Data.cpp Data.h)
