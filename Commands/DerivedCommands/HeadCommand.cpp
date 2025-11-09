//
// Created by Stefan Grujicic on 31. 7. 2025..
//

#include "HeadCommand.h"
#include "sstream"
void HeadCommand::execute(std::vector<std::string> &args,  std::vector<int>& positions) const {
    std::string content;
    IOManager& io=IOManager::getInstance();
    std::string fullLine=io.getCurrentLine();
    //writes n line of text and ignores rest
    if(args.empty())  throw CommandExecutionException("Didn't specify number of line for Head command"+fullLine);

    if(args.size()>2)  throw CommandExecutionException("Too much arguments in command:",fullLine,positions[2],args[2].size());

    args[0].erase(0,2);
    int n=std::stoi(args[0]);

    args.erase(args.begin());
    positions.erase(positions.begin());

    proccesing(args,content);

    std::stringstream buffer(content);//trasfers to buffer string that need to be cut down
    std::ostream& output=io.getOutput();
    std::string line;
    for(int i=0;i<n;i++)
    {
        std::getline(buffer,line);
        output<<line;
        if (!line.empty() && line.back() != '\n') {
            output << '\n';
        }
    }
}