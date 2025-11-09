//
// Created by Stefan Grujicic on 28.1.25..
//

#include "RmCommand.h"
#include <filesystem>
void RmCommand::execute( std::vector<std::string>& args,  std::vector<int>& positions)const{
    IOManager& io=IOManager::getInstance();
    std::string fullLine=io.getCurrentLine();
    if(args.size()>1)  throw CommandExecutionException("Too much arguments in command:",fullLine,positions[1],args[1].size());

    DeletingCommand::deleteFile(args[0]);
}

