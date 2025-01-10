#include "commandSuite.h"
#include <iostream>
#include <string>

class commandSuite{
public: 
    float time = 0.0f;
    OS Version = none;
    std::string playerName = "none";

    commandSuite(){
        playerName = "Name Not Given";
    }

    commandSuite(std::string name){
        playerName = name;  
    }
    
    virtual void wipeScreen(){}

    virtual void writeScreen(){}
};

class LinuxCommandSuite : public commandSuite{

    OS version = Linux;

public:

    LinuxCommandSuite(){
        playerName = "Name Not Given";
    }

    LinuxCommandSuite(std::string name){
        playerName = name;
        std::cout << "command Suite created for Linux user, " << playerName << std::endl;
    }

    void wipeScreen(){
        std::cout << "wipeing Screen" << std::endl; 
        return;
    }

    void writeScreen(){
        std::cout << "Writing to Screen" << std::endl;
        return;
    }

};

