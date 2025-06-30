#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

#define maxMainMenu 3

class MainMenu {
public:
    MainMenu(float width, float height);

    void draw(RenderWindow& window);
    void drawAbout(RenderWindow& window);
    void MoveUp();
    void MoveDown();

    int MainMenuPressed() {
        return MainMenuSelected;
    }

    ~MainMenu();
private:
    int MainMenuSelected;
    Font font;
    Text mainMenu[maxMainMenu];

    // Background elements
    sf::RectangleShape background;
    sf::RectangleShape ABbackground;
    sf::Texture Maintexture;
    sf::Texture Abouttexture;
};

MainMenu::MainMenu(float width, float height) {
    if (!font.loadFromFile("Fonts/ALGER.TTF")) {
        cout << "Font not found." << endl;
    }

    // Initialize menu options
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::Blue);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(60);
    mainMenu[0].setPosition(Vector2f(width / 2 - width / 4, height / (maxMainMenu + 1) * 1 - height / 9));

    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("About");
    mainMenu[1].setCharacterSize(60);
    mainMenu[1].setPosition(Vector2f(width / 2 - width / 4, height / (maxMainMenu + 1) * 2 - height / 9));

    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::White);
    mainMenu[2].setString("Exit");
    mainMenu[2].setCharacterSize(60);
    mainMenu[2].setPosition(Vector2f(width / 2 - width / 4, height / (maxMainMenu + 1) * 3 - height / 9));

    MainMenuSelected = 0;

    // Set background for Main Menu
    background.setSize(sf::Vector2f(1000, 600));
    Maintexture.loadFromFile("Backgrounds/Main_Menu_960_720.jpg");
    background.setTexture(&Maintexture);

    // About Laser Fighter 2000
    ABbackground.setSize(sf::Vector2f(1000, 600));
    Abouttexture.loadFromFile("Backgrounds/About_silly_960_720.jpg");
    ABbackground.setTexture(&Abouttexture);
}

MainMenu::~MainMenu() {}

void MainMenu::draw(RenderWindow& window) {
    window.draw(background);
    for (int i = 0; i < maxMainMenu; ++i) {
        window.draw(mainMenu[i]);
    }
}

void MainMenu::drawAbout(RenderWindow& window) {
    window.draw(ABbackground);
}

// MoveUp
void MainMenu::MoveUp() {
    if (MainMenuSelected - 1 >= 0) {
        mainMenu[MainMenuSelected].setFillColor(Color::White);
        MainMenuSelected--;
        if (MainMenuSelected == -1) {
            MainMenuSelected = 2;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}

// MoveDown
void MainMenu::MoveDown() {
    if (MainMenuSelected + 1 < maxMainMenu) {
        mainMenu[MainMenuSelected].setFillColor(Color::White);
        MainMenuSelected++;
        if (MainMenuSelected == maxMainMenu) {
            MainMenuSelected = 0;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}
