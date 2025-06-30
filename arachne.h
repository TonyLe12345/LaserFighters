#pragma once

#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "player.h"
#include <random>

class Arachne : public Ship {
public:
    Arachne(GameDataRef data, int r, int x, int y, int HP_x, int HP_y, const std::string& texturePath, bool isFlipped, int health, int speed, int fireRate);
    ~Arachne();

    void ability();

private:
    std::random_device rd;  
    std::mt19937 gen;       
    std::uniform_int_distribution<> distrib; 
};
