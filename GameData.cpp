#include <stdlib.h>
#include <iostream>
#include <string>

#include "GameData.h"

gameData::gameData(){
    playerPosition = WIDTH/2;
    lives = 3;
}

void gameData::loseLife(){
    lives--;
}

void gameData::movePlayer(int change){
    playerPosition += change;
    
    //frame the changes 
    if(playerPosition < 0){
        playerPosition = 0;
    }
    else if(playerPosition > WIDTH){
        playerPosition = WIDTH;
    }


}
