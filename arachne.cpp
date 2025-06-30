#include "arachne.h"
#include "iostream"

Arachne::Arachne(GameDataRef data, int r, int x, int y, int HP_x, int HP_y, const std::string& texturePath, bool isFlipped, int health, int speed, int fireRate)
    : Ship(data, r, x, y, HP_x, HP_y, texturePath, isFlipped, health, speed, fireRate), gen(rd()), distrib(-5, 10)  {
}

Arachne::~Arachne() {
    // Implement destructor if needed
}

void Arachne::ability() {
    int random_x = distrib(gen);
    takeDamage(random_x);
    //std::cout << "ability used" << std::endl;

}
