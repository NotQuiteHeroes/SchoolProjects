#ifndef _STATEMACHINE_
#define _STATEMACHINE_

#include "baseCharacter.h"
#include "states.h"

/*============================================================================
==============================================================================
=================================State Machine================================
==============================================================================
==============================================================================*/
class StateMachine {
public:
  StateMachine(BaseCharacter *owner);
  void setCurrentState(State *entity);
  void setPreviousState(State *entity);
  void Update() const;
  void changeState(State *newState);
  void revertState();

  State *get_currentState();
  State *get_previousState();

protected:
  BaseCharacter *owner;
  State *currentState;
  State *previousState;
};

#endif
