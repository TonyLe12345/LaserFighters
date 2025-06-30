#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"

class MainMenuState;

using namespace sf;
using namespace std;

//Game.h runs the game, handles frameRate and Clock, and initialises the GameData struct.

struct GameData
{
    StateMachine machine;
    RenderWindow window;
    AssetManager assets;
    int player1CharacterIndex;
    int player2CharacterIndex;
};
typedef shared_ptr<GameData> GameDataRef;

class Game
{
public:
    Game( int width, int height, string title);

private:
    const float frameRate = 1.0f / 60.0f;
    Clock _clock;

    GameDataRef _data = make_shared<GameData>();

    void Run();
};

