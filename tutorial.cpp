#include <iostream>
#include <string>
#include "tutorial.h"


// message that will welcome the player into the game
void welcomeMessage(std::string name){
    std::cout << "Hello, " << name << "!" << std::endl;
    std::cout << "Welcome to Space Invaders the Command Line Game!\n" << std::endl;

    std::cout << "Press Enter to Start the game!" << std::endl;
    return; 
}

//message that will inform the player that the game is over
void endGameMessage(){
    std::cout << "Game Over" << std::endl;
}

// will stop the game until the user has requested the game to start 
void waitForEnter(){

    std::string input; 

    std::getline(std::cin, input);

    return; 
}