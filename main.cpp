#include "CommandLineExecute.h"
int main() {
    Factory::factoryMaking(); // creation of command factory
    
    while(true){
        // creates instances for Input/Output manager and for prompt manager (CLI)
        IOManager& io = IOManager::getInstance();
        CommandLineInterpreter& CLI=CommandLineInterpreter::getCLI();
        std::string sigh=CLI.getPromptSign();
        std::cout<<sigh;
        std::string line;
        std::getline(io.getInput(),line);
        if(line=="exit")
            break;
        commandLineExecute(line); //function that executes exactily one line of commnads
    }
}
