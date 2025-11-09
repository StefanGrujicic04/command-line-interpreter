//
// Created by Stefan Grujicic on 31. 7. 2025..
//

#ifndef COMMAND_LINE_INTERPRETER_TRCOMMAND_H
#define COMMAND_LINE_INTERPRETER_TRCOMMAND_H
#include "../../IOManager.h"
#include "../ApstractCommands/ArgumentedCommand.h"
#include <string>
#include <vector>
#include <sstream>
//changes "what" using "with" in [argument]
class TrCommand : public ArgumentedCommand {
    void execute( std::vector<std::string>& args,  std::vector<int>& positions)const override;
     void assignStrings(std::vector<std::string>& args, std::vector<int>& positions,std::string& argument,std::string& what,std::string& with)const;
    static std::string replaceAll( std::string& input,  std::string& from,  std::string& to);
};


#endif //COMMAND_LINE_INTERPRETER_TRCOMMAND_H
