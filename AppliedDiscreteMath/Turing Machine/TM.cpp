
#include "States.h"
#include "TM.h"

TM::TM() {
  // create TM's fsm
  stateMachine = new StateMachine(this);
  // set initial state to FirstState
  stateMachine->setCurrentState(FirstState::Instance());
}

void TM::set_tape(std::vector<char> newTape) { tape = newTape; }

std::vector<char> TM::get_tape() { return tape; }

// clean up
TM::~TM() { delete stateMachine; }

void TM::set_status(int newStatus) { status = newStatus; }

int TM::get_status() { return status; }

// calls update with the statemachine, which executes the current state
void TM::Update() { stateMachine->Update(); }
