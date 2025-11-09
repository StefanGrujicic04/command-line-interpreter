//
// Created by Stefan Grujicic on 3.12.24..
//

#include "WcCommand.h"
void WcCommand::execute( std::vector<std::string>& args,  std::vector<int>& positions)const {
    IOManager &io=IOManager::getInstance();
    std::ostream & output=io.getOutput();
    std::string argument;
    std::string fullLine=io.getCurrentLine();
    //handling all imminent errors
    if(args.size()>2)  throw CommandExecutionException("Too much arguments in command:",fullLine,positions[2],args[2].size());
    std::string opt=args[0];
    if(opt!="-w"&&opt!="-c")
    {
        throw CommandExecutionException("Command wc does not have option:"+opt,fullLine,positions[0],args[0].size());
    }

    args.erase(args.begin());
    positions.erase(positions.begin());

    proccesing(args,argument);//gets final string that wc will process

    int result;
    //decides in what mod wc will be working
    if(opt=="-w"){
        result= optionWord(argument);
    }
    else
    {
        result= optionChar(argument);
    }
    output<<result<<std::endl;
}
int WcCommand::optionWord(const std::string& output)const{

    bool haveChars=false;
    int result=0;
    for(auto c:output){
        if(c==' '||c=='\t'||c=='\n')//ignores spaces and looks for a word
        {
            if(haveChars)
            {
                result++;
                haveChars=false;
            }
        }
        else
        {
            haveChars=true;// remmebers that we seen char
        }
    }
    if(haveChars)
        result++;
    return result;
}
inline int WcCommand::optionChar(const std::string& output)const{
    return output.length();// returns length of a string
}

