#pragma once

// virtual function that the StateMachine and various game states use

class GameState
{
public:
    virtual void Init() = 0;            // initialize the state
    virtual void HandleInput() = 0;     // handle all inputs in the state
    virtual void Update( float frameRate) = 0; // update any variables
    virtual void Draw(float frameRate) = 0; // draws the frames

    virtual void Pause() {}             // pause the game
    virtual void Resume() {}            // resume the game
};