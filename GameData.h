#ifndef GAMEDATA_H 
#define GAMEDATA_H 

#include <string>

static const int WIDTH = 45;

class gameData{

public:
    int playerPosition;
    int lives;
    bool end;

    void init();

    void loseLife();
    void movePlayer(int change);
    void gameEnd();
};

#endif