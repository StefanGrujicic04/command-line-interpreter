//
// Created by Stefan Grujicic on 3.12.24..
//

#ifndef COMMAND_LINE_INTERPRETER_COMMANDFACTORY_H
#define COMMAND_LINE_INTERPRETER_COMMANDFACTORY_H
#include "../Exeptions.h"
#include "../Commands/ApstractCommands/Command.h"
#include <unordered_map>
class CommandFactory {
public:


    // takes instance of CommandFactory
    static CommandFactory& getInstance();

    void registerCommand(std::string&& name, std::unique_ptr<Command> newCommand);//puts command in factory

    Command* getCommand(const std::string& name)const;// return pointer of command

private:
    std::unordered_map<std::string,std::unique_ptr<Command>> commandMap;

    //private constructor so factory would be singleton
    CommandFactory() = default;

    //disalows copying factory and it's operator
    CommandFactory(const CommandFactory&) = delete;
    CommandFactory& operator=(const CommandFactory&) = delete;
};


#endif //COMMAND_LINE_INTERPRETER_COMMANDFACTORY_H
