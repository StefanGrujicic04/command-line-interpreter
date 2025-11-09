//
// Created by Stefan Grujicic on 3.12.24..
//

#include "ArgumentedCommand.h"
  std::string ArgumentedCommand::getArgument() { //take argument from console 
    std::string final;
    std::string token;
    IOManager& io=IOManager::getInstance();
    std::istream& input=io.getInput();
    while(std::getline(input,token))//take while dont get EOF
    {                                                      //char by char
        final+=token;
        final+="\n";
    }
    input.clear();
    final += '\n';
    if(!final.empty())
        final.erase(final.end()-1);
    return final;
}
 void ArgumentedCommand::proccesing(const std::vector<std::string>& args,std::string& output){
     IOManager& io = IOManager::getInstance();
    if(args.empty())    // ako je prazan uzimamo iz tastature elemente
    {
        output=getArgument();
    }
    else
    {
        /*  in case echo "da" | echo "ne" should result in error implement this!
        if (io.getIfOutputBufferEmpty())
        {
            throw FileIOException("Can't have argument while having text fowarded from pipe buffer");
        }
        */
        std::string argument=args[0];
        if(argument.length()>2&&argument[0]=='"')//if argument is in quotes then the should be removed
        {
            argument.erase(argument.begin());
            argument.pop_back();
            output=argument;
        }
        else// if not open file
        {
            std::ifstream file;
            file.open(argument);
            if(!file.is_open()) // error after not being able to open file
            {
                throw FileIOException("File with name: " +argument+ " does not exist");
            }
            else
            {

                std::string row;
                while(std::getline(file,row)) // takes line by line
                {
                    output+=row;
                    output+='\n';
                }
                file.close();
            }
        }
    }
}