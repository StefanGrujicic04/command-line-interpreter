//
// Created by Stefan Grujicic on 3.12.24..
//

#include "TouchCommand.h"

void TouchCommand::execute( std::vector<std::string>& args,  std::vector<int>& positions)const{
    //creates new file but only if file with that name doesn't already exists
    IOManager& io=IOManager::getInstance();
    std::string fullLine=io.getCurrentLine();
    if(args.size()>1)  throw CommandExecutionException("Too much arguments in command:",fullLine,positions[1],args[1].size());

    std::string name;
    name=args[0];
    if (std::filesystem::exists(name)) {
        throw FileIOException("File with name: " + name + " already exist.\n");

    }
    std::ofstream file(name);

    if (!file) {
        throw FileIOException("There was an error with creating a new file, please try again");
    }
    file.close();
}