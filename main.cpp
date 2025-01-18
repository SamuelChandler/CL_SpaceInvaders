#include <iostream>
#include <string>
#include <chrono> 
#include <thread> 

#include "tutorial.h"
#include "commandSuite.h"




int main(int argc, char* argv[]) {
    std::string name = "World";
    commandSuite* suite;

    if (argc > 1) {
        name = argv[1];
    }

    welcomeMessage(name);
    
    //determine operating system and commandsuite to use
    #if __linux__
        std::cout << "Linux Version" << std::endl;
        suite = new LinuxCommandSuite(name);
        
    // Todo: Add windows Support
    #elif _WIN32
        std::cout << "Windows Version" << std::endl;
        suite = new WindowsCommandSuite(name);
    
    #else
        std::cout << "This game does not support this Operating System" << std::endl;
    
    #endif


    waitForEnter();
    suite->wipeScreen();


    return 0;
}