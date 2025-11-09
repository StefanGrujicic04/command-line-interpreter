//
// Created by Stefan Grujicic on 28.1.25..
//

#include "PromptCommand.h"
void PromptCommand::execute( std::vector<std::string>& args,  std::vector<int>& positions)const {
    CommandLineInterpreter& CLI=CommandLineInterpreter::getCLI();
    std::string processing=args[0];

    IOManager& io=IOManager::getInstance();
    std::string fullLine=io.getCurrentLine();
    if(args.size()>1)  throw CommandExecutionException("Too much arguments in command:",fullLine,positions[1],args[1].size());

    if(processing[0]=='"')//strips "'s and changes prompt sign or send exception
    {
        processing.erase(processing.begin());
        if(processing.back()!='"')
        {
            //raise error!
            return;
        }
        processing.pop_back();
        CLI.setPromptSign(processing);
        return ;
    }
    else
    {
        throw CommandExecutionException("Argument is not in \" :", fullLine, positions[0], args[0].size());
    }
}