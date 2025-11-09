//
// Created by Stefan Grujicic on 31. 7. 2025..
//

#ifndef COMMAND_LINE_INTERPRETER_BATCHCOMMAND_H
#define COMMAND_LINE_INTERPRETER_BATCHCOMMAND_H
#include <iostream>
#include"../ApstractCommands/ArgumentedCommand.h"
#include "../../CommandLineExecute.h"
//executes all given commands
class BatchCommand: public ArgumentedCommand{
    void execute( std::vector<std::string>& args,  std::vector<int>& positions)const override;

};


#endif //COMMAND_LINE_INTERPRETER_BATCHCOMMAND_H
