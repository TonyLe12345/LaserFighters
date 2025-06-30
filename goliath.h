#pragma once

#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "player.h"

class goliath : public Ship
{
public:
    goliath(GameDataRef data, int r, int x, int y, int HP_x, int HP_y, const std::string& texturePath, bool isFlipped, int health, int speed, int fireRate);    
    ~goliath();

    void ability();
    int getSpeed();

};

