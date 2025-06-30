#include "StateMachine.h"

//The function of StateMachine is to control what state the game is in.
//eg. Starts at MainMenu and then goes to state laserFighters2000 when the play button is pressed

void StateMachine::AddState( StateRef newState, bool isReplacing )
{
    this->_isAdding = true;
    this->_isReplacing = isReplacing;

    this->_newState = std::move( newState );
}

void StateMachine::RemoveState()
{
    this->_isRemoving = true;
}


void StateMachine::ProcessStateChanges()
{
    if ( this->_isRemoving && !this->_states.empty() )
    {
        this->_states.pop();

        if ( !this->_states.empty())
        {
            //If top state not empty. resume next state
            this->_states.top( )->Resume();
        }

        this->_isRemoving = false;

    }

    //check if we need to add a new state
    if (this->_isAdding)
    {

        //If the stack isn't empty, either pop the 
        //current state or pause the current state
        if ( !this->_states.empty())
        {
            if (this->_isReplacing)
            {
                this->_states.pop();
            }
            else
            {
                this->_states.top()->Pause();
            }
        }

        //Add the new state and initialise it. Update _isAdding.
        this->_states.push( std::move( this->_newState));
        this->_states.top()->Init();
        this->_isAdding = false;
    }
}

StateRef &StateMachine::GetActiveState()
{
    return this->_states.top();
}


