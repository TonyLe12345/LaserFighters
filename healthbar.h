#include <SFML/Graphics.hpp>

class healthbar {
private:
    sf::RectangleShape bar;
    int maxWidth; // Maximum width of the health bar
    int currentWidth; // Current width of the health bar
    sf::Vector2f position;

public:
    healthbar(sf::Vector2f pos, float width, float height) : position(pos), maxWidth(width), currentWidth(width) {
        bar.setSize(sf::Vector2f(width, height));
        bar.setFillColor(sf::Color::Red);
        bar.setPosition(position);
    }

    void setHealth(float healthPercentage) {
        if (healthPercentage < 0) healthPercentage = 0;
        else if (healthPercentage > 100) healthPercentage = 100;
        currentWidth = maxWidth * (healthPercentage / 100.0f);
        bar.setSize(sf::Vector2f(currentWidth, bar.getSize().y));
    }

    void draw(sf::RenderWindow& window) {
        window.draw(bar);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Health Bar");

    healthbar healthBar(sf::Vector2f(50, 50), 200, 20);

    float playerHealth = 100.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update player's health (this can come from your game logic)
        playerHealth -= 0.01f;

        // Update health bar based on player's health
        healthBar.setHealth(playerHealth);

        window.clear();
        // Draw everything
        healthBar.draw(window);
        window.display();
    }

    return 0;
}