//#include "baseCharacter.h"

#ifndef _STATES_
#define _STATES_

/*=============================================================================
===============================================================================
===================================  State  ===================================
===============================================================================
==============================================================================*/
class State {
public:
  virtual void enterState(BaseCharacter *) = 0;
  virtual void executeState(BaseCharacter *) = 0;
  virtual void exitState(BaseCharacter *) = 0;

  virtual ~State() {}
};

/*=============================================================================
===============================================================================
===================================  Attack  ==================================
===============================================================================
==============================================================================*/

class Attack : public State {
public:
  virtual void enterState(BaseCharacter *character);
};
/*-----------------------------------------------------------------------------
----------------------------------Magic Attack---------------------------------
-----------------------------------------------------------------------------*/
class MagicAttack : public Attack {
public:
  static MagicAttack *Instance();
  virtual void enterState(BaseCharacter *character);
  virtual void executeState(BaseCharacter *character);
  virtual void exitState(BaseCharacter *character);

private:
  MagicAttack() {}
  MagicAttack(const MagicAttack &);
  MagicAttack &operator=(const MagicAttack &);
};

/*-----------------------------------------------------------------------------
----------------------------------Melee Attack---------------------------------
-----------------------------------------------------------------------------*/
class MeleeAttack : public Attack {
public:
  static MeleeAttack *Instance();
  virtual void enterState(BaseCharacter *character);
  virtual void executeState(BaseCharacter *character);
  virtual void exitState(BaseCharacter *character);

private:
  MeleeAttack() {}
  MeleeAttack(const MeleeAttack &);
  MeleeAttack &operator=(const MeleeAttack &);
};
/*-----------------------------------------------------------------------------
----------------------------------Sneak Attack---------------------------------
-----------------------------------------------------------------------------*/
class SneakAttack : public Attack {
public:
  static SneakAttack *Instance();
  virtual void enterState(BaseCharacter *character);
  virtual void executeState(BaseCharacter *character);
  virtual void exitState(BaseCharacter *character);

private:
  SneakAttack() {}
  SneakAttack(const SneakAttack &);
  SneakAttack &operator=(const SneakAttack &);
};

/*=============================================================================
===============================================================================
=====================================  Wander  ================================
===============================================================================
==============================================================================*/

class Wander : public State {
public:
  virtual void enterState(BaseCharacter *character);
};

/*-----------------------------------------------------------------------------
--------------------------------Player Wander----------------------------------
-----------------------------------------------------------------------------*/
class PlayerWander : public Wander {
public:
  static PlayerWander *Instance();
  virtual void enterState(BaseCharacter *character);
  virtual void executeState(BaseCharacter *character);
  virtual void exitState(BaseCharacter *character);

private:
  PlayerWander() {}
  PlayerWander(const PlayerWander &);
  PlayerWander &operator=(const PlayerWander &);
};
/*-----------------------------------------------------------------------------
------------------------------Search for Enemy---------------------------------
-----------------------------------------------------------------------------*/
class SearchForEnemy : public Wander {
public:
  static SearchForEnemy *Instance();
  virtual void enterState(BaseCharacter *character);
  virtual void executeState(BaseCharacter *character);
  virtual void exitState(BaseCharacter *character);

private:
  SearchForEnemy() {}
  SearchForEnemy(const SearchForEnemy &);
  SearchForEnemy &operator=(const SearchForEnemy &);
};

/*-----------------------------------------------------------------------------
---------------------------Search for Treasure---------------------------------
-----------------------------------------------------------------------------*/
class SearchForTreasure : public Wander {
public:
  static SearchForTreasure *Instance();
  virtual void enterState(BaseCharacter *character);
  virtual void executeState(BaseCharacter *character);
  virtual void exitState(BaseCharacter *character);

private:
  SearchForTreasure() {}
  SearchForTreasure(const SearchForTreasure &);
  SearchForTreasure &operator=(const SearchForTreasure &);
};

/*=============================================================================
===============================================================================
=====================================  Death  =================================
===============================================================================
==============================================================================*/

class Death : public State {
public:
  static Death *Instance();
  virtual void enterState(BaseCharacter *character);
  virtual void executeState(BaseCharacter *character);
  virtual void exitState(BaseCharacter *character);

private:
  Death() {}
  Death(const Death &);
  Death &operator=(const Death &);
};

/*=============================================================================
===============================================================================
==================================  End Turn  =================================
===============================================================================
==============================================================================*/

class EndTurn : public State {
public:
  static EndTurn *Instance();
  virtual void enterState(BaseCharacter *character);
  virtual void executeState(BaseCharacter *character);
  virtual void exitState(BaseCharacter *character);

private:
  EndTurn() {}
  EndTurn(const EndTurn &);
  EndTurn &operator=(const EndTurn &);
};

#endif
