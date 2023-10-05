#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <string>
#include "config.h"
#include "Inventory.h"

class Player {
public:
    Player(int health = DEFAULT_HEALTH, int points = 0, int capacity = INVENTORY_CAPACITY);

    int getHealth();
    int getPoints();
    bool increaseHealth(int value = DEFAULT_INCRESE_HEALTH);
    bool decreaseHealth(int value = DEFAULT_DECRESE_HEALTH);
    void increasePoints(int value = DEFAULT_INCRESE_POINTS);

    Inventory* inventory;
private:
    int health;
    int points;
};
#endif