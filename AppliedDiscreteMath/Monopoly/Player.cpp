#include "Player.h"
#include "StateMachine.h"
#include "States.h"

Player::Player() {
  // create player's fsm
  stateMachine = new StateMachine(this);
  // set initial state to FirstRoll
  stateMachine->setCurrentState(FirstRoll::Instance());
}
// clean up
Player::~Player() { delete stateMachine; }
// calls update with the statemachine, which executes the current state
void Player::Update() { stateMachine->Update(); }
