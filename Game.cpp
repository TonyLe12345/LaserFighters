#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "Game.h"
#include "MainMenuState.h"


using namespace sf;
using namespace std;

Game::Game( int width, int height, string title)
{
    _data->window.create( VideoMode(width, height),
    title, Style::Close | Style::Titlebar);
    _data->machine.AddState( StateRef(new MainMenuState(this->_data)));

    this->Run();
}

void Game::Run()
{
    float newTime, frameTime, interpolation;

    float currentTime = this->_clock.getElapsedTime().asSeconds();

    float accumulator = 0.0f;

    while ( this->_data->window.isOpen())
    {
        this->_data->machine.ProcessStateChanges();

        newTime = this->_clock.getElapsedTime().asSeconds();

        frameTime  = newTime - currentTime;

        if (frameTime > 0.25f)
        {
            frameTime = 0.25f;
        }

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= frameRate)
        {
            this ->_data->machine.GetActiveState()->
                HandleInput();
            this->_data->machine.GetActiveState()->
                Update(frameRate);
            
            accumulator -= frameRate;
        }
        interpolation = accumulator / frameRate;
        this->_data->machine.GetActiveState()->
            Draw(interpolation);
    }

}