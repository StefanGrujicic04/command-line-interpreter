//
// Created by Stefan Grujicic on 3.12.24..
//

#include "DateCommand.h"
 void DateCommand::execute( std::vector<std::string>& args,  std::vector<int>& positions)const {
    IOManager &io=IOManager::getInstance();
     std::ostream & output=io.getOutput();
     std::string fullLine=io.getCurrentLine();
     if(!args.empty())  throw CommandExecutionException("Too much arguments in command:",fullLine,positions[0],args[0].size());
     //we get time here
     auto now = std::chrono::system_clock::now();
     std::time_t now_c = std::chrono::system_clock::to_time_t(now);

     std::tm tm_local{};
     #if defined(_WIN32) || defined(_MSC_VER)//so it can work on both windows and mac 
        ::localtime_s(&tm_local, &now_c);
     #else
        localtime_r(&now_c, &tm_local);
     #endif
     output << std::put_time(&tm_local, "%d-%m-%Y") << '\n';
 }