#include "Player.h"
#include "States.h"
#include <algorithm>
#include <ctime>
#include <iostream>

/*=============================================================================
================================  FirstRoll  ==================================
==============================================================================*/

FirstRoll *FirstRoll::Instance() {
  static FirstRoll instance;
  return &instance;
}

void FirstRoll::enterState() { std::cout << "First Roll: " << std::endl; }

void FirstRoll::executeState(Player *player) {
  diceOne = rand() % 6 + 1;
  diceTwo = rand() % 6 + 1;
  std::cout << diceOne << std::endl;
  std::cout << diceTwo << std::endl;

  if (diceOne == diceTwo) {
    std::cout << "Doubles!" << std::endl;
    player->getFSM()->ChangeState(FirstDoubleRoll::Instance());
  } else {
    player->getFSM()->ChangeState(EndTurn::Instance());
  }
}

void FirstRoll::exitState() {
  std::cout << "Moving " << diceOne + diceTwo << " spaces." << std::endl;
}

/*=============================================================================
============================  FirstDoubleRoll  ================================
==============================================================================*/

FirstDoubleRoll *FirstDoubleRoll::Instance() {
  static FirstDoubleRoll instance;
  return &instance;
}

void FirstDoubleRoll::enterState() {
  std::cout << "First Doubles Roll: " << std::endl;
}

void FirstDoubleRoll::executeState(Player *player) {
  diceOne = rand() % 6 + 1;
  diceTwo = rand() % 6 + 1;
  std::cout << diceOne << std::endl;
  std::cout << diceTwo << std::endl;

  if (diceOne == diceTwo) {
    std::cout << "Doubles again!" << std::endl;
    player->getFSM()->ChangeState(SecondDoubleRoll::Instance());
  } else {
    player->getFSM()->ChangeState(EndTurn::Instance());
  }
}

void FirstDoubleRoll::exitState() {
  std::cout << "Moving " << diceOne + diceTwo << " spaces." << std::endl;
}

/*=============================================================================
============================  SecondDoubleRoll  ===============================
==============================================================================*/

SecondDoubleRoll *SecondDoubleRoll::Instance() {
  static SecondDoubleRoll instance;
  return &instance;
}

void SecondDoubleRoll::enterState() {
  std::cout << "Second Doubles Roll: " << std::endl;
}

void SecondDoubleRoll::executeState(Player *player) {
  diceOne = rand() % 6 + 1;
  diceTwo = rand() % 6 + 1;
  std::cout << diceOne << std::endl;
  std::cout << diceTwo << std::endl;

  if (diceOne == diceTwo) {
    std::cout << "Oh no! Doubles three in a row!" << std::endl;
    player->getFSM()->ChangeState(GoToJail::Instance());
  } else {
    std::cout << "Moving " << diceOne + diceTwo << " spaces." << std::endl;
    player->getFSM()->ChangeState(EndTurn::Instance());
  }
}

void SecondDoubleRoll::exitState() {}

/*=============================================================================
==================================  EndTurn  ==================================
==============================================================================*/

EndTurn *EndTurn::Instance() {
  static EndTurn instance;
  return &instance;
}
void EndTurn::enterState() { std::cout << "End of turn." << std::endl; }

void EndTurn::executeState(Player *player) {}
void EndTurn::exitState() {}

/*=============================================================================
=================================  GoToJail  ==================================
==============================================================================*/

GoToJail *GoToJail::Instance() {
  static GoToJail instance;
  return &instance;
}

void GoToJail::enterState() { std::cout << "GO TO JAIL!" << std::endl; }
void GoToJail::executeState(Player *player) {
  player->getFSM()->ChangeState(EndTurn::Instance());
}
void GoToJail::exitState() {}
