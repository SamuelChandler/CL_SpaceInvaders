#ifndef COMMANDSUITE_H
#define COMMANDSUITE_H

#include <string>
#include "GameData.h"

enum OS{
    none, 
    windows, 
    Linux,
};

static const int W_WIDTH = 470;
static const int W_HEIGHT = 600;

static const int L_WIDTH = 500;
static const int L_HEIGHT = 600;

static const int GB_Width = 54;
static const int GB_Height = 34;

class commandSuite{

public:
    
    float time;
    OS Version;
    std::string playerName;
    char gameBoard[GB_Width][GB_Height];
    
    commandSuite();
    commandSuite(std::string name);

    virtual void wipeScreen();
    virtual void resetSize();
    virtual void render(gameData &data);
    virtual void setCursorPosition(int x, int y);

};

class LinuxCommandSuite: public commandSuite{

public: 
    LinuxCommandSuite(std::string name);

    void wipeScreen() override;

};

class WindowsCommandSuite: public commandSuite{
    
public: 
    WindowsCommandSuite(std::string name);

    void wipeScreen() override;
    void resetSize() override;
    void render(gameData &data) override;
    void setCursorPosition(int x, int y) override;

};



#endif