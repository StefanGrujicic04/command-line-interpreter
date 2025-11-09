//
// Created by Stefan Grujicic on 30. 7. 2025..
//

#ifndef COMMAND_LINE_INTERPRETER_IOMANAGER_H
#define COMMAND_LINE_INTERPRETER_IOMANAGER_H
#include<iostream>
#include <fstream>
#include <memory>
#include<sstream>
class IOManager {
public:
    //getters
    static IOManager& getInstance(); // Singleton access point
    std::istream& getInput();//gives reference of input
    std::ostream& getOutput();//gives reference of output
    bool getInPipe()const {return inPipe;}//gets iformation wether of not we are in pipe
    bool getIfOutputBufferEmpty();//gets wether or not buffer has some characters in it

    //setters
    void setInput(std::unique_ptr<std::istream>);//sets input to istream
    void setInput(std::string& name);// helper
    void setOutput(std::unique_ptr<std::ostream>);//sets output to ostream
    void setOutput(std::string& name); //helper
    void setOutputForExisting(std::string& name);//sets iutput to end of the ostream

    void setDefaultStreams(); // vraca na cin/cout
    void enablePipe();//enable pipe
    void disablePipe();//disables pipe and outputs whats left from buffer
    void moveOutputToInput(); // koristiš stringstream

    void setCurrentLine(const std::string& line);
    const std::string& getCurrentLine() const{return currentLine;}
private:
    std::string currentLine;
    IOManager() = default;
    IOManager(const IOManager&) = delete;
    IOManager& operator=(const IOManager&) = delete;

    std::unique_ptr<std::istream> input= nullptr;
    std::unique_ptr<std::ostream> output= nullptr;
    std::stringstream inputBuffer, outputBuffer;
    bool inPipe=false;
};

#endif //COMMAND_LINE_INTERPRETER_IOMANAGER_H
