//
// Created by Stefan Grujicic on 31. 7. 2025..
//

#ifndef COMMAND_LINE_INTERPRETER_HEADCOMMAND_H
#define COMMAND_LINE_INTERPRETER_HEADCOMMAND_H
#include "../ApstractCommands/ArgumentedCommand.h"
#include "../../IOManager.h"
#include <string>
//writes down n lines and ignores the rest
class HeadCommand: public ArgumentedCommand{
    void execute( std::vector<std::string>& args,  std::vector<int>& positions)const override;

};


#endif //COMMAND_LINE_INTERPRETER_HEADCOMMAND_H
