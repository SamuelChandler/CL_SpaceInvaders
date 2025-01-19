#ifndef GAMEDATA_H 
#define GAMEDATA_H 

#include <string>

static const int WIDTH = 45;

class gameData{

public:
    int playerPosition;
    int lives;

    gameData();

    void loseLife();
    void movePlayer(int change);
};

#endif