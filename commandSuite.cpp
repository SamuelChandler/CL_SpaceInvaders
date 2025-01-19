#include "commandSuite.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>

commandSuite::commandSuite(){
    playerName = "none";
    Version = none;
    time = 0.0f;
    score = 0;
    
}
commandSuite::commandSuite(std::string name){
    playerName = name;
    Version = none;
    time = 0.0f;
}
void commandSuite::wipeScreen(){
    std::cout << "Cannot Wipe A screen with OS undefined" << std::endl;
}
void commandSuite::resetSize(){
    std::cout << "Cannot Reset Screen Size with OS undefined" << std::endl;
}
void commandSuite::render(gameData &data){
    std::cout << "Cannot Render when OS undefined" << std::endl;
}


LinuxCommandSuite::LinuxCommandSuite(std::string name){
    playerName = name;
    Version = Linux;
    time = 0.0f;
    score = 0;

    std::cout << "command Suite created for Linux user, " << playerName << std::endl;
}

//clears the Screen
void LinuxCommandSuite::wipeScreen() {
    system("clear");
    // std::cout << "Screen Cleared" << std::endl;
}

WindowsCommandSuite::WindowsCommandSuite(std::string name){ 

    //player information
    playerName = name;
    Version = windows;
    time = 0.0f;
    score = 0;

    //set the screen size 
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //save current dimensions
    MoveWindow(console, r.left, r.top, W_WIDTH, W_HEIGHT, TRUE);

    std::cout << "Command Suite created for Windows User, " << playerName << std::endl;
}


void WindowsCommandSuite::wipeScreen(){
    system("cls");
}

//sets the size of the window to the initial values
void WindowsCommandSuite::resetSize(){

    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //save current dimensions
    MoveWindow(console, r.left, r.top, W_WIDTH, W_HEIGHT, TRUE);

}

void WindowsCommandSuite::render(gameData &data){

    //Player Name and current Score
    std::cout << playerName ;

    for(int x = playerName.length(); x <45 ; x++){
        std::cout << " ";
    } 

    std::cout << "Score: " << score << "\n";

    //render each row 
    for(int x = 0; x < 32; x++){
        std::cout << "1\n";
    }

    //render Player 
    for(int x = 0; x < 45; x++){
        if(x == data.playerPosition){
            std::cout << "^" ;
        }
        else{
            std::cout << " ";
        }
    }
    std::cout << std::flush;

    //Increment the score to detect new render
    score++;
}

