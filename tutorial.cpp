#include <iostream>
#include <string>
#include "tutorial.h"


// message that will welcome the player into the game
void welcomeMessage(std::string name){
    std::cout << "Hello, " << name << "!" << std::endl;
    std::cout << "Welcome to Space Invaders the Command Line Game!" << std::endl;

    return; 
}

// will stop the game until the user has requested the game to start 
void waitForStart(){
    std::cout << "Press enter to start the game!" << std::endl; 

    std::string input; 

    std::getline(std::cin, input);

    return; 
}