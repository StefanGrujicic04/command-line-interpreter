//
// Created by Stefan Grujicic on 3.12.24..
//

#ifndef COMMAND_LINE_INTERPRETER_WCCOMMAND_H
#define COMMAND_LINE_INTERPRETER_WCCOMMAND_H
#include <iostream>
#include"../ApstractCommands/ArgumentedCommand.h"
//count words or chars in given argument
class WcCommand:public ArgumentedCommand{
    void execute( std::vector<std::string>& args,  std::vector<int>& positions)const override;
    //all options
    int optionChar(const std::string& output)const;
    int optionWord(const std::string& output)const;
};


#endif //COMMAND_LINE_INTERPRETER_WCCOMMAND_H
