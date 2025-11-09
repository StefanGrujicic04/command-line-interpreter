//
// Created by Stefan Grujicic on 3.12.24..
//

#ifndef COMMAND_LINE_INTERPRETER_ARGUMENTEDCOMMAND_H
#define COMMAND_LINE_INTERPRETER_ARGUMENTEDCOMMAND_H
#include <iostream>
#include <fstream>
#include"Command.h"
class ArgumentedCommand:public Command {
public:
    //fuction takes argument by output when he doesn't get it by line
    static std::string getArgument() ;
    //procceses our input and create what is meant to be used by functions
    static void proccesing(const std::vector<std::string>& args,std::string& output);
};


#endif //COMMAND_LINE_INTERPRETER_ARGUMENTEDCOMMAND_H
