//
// Created by frangio on 23/05/19.
//

#ifndef THEBINDINGOFZELDAPROJECT_STATEMACHINE_H
#define THEBINDINGOFZELDAPROJECT_STATEMACHINE_H

#include <memory>
#include <stack>

#include "State.h"


typedef std::unique_ptr<State> StateRef;

class StateMachine
{
public:
    StateMachine() { }
    ~StateMachine() { }

    void AddState(StateRef newState, bool isReplacing = true);
    void RemoveState();
    // Run at start of each loop in Game.cpp
    void ProcessStateChanges();

    StateRef &GetActiveState();

private:
    std::stack<StateRef> _states;
    StateRef _newState;

    bool _isRemoving;
    bool _isAdding, _isReplacing;
};
#endif //THEBINDINGOFZELDAPROJECT_STATEMACHINE_H
