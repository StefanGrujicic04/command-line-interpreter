
// Created by Stefan Grujicic on 3.12.24..
//

#include "EchoCommand.h"
void EchoCommand::execute( std::vector<std::string>& args,  std::vector<int>& positions)const {
    std::string argument;
    IOManager &io=IOManager::getInstance();

    std::ostream & output=io.getOutput();

    std::string fullLine=io.getCurrentLine();
    if(args.size()>1)  throw CommandExecutionException("Too much arguments in command:",fullLine,positions[1],args[1].size());

    proccesing(args,argument);// process argument and gives us what we need to write down
    output<<argument;
    if (!argument.empty() && argument.back() != '\n') {
        output << '\n';
    }
}