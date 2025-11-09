//
// Created by Stefan Grujicic on 19.1.25..
//

#include "CommandLineInterpreter.h"

#include <utility>
//setter
void CommandLineInterpreter::setPromptSign(std::string s) {
    this->promptSign=std::move(s);
}//sets prompt

//getters
CommandLineInterpreter& CommandLineInterpreter::getCLI() {
    static CommandLineInterpreter instance;
    return instance;//gives instance for CLI
}
 std::string CommandLineInterpreter::getPromptSign() const {
    return promptSign;//returns prompt
}
