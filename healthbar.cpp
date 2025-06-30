#include "healthbar.h"

healthbar::healthbar(float x, float y, float width, float height, int maxHealth)
    : maxHealth(maxHealth), width(width) {
    outerBar.setSize(sf::Vector2f(width, height));
    outerBar.setFillColor(sf::Color::Transparent);
    outerBar.setOutlineColor(sf::Color::White);
    outerBar.setOutlineThickness(2);
    outerBar.setPosition(x, y);

    innerBar.setSize(sf::Vector2f(width, height));
    innerBar.setFillColor(sf::Color::Red);
    innerBar.setPosition(x, y);
}

void healthbar::setHealth(int health) {
    float healthPercent = static_cast<float>(health) / maxHealth;
    innerBar.setSize(sf::Vector2f(width * healthPercent, innerBar.getSize().y));
}

void healthbar::draw(sf::RenderWindow& window) {
    window.draw(outerBar);
    window.draw(innerBar);
}
