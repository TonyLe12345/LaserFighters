#pragma once

#include <SFML/Graphics.hpp>

class healthbar {
public:
    healthbar(float x, float y, float width, float height, int maxHealth);
    void setHealth(int health);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape outerBar;
    sf::RectangleShape innerBar;
    int maxHealth;
    float width;
};
