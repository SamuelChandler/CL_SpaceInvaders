#include <stdlib.h>
#include <iostream>
#include <string>

#include "GameData.h"

//sets up the player data, must be ran before using the data class
void gameData::init(){
    playerPosition = WIDTH/2;
    lives = 3;
    end = false;
}

//player loses a life
void gameData::loseLife(){
    lives--;
}

//changes player position in the data
void gameData::movePlayer(int change){
    playerPosition += change;
    
    //limit the changes to max values  
    if(playerPosition < 0){
        playerPosition = 0;
    }
    else if(playerPosition > WIDTH){
        playerPosition = WIDTH;
    }


}

//sets the flag to end the game
void gameData::gameEnd(){
    end = true;
}
