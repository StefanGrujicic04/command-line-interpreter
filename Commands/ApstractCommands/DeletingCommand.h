//
// Created by Stefan Grujicic on 28.1.25..
//

#ifndef COMMAND_LINE_INTERPRETER_DELETINGCOMMAND_H
#define COMMAND_LINE_INTERPRETER_DELETINGCOMMAND_H
#include <iostream>
#include <fstream>
#include"Command.h"
//just have ability to deletes file, every file that can delete goes throw him
class DeletingCommand: public Command{
public:
    void deleteFile(std::string& filename)const;
};


#endif //COMMAND_LINE_INTERPRETER_DELETINGCOMMAND_H
