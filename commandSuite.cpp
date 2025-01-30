#include "commandSuite.h"
#include <iostream>
#include <string>
#include <windows.h>
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
    std::cout << "Cannot Wipe A screen with OS undefined" << std::endl;
}
void commandSuite::resetSize(){
    std::cout << "Cannot Reset Screen Size with OS undefined" << std::endl;
}
void commandSuite::render(gameData &data){
    std::cout << "Cannot Render when OS undefined" << std::endl;
}
void commandSuite::setCursorPosition(int x, int y){
    std::cout << "cannot Set Cursor without setting the operating system" << std::endl;
}
void commandSuite::updateBoard(gameData &data){
    for (int y =0; y != GB_Height; ++y){
        for (int x = 0; x != GB_Width; ++x){
            gameBoard[x][y] = ' ';
        }
    }
}


LinuxCommandSuite::LinuxCommandSuite(std::string name){
    playerName = name;
    Version = Linux;
    time = 0.0f;

    //create the board
    for (int y =0; y != GB_Height; ++y){
        for (int x = 0; x != GB_Width; ++x){
            gameBoard[x][y] = ' ';
        }
    }

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

    //create the board and display board
    for (int y =0; y != GB_Height; ++y){
        for (int x = 0; x != GB_Width; ++x){
            gameBoard[x][y] = ' ';

        }
    }

    //set the screen size 
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //save current dimensions
    MoveWindow(console, r.left, r.top, W_WIDTH, W_HEIGHT, TRUE);

    std::cout << "Command Suite created for Windows User, " << playerName << std::endl;
}


void WindowsCommandSuite::wipeScreen(){
    //disable cursor
    system("setterm -cursor off");

    //full clear 
    system("cls");
}

//sets the size of the window to the initial values
void WindowsCommandSuite::resetSize(){

    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //save current dimensions
    MoveWindow(console, r.left, r.top, W_WIDTH, W_HEIGHT, TRUE);

}

void WindowsCommandSuite::updateBoard(gameData &data){
    
    //update player position
    for (int x = 0; x != GB_Width; ++x){
            if(x == data.playerPosition){
                gameBoard[x][GB_Height-1] = '^';
            }else{
                gameBoard[x][GB_Height-1] = ' ';
            }
    }
}

void WindowsCommandSuite::render(gameData &data){

    setCursorPosition(0,0);
    //Player Name and current Score
    std::cout << playerName ;

    for(int x = playerName.length(); x <43 ; x++){
        std::cout << " ";
    } 

    std::cout << "Score: " << data.score << "\n";

    //render seperation bar 
    for(int x = 0; x < 54; x++){
        std::cout << "=";
    }

    for(int y = 0; y != GB_Height; ++y){
        for(int x = 0; x != GB_Width; ++x){
            std::cout << gameBoard[x][y];
        }
        
    }
    std::cout.flush();

}

//sets the cursor too the position in the console based on the x,y coordinates
void WindowsCommandSuite::setCursorPosition(int x, int y){
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}
