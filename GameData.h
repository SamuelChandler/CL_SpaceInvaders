#ifndef GAMEDATA_H 
#define GAMEDATA_H 

#include <string>
#include <vector>

static const int WIDTH = 54;

class alien{

public:
    int x;
    int y;
    char sprite;

    alien(int a, int b, char s): x(a), y(b), sprite(s){};
};

class gameData{

public:
    int playerPosition;
    int lives;
    int score;
    bool end;

    std::vector<alien> enemies;

    void init();

    void loseLife();
    void movePlayer(int change);
    void gameEnd();
};



#endif