#ifndef _STATEMACHINE_
#define _STATEMACHINE_

#include "States.h"

// forward declaration
class Player;

/*============================================================================
==============================================================================
=================================State Machine================================
==============================================================================
==============================================================================*/
class StateMachine {
public:
  // constructor given a Player object
  StateMachine(Player *owner);

  // setCurrentState needs state to set as current
  void setCurrentState(State *entity);
  void Update() const;
  // ChangeState needs new state to change to current state
  void ChangeState(State *newState);

  State *get_currentState();

protected:
  // pointer to current player and current state instance
  Player *owner;
  State *currentState;
};

#endif
