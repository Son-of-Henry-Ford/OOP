#include "Player.h"


Player::Player(int health, int points, int capacity) {
    if (health <= 0 || health > MAX_HEALTH) {
        health = DEFAULT_HEALTH;
    }
    if (points < 0) {
        points = 0;
    }
    if (capacity < 0 || capacity > MAX_INVENTORY_CAPACITY) {
        capacity = INVENTORY_CAPACITY;
    }
    this->health = health;
    this->points = points;
    this->inventory = new Inventory(capacity);
}

int Player::getHealth() {
    return this->health;
}

int Player::getPoints() {
    return points;
}

bool Player::increaseHealth(int value) {
    if (health < MAX_HEALTH) {
        health += value;
        health -= health % MAX_HEALTH;
        return true;
    }
    return false;
}

bool Player::decreaseHealth(int value) {
    health -= value;
    if (health <= 0) {
        health = 0;
        return false;
    }
    return true;
}

void Player::increasePoints(int value) {
    points += value;
}