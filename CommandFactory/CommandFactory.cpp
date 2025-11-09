//
// Created by Stefan Grujicic on 3.12.24..
//

#include "CommandFactory.h"

void CommandFactory::registerCommand(std::string&& name, std::unique_ptr<Command> newCommand) {
    this->commandMap[name] =std::move( newCommand);//gives map a new command
}

Command* CommandFactory::getCommand(const std::string &name) const {
    auto it = commandMap.find(name);
    if (it != commandMap.end()) {
        return it->second.get(); // gets us a command we need
    }
    throw CommandNotFoundException("This command is not found in command factory: "+name);

}

CommandFactory &CommandFactory::getInstance() {
    static CommandFactory instance;
    return instance;//gives instance of Command Factory
}