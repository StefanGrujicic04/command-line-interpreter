//
// Created by Stefan Grujicic on 31. 7. 2025..
//

#include "TrCommand.h"
std::string TrCommand::replaceAll( std::string& input,  std::string& what,  std::string& with) {
    if (what.empty()) return input; // defence from infinte loop

    std::string result = input;
    int pos = 0;
    while ((pos = result.find(what, pos)) != std::string::npos) {
        result.replace(pos, what.length(), with);
        pos += with.length(); // moves after inplanting new text
    }
    return result;
}
void TrCommand::assignStrings(std::vector<std::string> &args, std::vector<int>& positions ,std::string &argument, std::string &what,std::string& with) const {
    IOManager& io = IOManager::getInstance();
    std::string fullLine=io.getCurrentLine();
    //looks for cases since tr can have different number of arguments
    if(args.size()==3&&io.getInPipe()&& !io.getIfOutputBufferEmpty())
    {
        throw StreamConflictException("Command Tr can't have argument in pipe.");
    }
    if(args.size()==2&&args[0][0]!='"')
    {
        
        if (args[1].size() >= 2 && args[1].front() == '"' && args[1].back() == '"') {
            args[1] = args[1].substr(1, args[1].size() - 2);
        } else {
            throw CommandExecutionException("Command Tr cant have elements be files beside it's first argument: ",fullLine,positions[1],args[1].size());
        }
    }
    else
    {
        int i=args.size()==3? 1:0;//if there are three arguments, it is not necessary to check whether [argument] is enclosed in quotes or not
        for(;i<args.size();i++) {
            if (args[i].size() >= 2 && args[i].front() == '"' && args[i].back() == '"') {
                args[i] = args[i].substr(1, args[i].size() - 2); 
            } else {
                throw CommandExecutionException("Command Tr cant have elements be files beside it's first argument: ",fullLine,positions[1],args[1].size());
            }
        }
    }
    //gives what with and argument their's values and calls for proccesing
    if(args.size()==1){ //only what is given with is blank
        what=args[0];
        args.erase(args.begin());
        with="";
    }
    else if(args.size()==2)//in case number of arguments is two we say one is what and other with , where argument we get by processign
    {
        what=args[0];
        with=args[1];

        args.erase(args.begin());
        positions.erase(positions.begin());
        args.erase(args.begin());
        positions.erase(positions.begin());
    }
    else if(args.size()==3)//we are being given all three arguments in command 
    {

        what=args[1];
        with=args[2];
        args.erase(args.begin()+1);
        positions.erase(positions.begin()+1);

    }
    proccesing(args,argument);
}
void TrCommand::execute( std::vector<std::string>& args,  std::vector<int>& positions)const{
    IOManager& io = IOManager::getInstance();

    // Validacija broja argumenata (tr [arg] what [with])
    if (args.empty() || args.size() > 3) {
        throw CommandExecutionException("Command Tr must have atleast one argument and maximum 3 argumnets. ");
    }
    std::string what,with,argument;
    assignStrings(args,positions,argument,what,with);

    // replace what and with
    std::string result;
    result= replaceAll(argument,what,with);
    io.getOutput() << result;//gives output
}