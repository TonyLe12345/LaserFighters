#pragma once

#include "player.h"

class Ship : public player {
public:
    Ship(GameDataRef data, int r, int x, int y, int HP_x, int HP_y, const std::string& texturePath, bool isFlipped, int health, int speed, int fireRate);

    void setSpeed(int speed);
    int getSpeed() const override;

    void setFireRate(int fireRate);
    int getFireRate() const;

protected:
    int speed;
    int fireRate;
};
