//
// Created by Stefan Grujicic on 3.12.24..
//

#ifndef COMMAND_LINE_INTERPRETER_TOUCHCOMMAND_H
#define COMMAND_LINE_INTERPRETER_TOUCHCOMMAND_H
#include <iostream>
#include"../ApstractCommands/Command.h"
#include <fstream>
#include <string>
#include <filesystem>
//creates text file
class TouchCommand:public Command {
    void execute( std::vector<std::string>& args,  std::vector<int>& positions)const override;

};


#endif //COMMAND_LINE_INTERPRETER_TOUCHCOMMAND_H
