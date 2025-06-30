#pragma once

#include <memory>
#include <stack>


#include "GameState.h"

typedef std::unique_ptr<GameState> StateRef;

class StateMachine
{
public:
    StateMachine() {}
    ~StateMachine() {}

    //Adds a state on to the stack, pausing other states (unless replacing)
    void AddState( StateRef newState, bool isReplacing = true);

    //manually remove state
    void RemoveState();

    //runs at the start of each loop
    void ProcessStateChanges();

    //returns top level state
    StateRef &GetActiveState();

private:
    //All states on stack
    std::stack<StateRef> _states;

    //Latest state to add
    StateRef _newState;

    bool _isRemoving;
    bool _isAdding;
    bool _isReplacing;

};