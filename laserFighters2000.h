#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "player.h"
#include "Game.h"
#include <string>
#include "Ship.h"



class laserFighters2000 : public GameState
{
public:
    laserFighters2000(GameDataRef data, int x, int y, std::string title, int _player1CharacterIndex, int _player2CharacterIndex);
    ~laserFighters2000();

    void Init();
    void HandleInput();
    void Update(float frameRate);
    void Draw(float frameRate);


private:
    GameDataRef _data;
    sf::RenderWindow* windo;
    player* player1;
    player* player2;
    sf::Sprite _background;
    int _player1CharacterIndex;;
    int _player2CharacterIndex;;
};
