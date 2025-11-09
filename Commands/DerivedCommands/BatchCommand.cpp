//
// Created by Stefan Grujicic on 31. 7. 2025..
//

#include "BatchCommand.h"
#include<sstream>

void BatchCommand::execute( std::vector<std::string>& args,  std::vector<int>& positions)const {
    IOManager& io=IOManager::getInstance();
    std::string fullLine=io.getCurrentLine();
    if(args.size()>1){throw CommandExecutionException("Too much arguments in command:",fullLine,positions[1],args[1].size());}
    std::string argument;
    proccesing(args, argument);
    std::string line;
    std::stringstream buffer(argument);
    //executes all given commands
    while(std::getline(buffer,line))
        commandLineExecute(line);
}
