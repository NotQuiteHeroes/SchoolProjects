#include "States.h"
#include "TM.h"
#include <algorithm>
#include <iostream>

/*=============================================================================
================================  FirstState  ==================================
==============================================================================*/

FirstState *FirstState::Instance() {
  static FirstState instance;
  return &instance;
}

void FirstState::enterState() {}

void FirstState::executeState(TM *tm) {
  std::vector<char> tempTape;
  std::cout
      << "Enter the string one letter at a time, pressing enter after each. "
         "Enter 'x' when done.\n";
  char input = 'S';
  // enter input until user enters an 'x'
  while (input != 'x') {
    std::cin >> input;
    tempTape.push_back(input);
  }
  // delete 'x' character from tape
  tempTape.pop_back();

  tm->set_tape(tempTape);

  // count of occurrences of each character
  int aCount = std::count(tempTape.begin(), tempTape.end(), 'a');
  int bCount = std::count(tempTape.begin(), tempTape.end(), 'b');
  int cCount = std::count(tempTape.begin(), tempTape.end(), 'c');

  // if the tape doesn't start with an a, then it doesn't meet the Language
  // criteria, reject it.
  // Also must be at least four characters long to meet Language criteria, so if
  // less than 4, reject it.
  // Also must have at least one a, one b, and one c to meet criteria, if not
  // reject it
  if (tempTape.at(0) != 'a' || tempTape.size() < 4 || aCount < 1 ||
      bCount < 1 || cCount < 1) {
    tm->getFSM()->ChangeState(Reject::Instance());
  } else {
    // otherwise, find and mark A
    tm->getFSM()->ChangeState(FindA::Instance());
  }
}

void FirstState::exitState() {}

/*=============================================================================
==================================  FindA  ====================================
==============================================================================*/

FindA *FindA::Instance() {
  static FindA instance;
  return &instance;
}

void FindA::enterState() {}

void FindA::executeState(TM *tm) {
  std::vector<char> tempTape = tm->get_tape();
  // find instance of 'a', change to 'A' to mark off
  for (int i = 0; i < tempTape.size(); i++) {
    if (tempTape.at(i) == 'a') {
      tempTape.at(i) = 'A';
      break;
    }
  }

  tm->set_tape(tempTape);

  int aCount = std::count(tempTape.begin(), tempTape.end(), 'a');
  int cCount = std::count(tempTape.begin(), tempTape.end(), 'c');

  // if no more a's and c's, evaluate tape
  if (aCount < 1 && cCount < 1) {
    tm->getFSM()->ChangeState(EvaluateTape::Instance());
  } else {
    // otherwise, find next b
    tm->getFSM()->ChangeState(FindB::Instance());
  }
}

void FindA::exitState() {}

/*=============================================================================
================================  FindB  ======================================
==============================================================================*/

FindB *FindB::Instance() {
  static FindB instance;
  return &instance;
}

void FindB::enterState() {}

void FindB::executeState(TM *tm) {
  std::vector<char> tempTape = tm->get_tape();
  // find instance of 'b' and change to 'B' to mark off
  for (int i = 0; i < tempTape.size(); i++) {
    if (tempTape.at(i) == 'b') {
      tempTape.at(i) = 'B';
      break;
    }
  }

  tm->set_tape(tempTape);

  int cCount = std::count(tempTape.begin(), tempTape.end(), 'c');

  // if no more c's, evaluate tape
  if (cCount < 1) {
    tm->getFSM()->ChangeState(EvaluateTape::Instance());
  } else {
    // otherwise, find next c
    tm->getFSM()->ChangeState(FindC::Instance());
  }
}

void FindB::exitState() {}

/*=============================================================================
===================================  FindC  ===================================
==============================================================================*/

FindC *FindC::Instance() {
  static FindC instance;
  return &instance;
}
void FindC::enterState() {}

