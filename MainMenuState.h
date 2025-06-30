#pragma once

#include "GameState.h"
#include "Game.h"


#include "DEFINITIONS.h"

class MainMenuState : public GameState
{
public:
    MainMenuState(GameDataRef data);

    void Init() ;
    void HandleInput() ;
    void Update(float frameRate) ;
    void Draw(float frameRate) ;

private:
    GameDataRef _data;
    sf::Sprite _background;
    sf::Text _title;
    sf::Text _playButton;
    sf::Text _exitButton;

    int _selectedItemIndex;
    void MoveUp();
    void MoveDown();
    void SelectItem();
};
