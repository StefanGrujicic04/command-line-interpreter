//
// Created by Stefan Grujicic on 28.1.25..
//

#ifndef COMMAND_LINE_INTERPRETER_RMCOMMAND_H
#define COMMAND_LINE_INTERPRETER_RMCOMMAND_H
#include <iostream>
#include"../ApstractCommands/DeletingCommand.h"
#include <fstream>
//deletes file
class RmCommand:public DeletingCommand{
    void execute( std::vector<std::string>& args,  std::vector<int>& positions)const override;
};


#endif //COMMAND_LINE_INTERPRETER_RMCOMMAND_H
