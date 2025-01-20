#include <iostream>
#include <string>
#include <chrono> 
#include <thread> 

#include "tutorial.h"
#include "commandSuite.h"
#include "GameData.h"
#include "playerController.h"




int main(int argc, char* argv[]) {
    std::string name = "World";
    commandSuite* suite;
    gameData* data = new gameData();


    playerController* controller = new playerController();


    if (argc > 1) {
        name = argv[1];
    }

    
    
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
        waitForEnter();
        return 0;
    
    #endif

    //play the welcome message and start upon enter press 
    welcomeMessage(name);
    waitForEnter();

    suite->wipeScreen();

    //create thread for the player conroller 
    std::thread controllerThread(&playerController::run,&controller,std::ref(data),123);


    while(1){
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        suite->resetSize();
        suite->wipeScreen();
        suite->render(*data);
    } 

    controllerThread.join();

    return 0;
}