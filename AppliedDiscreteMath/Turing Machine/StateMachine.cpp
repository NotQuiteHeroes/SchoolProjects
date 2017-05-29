
#include "StateMachine.h"

/*============================================================================
==============================================================================
=================================State Machine================================
==============================================================================
==============================================================================*/

StateMachine::StateMachine(TM *currentOwner) {
  // pointer to TM object as owner of state machine
  owner = currentOwner;

  // current state null
  currentState = 0;
}

void StateMachine::setCurrentState(State *entity) { currentState = entity; }
State *StateMachine::get_currentState() { return currentState; }

void StateMachine::Update() const {
  // execute current state
  if (currentState) {
    currentState->executeState(owner);
  }
}

void StateMachine::ChangeState(State *newState) {
  // call exit state of current state
  currentState->exitState();
  // change current state to new state
  currentState = newState;
  // call enter state of new state
  currentState->enterState();
}
