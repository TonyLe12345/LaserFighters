#include "flea.h"
#include "iostream"

Flea::Flea(GameDataRef data, int r, int x, int y, int HP_x, int HP_y, const std::string& texturePath, bool isFlipped, int health, int speed, int fireRate)
    : Ship(data, r, x, y, HP_x, HP_y, texturePath, isFlipped, health, speed, fireRate), gen(rd()), distrib(170, 830) 
{
}

Flea::~Flea() {
    // Implement destructor if needed
}

void Flea::ability() {
    int random_x = distrib(gen);  // Generate random x position between 170 and 830
    int y = sprite.getPosition().y;
    sprite.setPosition(random_x, y);
    //std::cout << "ability used" << std::endl;

}
