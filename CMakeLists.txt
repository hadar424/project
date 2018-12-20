cmake_minimum_required(VERSION 3.12)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled main.cpp Expression.h BinaryExpression.cpp BinaryExpression.h Number.cpp Number.h Plus.cpp Plus.h Minus.cpp Minus.h Mul.cpp Mul.h Div.cpp Div.h CalculateExpression.cpp CalculateExpression.h Neg.cpp Neg.h UnaryExpression.cpp UnaryExpression.h OpenServerCommand.cpp OpenServerCommand.h Command.h Parser.cpp Parser.h ConnectCommand.cpp ConnectCommand.h Lexer.cpp Lexer.h ConditionParser.cpp ConditionParser.h SymbolTable.cpp SymbolTable.h DefineVarCommand.cpp DefineVarCommand.h test.txt test2.txt Data.h LoopCondition.cpp LoopCondition.h)
