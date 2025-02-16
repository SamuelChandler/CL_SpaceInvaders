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
    for(int x = 0; x < enemies.size(); x++){

        //update position
        enemies[x].x = enemies[x].x + enemies[x].vel;

        //swap direction and descend when at an edge
        if(enemies[x].x >= WIDTH){
            
            enemies[x].vel = -1 * enemies[x].vel;
            enemies[x].y = enemies[x].y +1;

        }else if(enemies[x].x <= 0){
            
            enemies[x].vel = -1 * enemies[x].vel;
            enemies[x].y = enemies[x].y +1;
        }

    }
}

void gameData::fire(){
    bullets.push_back(std::make_pair(playerPosition,HEIGHT-2));
}

//sets the flag to end the game
void gameData::gameEnd(){
    end = true;
}
