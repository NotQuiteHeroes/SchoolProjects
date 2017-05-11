#include "Player.h"
#include "StateMachine.h"
#include "States.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  // seed time for random calls in states.cpp
  srand(time(0));

  // create player object
  Player *player = new Player();

  // while the current state isn't endturn, update the FSM
  while (player->getFSM()->get_currentState() != EndTurn::Instance()) {
    player->Update();
  }
}
