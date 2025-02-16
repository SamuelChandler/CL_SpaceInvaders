#include "playerController.h"

#include <string>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

playerController::playerController(){
    std::cout << "Player Controller Created" << std::endl;
}

void playerController::run( gameData &data){
    std::cout << "playerController is Running" << std::endl;

    char input;

    while(1){
        input = getch();

        if(input == 'a'){
            data.movePlayer(-1);
        }else if(input == 'd'){
            data.movePlayer(1);
        }else if(input == ' '){
            data.fire();
        }else if(input == 27){
            //esc
            data.gameEnd();
            break;
        }
    }
}