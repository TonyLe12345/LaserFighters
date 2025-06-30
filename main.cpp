#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "StateMachine.h"
#include "Game.h"
#include "AssetManager.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"


int main()
{
    Game(SCREEN_WIDTH,SCREEN_HEIGHT, "Laser Fighters 2000");
    return EXIT_SUCCESS;
}