//
// Created by Stefan Grujicic on 3.12.24..
//

#ifndef COMMAND_LINE_INTERPRETER_DATECOMMAND_H
#define COMMAND_LINE_INTERPRETER_DATECOMMAND_H
#include <iostream>
#include"../ApstractCommands/Command.h"
#include <chrono>
#include <iomanip>
#include <ctime>
//gives current time
class DateCommand:public Command {
public:
    void execute( std::vector<std::string>& args,  std::vector<int>& positions)const override;
};


#endif //COMMAND_LINE_INTERPRETER_DATECOMMAND_H
