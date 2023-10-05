#ifndef ITEM_H
#define ITEM_H

#include <string>

class Player;

class Item {
public:
    virtual const std::string& getName() = 0;
    virtual bool use(Player& player) = 0;
    virtual Item* getCopy() = 0;
    virtual ~Item() = 0;
};

#endif