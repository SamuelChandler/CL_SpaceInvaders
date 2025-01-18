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
    std::cout << "Cannot Wipe A screen with no OS defined" << std::endl;
}
void commandSuite::resetSize(){
    std::cout << "Cannot Reset Screen Size without OS defined" << std::endl;
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

    //player information
    playerName = name;
    Version = windows;
    time = 0.0f;

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

