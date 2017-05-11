
#ifndef _STATES_
#define _STATES_

class Player;

/*============================================================================
==============================================================================
==================================  States  ==================================
==============================================================================
==============================================================================*/
// base class for State
class State {
public:
  virtual void enterState() = 0;
  virtual void executeState(Player *player) = 0;
  virtual void exitState() = 0;
};

/*=============================================================================
================================  FirstRoll  ==================================
==============================================================================*/
class FirstRoll : public State {
private:
  int diceOne, diceTwo;

  // constructor
  FirstRoll() {}
  // copy constructor
  FirstRoll(const FirstRoll &);
  // assignment
  FirstRoll &operator=(const FirstRoll &);

public:
  // singleton
  static FirstRoll *Instance();
  virtual void enterState();
  virtual void executeState(Player *player);
  virtual void exitState();
};

/*=============================================================================
============================  FirstDoubleRoll  ================================
==============================================================================*/
class FirstDoubleRoll : public State {
private:
  int diceOne, diceTwo;
  // constructor
  FirstDoubleRoll() {}
  // copy constructor
  FirstDoubleRoll(const FirstDoubleRoll &);
  // assignment
  FirstDoubleRoll &operator=(const FirstDoubleRoll &);

public:
  // singleton
  static FirstDoubleRoll *Instance();
  virtual void enterState();
  virtual void executeState(Player *player);
  virtual void exitState();
};

/*=============================================================================
============================  SecondDoubleRoll  ===============================
==============================================================================*/
class SecondDoubleRoll : public State {
private:
  int diceOne, diceTwo;
  // constructor
  SecondDoubleRoll() {}
  // copy constructor
  SecondDoubleRoll(const SecondDoubleRoll &);
  // assignment
  SecondDoubleRoll &operator=(const SecondDoubleRoll &);

public:
  // singleton
  static SecondDoubleRoll *Instance();
  virtual void enterState();
  virtual void executeState(Player *player);
  virtual void exitState();
};

/*=============================================================================
==================================  EndTurn  ==================================
==============================================================================*/
class EndTurn : public State {
private:
  // constructor
  EndTurn() {}
  // copy constructor
  EndTurn(const EndTurn &);
  // assignment
  EndTurn &operator=(const EndTurn &);

public:
  // singleton
  static EndTurn *Instance();
  virtual void enterState();
  virtual void executeState(Player *player);
  virtual void exitState();
};

/*=============================================================================
=================================  GoToJail  ==================================
==============================================================================*/
class GoToJail : public State {
private:
  // constructor
  GoToJail() {}
  // copy constructor
  GoToJail(const GoToJail &);
  // assignment
  GoToJail &operator=(const GoToJail &);

public:
  // singleton
  static GoToJail *Instance();
  virtual void enterState();
  virtual void executeState(Player *player);
  virtual void exitState();
};

#endif
