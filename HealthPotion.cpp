#include "HealthPotion.h"
#include "config.h"

HealthPotion::HealthPotion(std::string name, int healingAmount) : name(name), healingAmount(healingAmount) {
    if (healingAmount <= 0 || healingAmount > MAX_HEALING_AMOUNT) {
        this->healingAmount = HEALTH_POTION;
    }
}

bool HealthPotion::use(Player& player) {
    return player.increaseHealth(healingAmount);
}

Item* HealthPotion::getCopy() {
    return new HealthPotion(*this);
}

const std::string& HealthPotion::getName() {
    return this->name;
}