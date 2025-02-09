#include <stdlib.h>
#include <iostream>
#include <string>

#include "GameData.h"

//sets up the player data, must be ran before using the data class
void gameData::init(){
    playerPosition = WIDTH/2;
    score = 0;
    lives = 3;
    end = false;

    enemies.push_back(alien(1,1,'O',1));
    enemies.push_back(alien(4,1,'Y',-1));
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
    else if(playerPosition >= WIDTH){
        playerPosition = WIDTH-1;
    }
}

void gameData::enemyMovement(){
    for(alien a:enemies){

        //update position
        a.x = a.x + a.vel;

        //swap direction when at an edge
        if(a.x >= WIDTH){
            a.vel = -1 * a.vel;
        }else if(a.x <= 0){
            a.vel = -1 * a.vel;
        }

    }
}

//sets the flag to end the game
void gameData::gameEnd(){
    end = true;
}
