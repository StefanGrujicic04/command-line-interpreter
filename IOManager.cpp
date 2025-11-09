//
// Created by Stefan Grujicic on 30. 7. 2025..
//

#include "IOManager.h"
#include "Exeptions.h"
std::istream& IOManager::getInput() {
    if (inPipe&& !inputBuffer.str().empty())
        return inputBuffer;  
    else if (input)
        return *input;
    else
        return std::cin;
}
std::ostream& IOManager::getOutput() { //returning output
    if(inPipe)
    {
        return outputBuffer;// because of converstion from const stringstream to ostream
    }                       //this getter can't be const
    else
    {
        if(output)
            return *output;
        else
            return std::cout;
    }
}
void IOManager::setInput(std::unique_ptr<std::istream> in) {//sets input if given istream pointer
    input = std::move(in);
}
void IOManager::setInput(std::string& name) {//sets input by name
    input= nullptr;
    auto file = std::make_unique<std::ifstream>(name);
    if (!file->is_open()) {
        throw FileIOException("There was an error with creating a new file, please try again");
        return;
    }
    setInput(std::move(file));
}

void IOManager::setOutput(std::unique_ptr<std::ostream> outputNode) {//set output by ostream 
    output=std::move(outputNode);
}
void IOManager::setOutput(std::string& name) {//set input by name
    output= nullptr;
    auto file = std::make_unique<std::ofstream>(name);
    if (!file->is_open()) {
        throw FileIOException("There was an error with creating a new file, please try again");
        
    }
    output =std::move(file);
}
void IOManager::setOutputForExisting(std::string& name){//set output by name by opening file that already exists and writes at end of it
    output= nullptr;
    auto file=std::make_unique<std::ofstream>(name, std::ios::app);
    if (!file->is_open()) {
        throw FileIOException("There was an error with creating a new file, please try again");
       
    }
    output=std::move(file);
}
bool IOManager::getIfOutputBufferEmpty() {//gives you wether or not buffer has elements
    return outputBuffer.str().empty();
}

void IOManager::setDefaultStreams() {// return IOManager to starting state
    output= nullptr;
    input= nullptr;
}
void IOManager::enablePipe() {
    inPipe = true;
    outputBuffer.str("");  // deletes anything before
    outputBuffer.clear();
}
void IOManager::disablePipe() {// disable pipe and write anything that is left in buffer

    inPipe = false;
    std::ostream& output = getOutput();
    if (!getIfOutputBufferEmpty())
    {
        output << outputBuffer.str();
    }
    inputBuffer.str("");
    inputBuffer.clear();
    outputBuffer.str("");
    outputBuffer.clear();
}
void IOManager::moveOutputToInput() {//continues in pipe
    std::string data = outputBuffer.str();
    outputBuffer.str("");
    outputBuffer.clear();

    inputBuffer.str(data);
    inputBuffer.clear(); // preparation for reading

    input = nullptr; //sets input to cin
}
IOManager& IOManager::getInstance() {//return instance of singleton
    static IOManager instance;
    return instance;
}
void IOManager::setCurrentLine(const std::string& line){
    currentLine=line;//remmembers full line
}
