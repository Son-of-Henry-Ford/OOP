#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include"Keys.h"
#include"Player.h"

class PlayerController
{
public:
    PlayerController(Player& p, int x = X_SIZE, int y = Y_SIZE);
    void run();
    int getX();
    int getY();

private:
    Keys convertToKeys(int key);
    char getKeyPress();
    void updatePlayerPosition(Keys key);
    void hotKeys(Keys key);

    Player& player;
    int x;
    int y;
};

#endif
