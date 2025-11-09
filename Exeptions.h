//
// Created by Stefan Grujicic on 1. 8. 2025..
//

#ifndef COMMAND_LINE_INTERPRETER_EXEPTIONS_H
#define COMMAND_LINE_INTERPRETER_EXEPTIONS_H
#include <exception>
#include <string>
#include <utility>
//all exceptions
class BaseException : public std::exception {
protected:
    std::string message;
    std::string line;
    int position;
    int length;
    mutable std::string fullMessage;

public:
    virtual const char* prefix() const { return "Base Exception: "; }


    BaseException(const std::string& msg, std::string l, int pos, int len)
        : message(msg), line(std::move(l)), position(pos), length(len) {}

    explicit BaseException(const std::string& msg)
        : message(msg) {}

    [[nodiscard]] const char* what() const noexcept override {//costracting what is written
        if (fullMessage.empty()) {
            fullMessage = std::string(prefix()) + message;
            if (!line.empty()) {
                fullMessage += "\n" + line + "\n" +
                    std::string(position, ' ') + std::string(length, '^');
            }
        }
        return fullMessage.c_str();
    }
};

class LexicalException : public BaseException {
    const char* prefix() const override { return "Lexical Exception: "; }
    using BaseException::BaseException;
};

class CommandNotFoundException : public BaseException {
    const char* prefix() const override { return "Command not found Exception: "; }
    using BaseException::BaseException;
};

class StreamConflictException : public BaseException {
    const char* prefix() const override { return "Stream Conflict Exception: "; }
    using BaseException::BaseException;
};

class CommandExecutionException : public BaseException {
    const char* prefix() const override { return "Command execution Exception: "; }
    using BaseException::BaseException;
};

class FileIOException : public BaseException {
    const char* prefix() const override { return "File Input/output Exception: "; }
    using BaseException::BaseException;
};
#endif //COMMAND_LINE_INTERPRETER_EXEPTIONS_H
