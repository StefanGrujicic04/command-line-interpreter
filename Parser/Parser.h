//
// Created by Stefan Grujicic on 25.11.24..
//
#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Parser.h"
#include "../IOManager.h"
#include "../Exeptions.h"
class Parser {
public:
    static void validatePostQuote(const std::string& line, int i);//tell us if argument with " doesnt have any unforseen characters before and after "
    static void extractToken(std::string& token, int posStart, int& lastPos,std::vector<std::string>& arg, std::vector<int>& position);//puts token in arguments
    static void parse(std::string& line, std::vector<std::string>& arg, std::vector<int>& position);//parses command
    static void validateRedirectionInPipe(const std::vector<std::string>& args, std::vector<int>& position, int commandIndex, int totalCommands);//tell us wether or not redirection is valid
    static void redirectionHandler(std::vector<std::string>& args, std::vector<int>& position, int currentInPipeCommand, int allPipeCommand);//updates I/O stream if redirection is valid

};

#endif