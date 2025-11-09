//
// Created by Stefan Grujicic on 28.1.25..
//

#include "DeletingCommand.h"
#include <filesystem>

void DeletingCommand::deleteFile(std::string& filename)const{
    //deletes command and gives error if it was not secessful
    if (std::filesystem::exists(filename)) {
        if (std::remove(filename.c_str()) == 0) {
            return;
        } else {
            throw CommandExecutionException("Could not delete file: "+filename+"\n");
        }
    } else {
        throw FileIOException("File "+filename+" does not exist\n");

    }
}
