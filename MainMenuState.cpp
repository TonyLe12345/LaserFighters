#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "MainMenuState.h"
#include "laserFighters2000.h"
#include "CharacterSelect.h"

MainMenuState::MainMenuState(GameDataRef data) : _data(data), _selectedItemIndex(0) {}

void MainMenuState::Init()
{
    // Load background
    _data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
    _background.setTexture(_data->assets.GetTexture("Main Menu Background"));

    // Load fonts
    _data->assets.LoadFont("Main Menu Font", "Assets/PLANK___.TTF");

 
    // Setup play button
    _playButton.setFont(_data->assets.GetFont("Main Menu Font"));
    _playButton.setString("PLAY");
    _playButton.setCharacterSize(70);
    _playButton.setFillColor(sf::Color::Blue); // Highlighted color
    _playButton.setPosition(_data->window.getSize().x / 4.0f - _playButton.getGlobalBounds().width / 2.0f, _data->window.getSize().y / 3.0f);

    // Setup exit button
    _exitButton.setFont(_data->assets.GetFont("Main Menu Font"));
    _exitButton.setString("EXIT");
    _exitButton.setCharacterSize(70);
    _exitButton.setFillColor(sf::Color::White);
    _exitButton.setPosition(_data->window.getSize().x / 4.0f - _exitButton.getGlobalBounds().width / 2.0f, _data->window.getSize().y / 2.0f);
}

void MainMenuState::HandleInput()
{
    sf::Event event;
    while (_data->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
        {
            _data->window.close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
            {
                MoveUp();
            }
            else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
            {
                MoveDown();
            }
            else if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Space)
            {
                SelectItem();
            }
        }
    }
}

void MainMenuState::Update(float frameRate)
{
    // Update logic if any
}

void MainMenuState::Draw(float frameRate)
{
    _data->window.clear();

    _data->window.draw(_background);
    _data->window.draw(_title);
    _data->window.draw(_playButton);
    _data->window.draw(_exitButton);

    _data->window.display();
}

void MainMenuState::MoveUp()
{
    if (_selectedItemIndex > 0)
    {
        _selectedItemIndex--;
        if (_selectedItemIndex == 0)
        {
            _playButton.setFillColor(sf::Color::Blue);
            _exitButton.setFillColor(sf::Color::White);
        }
    }
}

void MainMenuState::MoveDown()
{
    if (_selectedItemIndex < 1)
    {
        _selectedItemIndex++;
        if (_selectedItemIndex == 1)
        {
            _playButton.setFillColor(sf::Color::White);
            _exitButton.setFillColor(sf::Color::Blue);
        }
    }
}

void MainMenuState::SelectItem()
{
    if (_selectedItemIndex == 0)
    {
        // Transition to the game state

        _data->machine.AddState(StateRef(new CharacterSelect(_data, _data->window.getSize().x, _data->window.getSize().y, "Character Select P1")), true);
    }
    else if (_selectedItemIndex == 1)
    {
        _data->window.close();
    }
}
