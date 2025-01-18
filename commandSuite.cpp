#include "commandSuite.h"
#include <iostream>
#include <string>
#include <stdlib.h>

commandSuite::commandSuite(){
    playerName = "none";
    Version = none;
    time = 0.0f;
}
commandSuite::commandSuite(std::string name){
    playerName = name;
    Version = none;
    time = 0.0f;
}
void commandSuite::wipeScreen(){
    std::cout << "Cannot Wipe A screen with no OS defined" << std::endl;
}


LinuxCommandSuite::LinuxCommandSuite(std::string name){
    playerName = name;
    Version = Linux;
    time = 0.0f;

    std::cout << "command Suite created for Linux user, " << playerName << std::endl;
}

//clears the Screen
void LinuxCommandSuite::wipeScreen() {
    system("clear");
    // std::cout << "Screen Cleared" << std::endl;
}

WindowsCommandSuite::WindowsCommandSuite(std::string name){ 
    playerName = name;
    Version = windows;
    time = 0.0f;

    std::cout << "Command Suite created for Windows User, " << playerName << std::endl;
}


void WindowsCommandSuite::wipeScreen(){
    system("cls");
}

