#ifndef GAMEDATA_H 
#define GAMEDATA_H 

#include <string>

static const int WIDTH = 54;

class gameData{

public:
    int playerPosition;
    int lives;
    int score;
    bool end;

    void init();

    void loseLife();
    void movePlayer(int change);
    void gameEnd();
};

#endif