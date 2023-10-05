#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H

#include "Item.h"
#include "Player.h"


class HealthPotion : public Item {
public:
    HealthPotion(std::string name = "HealthPotion", int healingAmount = HEALTH_POTION);
    const std::string& getName() override;
    bool use(Player& player) override;
    Item* getCopy() override;
private:
    int healingAmount;
    const std::string name;
};

#endif