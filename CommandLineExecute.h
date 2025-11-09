//
// Created by Stefan Grujicic on 29. 7. 2025..
//

#ifndef COMMAND_LINE_INTERPRETER_COMMANDLINEEXECUTE_H
#define COMMAND_LINE_INTERPRETER_COMMANDLINEEXECUTE_H
#include <iostream>
#include "CommandFactory/Factory.h"

//function that executes exactily one line of commnads

static void commandLineExecute(std::string line)
{
    IOManager &io = IOManager::getInstance();
    try {
        
        std::istream &input = io.getInput();
        io.setCurrentLine(line);
        CommandFactory &myFactory = CommandFactory::getInstance();
       // taking IOManager singleton and all his atributes that will be used in this function
        std::vector<std::string> args;
        std::vector<int> positions;
        std::vector<std::string> commands;
        //preparing vectors for arguments and places where they begin for better Exeptions handling

        Cutter::cutter(line, commands);//cutter cuts down one line in case of a pipe
        for (int i = 0; i < commands.size(); i++) {
            auto &command = commands[i];
            
            Parser::parse(command, args,positions);//parse one command 

            Parser::redirectionHandler(args,positions ,i, commands.size());//handles redirections before executing that command

            if (args.empty()){ throw LexicalException("Empty command");}

            Command *tmpCommand = myFactory.getCommand(args[0]);
            args.erase(args.begin());
            positions.erase(positions.begin());

            tmpCommand->execute(args,positions);

            args.clear();
            input.clear();
            
            if (io.getInPipe() && i != commands.size() - 1) {// updating the state of the pipe
                io.moveOutputToInput();
            }
        }
        if (io.getInPipe())//closing pipe if open
            io.disablePipe();
        io.setDefaultStreams();
    }
    catch (const BaseException& e) {
        //writing exeption and return everything in it's starting position
        std::cout << e.what() << std::endl;
        if (io.getInPipe())
            io.disablePipe();
        io.setDefaultStreams();
    }
}

#endif //COMMAND_LINE_INTERPRETER_COMMANDLINEEXECUTE_H
