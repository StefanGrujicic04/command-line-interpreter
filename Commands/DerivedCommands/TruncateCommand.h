//
// Created by Stefan Grujicic on 28.1.25..
//

#ifndef COMMAND_LINE_INTERPRETER_TRUNCATECOMMAND_H
#define COMMAND_LINE_INTERPRETER_TRUNCATECOMMAND_H
#include <iostream>
#include"../ApstractCommands/DeletingCommand.h"
#include <fstream>
//deletes text from file
class TruncateCommand: public DeletingCommand{
    void execute( std::vector<std::string>& args,  std::vector<int>& positions)const override;

};


#endif //COMMAND_LINE_INTERPRETER_TRUNCATECOMMAND_H
