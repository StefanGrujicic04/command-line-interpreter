//
// Created by Stefan Grujicic on 28.1.25..
//

#ifndef COMMAND_LINE_INTERPRETER_PROMPTCOMMAND_H
#define COMMAND_LINE_INTERPRETER_PROMPTCOMMAND_H
#include <iostream>
#include"../ApstractCommands/Command.h"
//changes prompt sigh
class PromptCommand : public Command {
    void execute( std::vector<std::string>& args,  std::vector<int>& positions)const override;
};


#endif //COMMAND_LINE_INTERPRETER_PROMPTCOMMAND_H
