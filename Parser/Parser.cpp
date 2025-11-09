#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Parser.h"
#include "../IOManager.h"
#include "../Exeptions.h"
#include"Parser.h"
//part for Parser
void Parser::extractToken(std::string& token, int posStart, int& lastPos,std::vector<std::string>& arg, std::vector<int>& position) {//take all chars from token creates string and remmembers position
    if (!token.empty()) {
        arg.push_back(token);
        position.push_back(posStart);
        token.clear();
        lastPos = posStart;
    }
}
void Parser::validatePostQuote(const std::string& line, int i) {//looks if argument have any char that is glued to "
    if (line.size() > i + 1 && !isspace(line[i + 1])) {
        int j = i + 1;
        while (j < line.size() && !isspace(line[j])) ++j;
        throw LexicalException("Unexpected characters after closing quote:", line, i + 1, j - i - 1);
    }
} 
void Parser::parse(std::string& line, std::vector<std::string>& arg, std::vector<int>& position) {
    std::string token;
    bool insideQuotes = false;
    int i = -1;
    int posStart = 0;

    for (char c : line) {//looks char by char
        i++;
        if (c == '"') {
            if (!insideQuotes) {//if not in quotes and find " and token is empty push in token otherwise error
                if (token.empty()) {
                    insideQuotes = true;
                    token += c;
                    posStart = i;
                }
                else {
                    throw LexicalException("Signs right before \": ", line, i - token.size(), token.size());
                }
            }
            else {
                validatePostQuote(line, i);//end of a argument  extract token
                token += c;
                extractToken(token, posStart, posStart, arg, position);
                insideQuotes = false;
            }
        }
        else if (isspace(c)) {//resolves if char is space 
            if (!insideQuotes) {
                extractToken(token, posStart, posStart, arg, position);
            }
            else {
                token += c;
            }
        }
        else {//if char is anything else
            if (token.empty()) posStart = i;
            token += c;
        }
    }

    if (!token.empty()) {
        if (insideQuotes) {
            throw LexicalException("Unclosed quote detected:", line, i - token.size() + 1, token.size());
        }
        else {
            extractToken(token, posStart, posStart, arg, position);//takes what's left
        }
    }
}
//part for redirection handler

void Parser::validateRedirectionInPipe(const std::vector<std::string>& args, std::vector<int>& position, int commandIndex, int totalCommands) {
    IOManager& io = IOManager::getInstance();
    if(totalCommands==1)//looks if all redirections have right to exists 
    for (int i = 0; i < args.size(); i++) {
        const std::string& tok = args[i];
        if (tok.empty()) continue;

        const char r = tok[0];
        if (r != '<' && r != '>') continue;

        const int pos = (i < position.size() ? position[i] : 0);
        const int len = static_cast<int>(tok.size());
        if (commandIndex != 0 && commandIndex != totalCommands - 1) {
            throw StreamConflictException(
                "Can't have redirection in the middle of a pipe: " + tok,io.getCurrentLine(), pos, len );
        }
        if (commandIndex == 0 && r == '>') {
            throw StreamConflictException(
                "Output redirection '>' is not allowed on the first command of a pipe.",io.getCurrentLine(), pos, len );
        }
        if (commandIndex == totalCommands - 1 && r == '<') {
            throw StreamConflictException("Input redirection '<' is not allowed on the last command of a pipe.",io.getCurrentLine(), pos, len);
        }
    }
}

void Parser::redirectionHandler(std::vector<std::string>& args, std::vector<int>& position, int currentInPipeCommand, int allPipeCommand) { 
    IOManager& io = IOManager::getInstance();
    if(io.getInPipe())
        validateRedirectionInPipe(args, position, currentInPipeCommand, allPipeCommand);
    for (int i = 0; i < args.size();) {
        const std::string& tok = args[i];
        if (tok.empty()) { i++; continue; }

        if (tok[0] == '>' || tok[0] == '<') {//looks for what kind of redirection it is if there is redirection
            const bool isOutput = (tok[0] == '>');
            const bool isAppend = (isOutput && tok.size() >= 2 && tok[1] == '>');
            const int opLen = isAppend ? 2 : 1;

            std::string filename;

            if (tok.size() > opLen) {
                
                filename = tok.substr(opLen);
            }
            else {
                if (i + 1 >= args.size()) {//looks for filename
                    int pos = (i < position.size() ? position[i] : 0);
                    int len = (int)tok.size();
                    throw StreamConflictException("Redirection operator without filename",io.getCurrentLine(), pos, len);}
                filename = args[i + 1];
                if (filename.empty()) {
                    int pos = (i + 1 < position.size() ? position[i + 1]
                        : (i < position.size() ? position[i] : 0));
                    throw StreamConflictException("Empty filename after redirection",io.getCurrentLine(), pos,filename.size());
                }
            }

            if (isOutput) {//looks wether it is > or >>
                if (isAppend) io.setOutputForExisting(filename);
                else          io.setOutput(filename);
            }
            else {
                io.setInput(filename);
            }

            if (tok.size() > opLen) {// resizing of argument and position after deleting them from argument 
                args.erase(args.begin() + i);
                if (i < position.size()) position.erase(position.begin() + i);
            }
            else {
                
                args.erase(args.begin() + i);
                if (i < position.size()) position.erase(position.begin() + i); 
                
                args.erase(args.begin() + i);
                if (i < position.size()) position.erase(position.begin() + i);
            }

            continue;
        }

        i++; 
    }
}
