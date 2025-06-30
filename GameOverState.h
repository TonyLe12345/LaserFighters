#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Game.h"

class GameOverState : public GameState
{
public:
    GameOverState(GameDataRef data, const std::string& winner);

    void Init();
    void HandleInput();
    void Update(float dt);
    void Draw(float dt);

private:
    GameDataRef _data;
    sf::Text _gameOverText;
    sf::Text _instructionText;
    sf::Font _font;
    std::string _winner;
    sf::Sprite _background;
};
