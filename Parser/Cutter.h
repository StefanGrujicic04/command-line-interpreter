//
// Created by Stefan Grujicic on 28.1.25..
//

#ifndef COMMAND_LINE_INTERPRETER_CUTTER_H
#define COMMAND_LINE_INTERPRETER_CUTTER_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "../IOManager.h"
#define MAX_LINE_LENGTH 512
//cuts down one line to commands 
class Cutter {
public:
	static void cutter(std::string& line, std::vector<std::string>& commands);
};

#endif //COMMAND_LINE_INTERPRETER_CUTTER_H