void FindC::executeState(TM *tm) {
  std::vector<char> tempTape = tm->get_tape();
  // find 'c' and change to 'C' to mark it off
  for (int i = 0; i < tempTape.size(); i++) {
    if (tempTape.at(i) == 'c') {
      tempTape.at(i) = 'C';
      break;
    }
  }

  tm->set_tape(tempTape);

  int aCount = std::count(tempTape.begin(), tempTape.end(), 'a');

  // if no more a's, evaluate tape
  if (aCount < 1) {
    tm->getFSM()->ChangeState(EvaluateTape::Instance());
  } else {
    // otherwise, find next 'a'
    tm->getFSM()->ChangeState(FindA::Instance());
  }
}
void FindC::exitState() {}

/*=============================================================================
=================================  Accept  ====================================
==============================================================================*/
Accept *Accept::Instance() {
  static Accept instance;
  return &instance;
}

void Accept::enterState() { std::cout << "Tape Accepted." << std::endl; }
void Accept::executeState(TM *tm) {
  // change status to done
  tm->set_status(1);
}
void Accept::exitState() {}
/*=============================================================================
=================================  Reject  ====================================
==============================================================================*/

Reject *Reject::Instance() {
  static Reject instance;
  return &instance;
}

void Reject::enterState() { std::cout << "Tape Rejected." << std::endl; }
void Reject::executeState(TM *tm) {
  // change status to done
  tm->set_status(1);
}
void Reject::exitState() {}

/*=============================================================================
=============================  EvaluateTape  ==================================
==============================================================================*/

EvaluateTape *EvaluateTape::Instance() {
  static EvaluateTape instance;
  return &instance;
}

void EvaluateTape::enterState() {}
void EvaluateTape::executeState(TM *tm) {
  std::vector<char> tape = tm->get_tape();
  bool passes = true;

  // occurrences of each character
  int aCount = (std::count(tape.begin(), tape.end(), 'A') +
                (std::count(tape.begin(), tape.end(), 'a')));
  int bCount = (std::count(tape.begin(), tape.end(), 'B') +
                (std::count(tape.begin(), tape.end(), 'b')));
  int cCount = (std::count(tape.begin(), tape.end(), 'C') +
                (std::count(tape.begin(), tape.end(), 'c')));

  // if a and c don't occur at the same rate, or if b occurs at the same rate as
  // a, then reject
  if (aCount != cCount || bCount == aCount) {
    passes = false;
    tm->getFSM()->ChangeState(Reject::Instance());
  }

  int aMax = 0, bMax = 0, cMax = 0;
  int aMin = 100, bMin = 100, cMin = 100;

  // find first and last occurrence of each letter
  for (int i = 0; i < tape.size(); i++) {
    if (tape.at(i) == 'a' || tape.at(i) == 'A') {
      if (i > aMax) {
        aMax = i;
      }
      if (i < aMin) {
        aMin = i;
      }
    } else if (tape.at(i) == 'b' || tape.at(i) == 'B') {
      if (i > bMax) {
        bMax = i;
      }
      if (i < bMin) {
        bMin = i;
      }
    } else if (tape.at(i) == 'c' || tape.at(i) == 'C') {
      if (i > cMax) {
        cMax = i;
      }
      if (i < cMin) {
        cMin = i;
      }
    }
  }

  // if last occurrence of a happens after first occurrence of b or c, reject it
  if (aMax > bMin || aMax > cMin) {
    passes = false;
    tm->getFSM()->ChangeState(Reject::Instance());
  }
  // if first occurrence of b happens before last occurrence of a, or last
  // occurrence of b happens after first occurrence of c, reject it
  if (bMin < aMax || bMax > cMin) {
    passes = false;
    tm->getFSM()->ChangeState(Reject::Instance());
  }
  // if first occurrence of c happens after last occurrence of a, or first
  // occurrence of c happens before last occurrence of b, reject it
  if (cMin < aMax || cMin < bMax) {
    passes = false;
    tm->getFSM()->ChangeState(Reject::Instance());
  }

  // if all tests passed, accept it
  if (passes == true) {
    tm->getFSM()->ChangeState(Accept::Instance());
  }
}

void EvaluateTape::exitState() {}
