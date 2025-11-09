//
// Created by Stefan Grujicic on 28.1.25..
//

#include "TruncateCommand.h"
void TruncateCommand::execute( std::vector<std::string>& args,  std::vector<int>& positions)const {
    //first deletes and than creates new file effectivly deleting it's content
    IOManager& io = IOManager::getInstance();
    std::string fullLine=io.getCurrentLine();
    if(args.size()>1)  throw CommandExecutionException("Too much arguments in command:",fullLine,positions[1],args[1].size());

    DeletingCommand::deleteFile(args[0]);

    std::ofstream file(args[0]);
    if (!file) {
        throw BaseException("There was an error while creating a new file, please try again.");

    }
    file.close();

}
