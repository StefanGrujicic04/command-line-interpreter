//
// Created by Stefan Grujicic on 3.12.24..
//

#include "TimeCommand.h"
void TimeCommand::execute( std::vector<std::string>& args,  std::vector<int>& positions)const{
    IOManager &io=IOManager::getInstance();
    std::ostream & output=io.getOutput();

    std::string fullLine=io.getCurrentLine();
    if(!args.empty())  throw CommandExecutionException("Too much arguments in command:",fullLine,positions[0],args[0].size());
    // adds current time
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm tm_local{};                 // storage for result
    if (::localtime_s(&tm_local, &now_c) != 0) { //need for locacltime_s to be secure 
        throw CommandExecutionException("Failed to obtain local time.");
    }

    output << std::put_time(&tm_local, "%H:%M:%S") << '\n';//writes time on output
}