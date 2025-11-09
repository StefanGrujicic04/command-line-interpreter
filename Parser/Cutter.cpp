#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "../IOManager.h"
#include"Cutter.h"
#include"../Exeptions.h"

void Cutter::cutter(std::string& line, std::vector<std::string>& commands) {
    IOManager& io = IOManager::getInstance();

    if (line.length() > MAX_LINE_LENGTH) {
        line.resize(MAX_LINE_LENGTH);
    }//resize line if to long
    std::vector<std::string> result;
    std::stringstream strings(line);
    std::string token;
    bool insideQuotes = false;
    int i = -1;
    for (auto c : line)//cuts down line in commands if this is pipe
    {
        i++;
        if (c == '"')
        {
            insideQuotes = !insideQuotes;
            token += c;
        }
        else if (c == '|' && !insideQuotes)
        {
            if (token.empty()) { throw LexicalException("Empty command between pipes", line, i, 1); }
            commands.push_back(token);
            token.clear();
        }
        else
        {
            token += c;
        }
    }
    if (!token.empty())
    {
        commands.push_back(token);
    }
    if (commands.size() > 1)//turn pipe on
        io.enablePipe();
}