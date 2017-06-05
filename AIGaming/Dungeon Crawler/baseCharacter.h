#include "stateMachine.h"
#include <string>
#include <vector>

#ifndef _BASECHARACTER_
#define _BASECHARACTER_

class StateMachine;
/*=============================================================================
===============================================================================
=================================Base Character================================
===============================================================================
=============================================================================*/

class BaseCharacter {
public:
  /*---------------------------------------------------------------------------
  ------------------------------------ Health ---------------------------------
  ----------------------------------------------------------------------------*/
  void set_currentHealth(int newHealth);
  int get_currentHealth();

  void set_maxHealth(int newHealth);
  int get_maxHealth();

  /*---------------------------------------------------------------------------
  --------------------------------- Inventory----------------------------------
  ----------------------------------------------------------------------------*/
  void update_Gold(int newGold);
  int get_Gold();

  /*----------------------------------------------------------------------------
  -------------------------------- Location  -----------------------------------
  ----------------------------------------------------------------------------*/
  void set_currentLocation(int newX, int newY);
  int get_currentX();
  int get_currentY();

  void set_previousLocation(int oldX, int oldY);
  int get_previousX();
  int get_previousY();

  /*----------------------------------------------------------------------------
  --------------------------------- Level  -------------------------------------
  ----------------------------------------------------------------------------*/
  void set_level(int newLevel);
  int get_level();

  /*---------------------------------------------------------------------------
  --------------------------------- Stats  ------------------------------------
  ---------------------------------------------------------------------------*/

  void set_strength(int newStrength);
  int get_strength();

  void set_dexterity(int newDexterity);
  int get_dexterity();

  void set_speed(int newSpeed);
  int get_speed();

  void set_defense(int newDefense);
  int get_defense();

  void set_magic(int newMagic);
  int get_magic();

  void set_healing(int newHealing);
  int get_healing();

  /*---------------------------------------------------------------------------
  --------------------------------- Gameplay ----------------------------------
  ----------------------------------------------------------------------------*/
  void set_inCombat(bool newInCombat);
  bool get_inCombat();

  std::string get_type();

  void set_route(std::string route);
  std::string get_route();

  virtual void Update() = 0;

  virtual StateMachine *getFSM() const = 0;

  bool isPlayer;

protected:
  int currentHealth, maxHealth;
  int x, y, previousX, previousY;
  int level;
  int strength, dexterity, speed, defense, magic, healing;
  bool inCombat;
  int gold;
  std::string type;
  std::string currentRoute;
  StateMachine *stateMachine;
};

#endif
