#ifndef _STATEMACHINE_
#define _STATEMACHINE_

#include "States.h"

// forward declaration
class TM;

/*============================================================================
==============================================================================
=================================State Machine================================
==============================================================================
==============================================================================*/
class StateMachine {
public:
  // constructor given a TM object
  StateMachine(TM *owner);

  // setCurrentState needs state to set as current
  void setCurrentState(State *entity);
  void Update() const;
  // ChangeState needs new state to change to current state
  void ChangeState(State *newState);

  State *get_currentState();

protected:
  // pointer to current TM and current state instance
  TM *owner;
  State *currentState;
};

#endif
