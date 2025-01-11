#ifndef COMMANDSUITE_H
#define COMMANDSUITE_H

#include <string>

enum OS{
    none, 
    windows, 
    Linux,
};

class commandSuite{

public:
    
    float time;
    OS Version;
    std::string playerName;
    
    commandSuite();
    commandSuite(std::string name);

    virtual void wipeScreen();

};

class LinuxCommandSuite: public commandSuite{

public: 
    LinuxCommandSuite(std::string name);

    void wipeScreen() override;

};



#endif