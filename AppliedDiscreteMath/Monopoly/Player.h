#ifndef _PLAYER_
#define _PLAYER_

#include "StateMachine.h"

/*============================================================================
==============================================================================
==================================  Player  ==================================
==============================================================================
==============================================================================*/
class Player {
private:
  // player owned instance of a statemachine
  StateMachine *stateMachine;

public:
  // constructor
  Player();
  // destructor
  ~Player();
  void Update();

  // for access to the player's StateMachine
  StateMachine *getFSM() const { return stateMachine; }
};

#endif
