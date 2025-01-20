#include "playerController.h"

#include <string>
#include <stdlib.h>
#include <iostream>

playerController::playerController(){
    std::cout << "Player Controller Created" << std::endl;
}

void playerController::run( gameData &data){
    std::cout << "playerController is Running" << std::endl;

    char input;

    while(1){
        std::cin >> input;

        if(input == 'a'){
            data.movePlayer(-1);
        }else if(input == 'd'){
            data.movePlayer(1);
        }
    }
}