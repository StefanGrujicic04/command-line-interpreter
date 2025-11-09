//
// Created by Stefan Grujicic on 3.12.24..
//

#ifndef COMMAND_LINE_INTERPRETER_TIMECOMMAND_H
#define COMMAND_LINE_INTERPRETER_TIMECOMMAND_H
#include <iostream>
#include"../ApstractCommands/Command.h"
#include <chrono>
#include <iomanip>
#include <ctime>
#include "../../IOManager.h"
//gives us curent time 
class TimeCommand:public Command {
public:
    void execute( std::vector<std::string>& args,  std::vector<int>& positions)const override;

};


#endif //COMMAND_LINE_INTERPRETER_TIMECOMMAND_H
