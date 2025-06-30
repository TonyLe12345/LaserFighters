#include "goliath.h"
#include "iostream"
#include "DEFINITIONS.h"

goliath::goliath(GameDataRef data, int r, int x, int y, int HP_x, int HP_y, const std::string& texturePath, bool isFlipped, int health, int speed, int fireRate)
    : Ship(data, r, x, y, HP_x, HP_y, texturePath, isFlipped, health, speed, fireRate) {
}

goliath::~goliath() {
  
}

void goliath::ability() {
    int newhealth = getHealth();
    newhealth = newhealth + 2;
    if (newhealth > GOLIATH_HEALTH) {
        setHealth(GOLIATH_HEALTH);
    } else {
        setHealth(newhealth);
    }

}
