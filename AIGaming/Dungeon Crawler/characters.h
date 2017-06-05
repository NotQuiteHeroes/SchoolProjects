#include "stateMachine.h"

#ifndef _CHARACTERS_
#define _CHARACTERS_

/*=============================================================================
===============================================================================
=================================  Characters  ================================
===============================================================================
=============================================================================*/

/*-----------------------------------------------------------------------------
---------------------------------  Player  ------------------------------------
-----------------------------------------------------------------------------*/
class Player : public BaseCharacter {
public:
  Player(int pLevel, std::string type);
  ~Player();
  void Update();
  StateMachine *getFSM() const { return stateMachine; }

protected:
  StateMachine *stateMachine;
};

/*-----------------------------------------------------------------------------
---------------------------------  Barbarian  ---------------------------------
-----------------------------------------------------------------------------*/
class Barbarian : public BaseCharacter {
public:
  Barbarian(int pLevel);
  ~Barbarian();
  void Update();
  StateMachine *getFSM() const { return stateMachine; }

protected:
  StateMachine *stateMachine;
};

/*-----------------------------------------------------------------------------
-----------------------------------  Elf  -------------------------------------
-----------------------------------------------------------------------------*/
class Elf : public BaseCharacter {
public:
  Elf(int pLevel);
  ~Elf();
  void Update();
  StateMachine *getFSM() const { return stateMachine; }

protected:
  StateMachine *stateMachine;
};

/*-----------------------------------------------------------------------------
---------------------------------  Goblin  ------------------------------------
-----------------------------------------------------------------------------*/
class Goblin : public BaseCharacter {
public:
  Goblin(int pLevel);
  ~Goblin();
  void Update();
  StateMachine *getFSM() const { return stateMachine; }

protected:
  StateMachine *stateMachine;
};

/*-----------------------------------------------------------------------------
---------------------------------  Wizard  ------------------------------------
-----------------------------------------------------------------------------*/
class Wizard : public BaseCharacter {
public:
  Wizard(int pLevel);
  ~Wizard();
  void Update();
  StateMachine *getFSM() const { return stateMachine; }

protected:
  StateMachine *stateMachine;
};

#endif
