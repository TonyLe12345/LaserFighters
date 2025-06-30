#include "Ship.h"

Ship::Ship(GameDataRef data, int r, int x, int y, int HP_x, int HP_y, const std::string& texturePath, bool isFlipped, int health, int speed, int fireRate)
    : player(data, r, x, y, HP_x, HP_y, texturePath, isFlipped, fireRate), speed(speed) {}


void Ship::setSpeed(int speed) {
    this->speed = speed;
}

int Ship::getSpeed() const {
    return speed;
}

void Ship::setFireRate(int fireRate) {
    this->fireRate = fireRate;
}

int Ship::getFireRate() const {
    return fireRate;
}
