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
    int vel;

    alien(int a, int b, char s, int v): x(a), y(b), sprite(s), vel(v){};
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
    void enemyMovement();
    void movePlayer(int change);
    void gameEnd();
};



#endif