//
// Created by Stefan Grujicic on 3.12.24..
//

#ifndef COMMAND_LINE_INTERPRETER_ECHOCOMMAND_H
#define COMMAND_LINE_INTERPRETER_ECHOCOMMAND_H
#include <iostream>
#include"../ApstractCommands/ArgumentedCommand.h"
//writes down what is given to him
class EchoCommand: public ArgumentedCommand {
public:
    void execute( std::vector<std::string>& args,  std::vector<int>& positions)const override;
};

#endif //COMMAND_LINE_INTERPRETER_ECHOCOMMAND_H
