
#include"Factory.h"
void Factory::factoryMaking() {
    CommandFactory& myFactory = CommandFactory::getInstance();
    //generates factory for every command
    myFactory.registerCommand("echo", std::make_unique<EchoCommand>());
    myFactory.registerCommand("date", std::make_unique<DateCommand>());
    myFactory.registerCommand("time", std::make_unique<TimeCommand>());
    myFactory.registerCommand("touch", std::make_unique<TouchCommand>());
    myFactory.registerCommand("wc", std::make_unique<WcCommand>());
    myFactory.registerCommand("prompt", std::make_unique<PromptCommand>());
    myFactory.registerCommand("rm", std::make_unique<RmCommand>());
    myFactory.registerCommand("truncate", std::make_unique<TruncateCommand>());
    myFactory.registerCommand("head", std::make_unique<HeadCommand>());
    myFactory.registerCommand("tr", std::make_unique<TrCommand>());
    myFactory.registerCommand("batch", std::make_unique<BatchCommand>());


}