#include "GameOverState.h"
#include <iostream>
#include "MainMenuState.h"
#include "DEFINITIONS.h"

GameOverState::GameOverState(GameDataRef data, const std::string& winner) : _data(data), _winner(winner) {}

void GameOverState::Init()
{
    // Load font
    if (!_font.loadFromFile(GAMEOVER_FONT_PATH))
    {
        std::cerr << "Failed to load font!" << std::endl;
    }
    //EndScreenBackground.jpg

    // Load background
    _data->assets.LoadTexture("Game Over Background", "Assets/EndScreenBackground.jpg");
    _background.setTexture(_data->assets.GetTexture("Game Over Background"));

    // Set up game over text
    _gameOverText.setFont(_font);
    _gameOverText.setString("Game Over, " + _winner + " wins!");
    _gameOverText.setCharacterSize(50);
    _gameOverText.setFillColor(sf::Color::White);
    _gameOverText.setPosition(_data->window.getSize().x / 2.0f - _gameOverText.getGlobalBounds().width / 2.0f, _data->window.getSize().y / 3.0f);

    // Set up instruction text
    _instructionText.setFont(_font);
    _instructionText.setString("Play again? Y/N");
    _instructionText.setCharacterSize(30);
    _instructionText.setFillColor(sf::Color::White);
    _instructionText.setPosition(_data->window.getSize().x / 2.0f - _instructionText.getGlobalBounds().width / 2.0f, _data->window.getSize().y / 2.0f);
}

void GameOverState::HandleInput()
{
    sf::Event event;
    while (_data->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _data->window.close();
        }

        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Y)
            {
                _data->machine.AddState(StateRef(new MainMenuState(_data)), true);
            }
            else if (event.key.code == sf::Keyboard::N)
            {
                _data->window.close();
            }
        }
    }
}

void GameOverState::Update(float dt) {}

void GameOverState::Draw(float dt)
{
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_gameOverText);
    _data->window.draw(_instructionText);
    _data->window.display();
}
