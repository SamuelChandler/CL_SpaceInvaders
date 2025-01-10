#ifndef COMMANDSUITE
#define COMMANDSUITE

enum OS{
    none, 
    windows, 
    Linux,
};

class commandSuite{

public:
    float time;
    OS Version;

    commandSuite();
    commandSuite(std::string name);

    virtual void wipeScreen();
    virtual void writeScreen();
};

class LinuxCommandSuite: public commandSuite{


public: 

    LinuxCommandSuite();
    LinuxCommandSuite(std::string name);

    void wipeScreen() override;
    void writeScreen() override;
};



#endif