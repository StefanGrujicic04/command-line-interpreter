//
// Created by Stefan Grujicic on 25.11.24..
//

#ifndef COMMAND_H
#define COMMAND_H
#include<iostream>
#include "../../CommandLineInterpreter.h"
#include "../../IOManager.h"
#include "../../Exeptions.h"
#include<vector>
class Command {
protected:
     Command()=default;
public:

    virtual ~Command()=default;// detructor that is same for every derived command

    virtual void execute( std::vector<std::string>& args,  std::vector<int>& positions)const=0;//Abstract execute

};


#endif
