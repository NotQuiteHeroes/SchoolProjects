#include "stateMachine.h"
#include "states.h"

/*============================================================================
==============================================================================
=================================State Machine================================
==============================================================================
==============================================================================*/
StateMachine::StateMachine(BaseCharacter *currentOwner) {
  owner = currentOwner;
  currentState = 0;
  previousState = 0;
}
void StateMachine::setCurrentState(State *entity) { currentState = entity; }
State *StateMachine::get_currentState() { return currentState; }

void StateMachine::setPreviousState(State *entity) { previousState = entity; }
State *StateMachine::get_previousState() { return previousState; }

void StateMachine::Update() const {
  if (currentState) {
    currentState->executeState(owner);
  }
}
void StateMachine::changeState(State *newState) {
  previousState = currentState;
  currentState->exitState(owner);
  currentState = newState;
  currentState->enterState(owner);
}
void StateMachine::revertState() { changeState(previousState); }
