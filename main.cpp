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

    gameData data;
    data.init();
    playerController controller;

    //timing variables 
    time_t start,end;


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

    //play the welcome message 
    welcomeMessage(name);

    //start upon enter press 
    waitForEnter();
    suite->wipeScreen();
    
    //create thread for the player conroller 
    std::thread controllerThread(&playerController::run,&controller,std::ref(data));

    //set the start time variable
    time(&start);

    //display loop, runs in parrallel with the player controller
    while(!data.end){

  
        std::this_thread::sleep_for(std::chrono::milliseconds(8));
        suite->resetSize();
        suite->wipeScreen();
        suite->render(data);

        //check time 
        time(&end);

        //fixed update 
        if(difftime(end,start) >= 0.1){
            //increase score for surviving 
            data.score++;

            //update start time 
            start = end;

        }


    } 

    //wait for controller to finish
    controllerThread.join();

    //end game 
    suite->wipeScreen();
    endGameMessage();
    return 0;
}