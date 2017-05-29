#ifndef _TM_
#define _TM_

#include "StateMachine.h"
#include <vector>

/*============================================================================
==============================================================================
====================================  TM  ====================================
==============================================================================
==============================================================================*/

class TM {
public:
  void set_tape(std::vector<char> newTape);
  std::vector<char> get_tape();

  void set_status(int newStatus);
  int get_status();

  // constructor
  TM();
  // destructor
  ~TM();
  void Update();

  // for access to the TM's StateMachine
  StateMachine *getFSM() const { return stateMachine; }

private:
  std::vector<char> tape;
  int status;
  StateMachine *stateMachine;
};

#endif
