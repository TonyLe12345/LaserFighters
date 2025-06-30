#pragma once

#include "GameState.h"
#include "Game.h"


#include "DEFINITIONS.h"

class CharacterSelectP2 : public GameState
{
public:
    CharacterSelectP2(GameDataRef data, int x, int y, std::string title, int player1Choice);

    void Init() ;
    void HandleInput() ;
    void Update(float frameRate) ;
    void Draw(float frameRate) ;

private:
    GameDataRef _data;
    sf::Sprite _background;
    sf::Text _player;
    sf::Text _Goliath;
    sf::Text _Flea;
    sf::Text _Arachne;
    int player1Choice;

    int _selectedShipIndex;
    
    void MoveLeft();
    void MoveRight();
    void SelectItem();
};
