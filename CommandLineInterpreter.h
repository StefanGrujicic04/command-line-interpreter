//
// Created by Stefan Grujicic on 19.1.25..
//

#ifndef COMMAND_LINE_INTERPRETER_COMMANDLINEINTERPRETER_H
#define COMMAND_LINE_INTERPRETER_COMMANDLINEINTERPRETER_H

#include<iostream>
#include <fstream>
#include <memory>
#include<sstream>
class CommandLineInterpreter { //Prompt sign
public:

    //Instance for singleton CommandLineInterpreter
    static CommandLineInterpreter& getCLI();
    // getter
    [[nodiscard]] std::string getPromptSign() const;
protected:
    //setter
    void setPromptSign(std::string s);
    friend class PromptCommand;
private:
    std::string promptSign;

    // Private constructor (Singleton)
    CommandLineInterpreter()
            : promptSign("$"){}
};


#endif //COMMAND_LINE_INTERPRETER_COMMANDLINEINTERPRETER_H
