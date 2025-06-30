#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include "Ship.h"
#include "player.h"

class Flea : public Ship
{
public:
    Flea(GameDataRef data, int r, int x, int y, int HP_x, int HP_y, const std::string& texturePath, bool isFlipped, int health, int speed, int fireRate);
    ~Flea();

    void ability();

private:
    std::random_device rd;  // Random device to seed the generator
    std::mt19937 gen;       // Mersenne Twister random number generator
    std::uniform_int_distribution<> distrib; // Uniform distribution for range

    // Add any private members if needed
};

