#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "MainMenuState.h"
#include "laserFighters2000.h"
#include "CharacterSelect.h"
#include "CharacterSelectP2.h"

CharacterSelect::CharacterSelect(GameDataRef data, int x, int y, std::string title) : _data(data), _selectedShipIndex(0) {}

void CharacterSelect::Init()
{

    // Load the background texture
    _data->assets.LoadTexture("Character Select Screen Background", CHARACTER_SELECT_BACKGROUND_FILEPATH_P1);
    // Retrieve the background texture from the AssetManager
    sf::Texture& backgroundTexture = _data->assets.GetTexture("Character Select Screen Background");
    // Set the background texture for the sprite
    _background.setTexture(backgroundTexture);
    _background.setPosition(0, 0); // Set position as needed

    // Load fonts
    _data->assets.LoadFont("Font", "Assets/PLANK___.TTF");

 
    // Setup Goliath button
    _Goliath.setFont(_data->assets.GetFont("Font"));
    _Goliath.setString("Goliath");
    _Goliath.setCharacterSize(40);
    _Goliath.setFillColor(sf::Color::Blue); // Highlighted color
    _Goliath.setPosition(115, 370);

    // Setup Arachne button
    _Arachne.setFont(_data->assets.GetFont("Font"));
    _Arachne.setString("Arachne");
    _Arachne.setCharacterSize(40);
    _Arachne.setFillColor(sf::Color::White);
    _Arachne.setPosition(380, 370);

    // Setup Flea button
    _Flea.setFont(_data->assets.GetFont("Font"));
    _Flea.setString("Flea");
    _Flea.setCharacterSize(40);
    _Flea.setFillColor(sf::Color::White);
    _Flea.setPosition(740, 370);


}

void CharacterSelect::HandleInput()
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
            if (event.key.code == sf::Keyboard::A)
            {
                MoveLeft();
            }
            else if (event.key.code == sf::Keyboard::D)
            {
                MoveRight();
            }
            else if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Enter)
            {
                SelectItem();
            }
        }
    }
}

void CharacterSelect::Update(float frameRate)
{
    // Update logic if any
}

void CharacterSelect::Draw(float frameRate)
{
    _data->window.clear();

    _data->window.draw(_background);
    _data->window.draw(_Goliath);
    _data->window.draw(_Arachne);
    _data->window.draw(_Flea);

    _data->window.display();
}

void CharacterSelect::MoveLeft()
{
    if (_selectedShipIndex > 0)
    {
        _selectedShipIndex--;
        if (_selectedShipIndex == 0)
        {
            _Goliath.setFillColor(sf::Color::Blue);
            _Arachne.setFillColor(sf::Color::White);
            _Flea.setFillColor(sf::Color::White);
        }
        else if (_selectedShipIndex == 1)
        {
            _Goliath.setFillColor(sf::Color::White);
            _Arachne.setFillColor(sf::Color::Blue);
            _Flea.setFillColor(sf::Color::White);
        }
        else if (_selectedShipIndex == 2)
        {
            _Goliath.setFillColor(sf::Color::White);
            _Arachne.setFillColor(sf::Color::White);
            _Flea.setFillColor(sf::Color::Blue);
        }
    }
}

void CharacterSelect::MoveRight()
{
    if (_selectedShipIndex < 2)
    {
        _selectedShipIndex++;
        if (_selectedShipIndex == 0)
        {
            _Goliath.setFillColor(sf::Color::Blue);
            _Arachne.setFillColor(sf::Color::White);
            _Flea.setFillColor(sf::Color::White);
        }
        else if (_selectedShipIndex == 1)
        {
            _Goliath.setFillColor(sf::Color::White);
            _Arachne.setFillColor(sf::Color::Blue);
            _Flea.setFillColor(sf::Color::White);
        }
        else if (_selectedShipIndex == 2)
        {
            _Goliath.setFillColor(sf::Color::White);
            _Arachne.setFillColor(sf::Color::White);
            _Flea.setFillColor(sf::Color::Blue);
        }
    }
}

void CharacterSelect::SelectItem()
{

// i think this is the bug !!

    if (_selectedShipIndex == 0)
    {
        // Transition to the game state
        
        _data->machine.AddState(StateRef(new CharacterSelectP2(_data, _data->window.getSize().x, _data->window.getSize().y,  "Player 2 Character Select", _selectedShipIndex)), true);
    }
    else if (_selectedShipIndex == 1)
    {
        // Transition to the game state
        
        _data->machine.AddState(StateRef(new CharacterSelectP2(_data, _data->window.getSize().x, _data->window.getSize().y,  "Player 2 Character Select", _selectedShipIndex)), true);
    }
    else if (_selectedShipIndex == 2)
    {
        // Transition to the game state
        
        _data->machine.AddState(StateRef(new CharacterSelectP2(_data, _data->window.getSize().x, _data->window.getSize().y, "Player 2 Character Select", _selectedShipIndex)), true);
    }
}
