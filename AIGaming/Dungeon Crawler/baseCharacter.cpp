#include "baseCharacter.h"
#include <algorithm>

/*=============================================================================
===============================================================================
===============================  Base Character  ==============================
===============================================================================
=============================================================================*/

/*-----------------------------------------------------------------------------
-----------------------------  Health Functions  ------------------------------
------------------------------------------------------------------------------*/
void BaseCharacter::set_currentHealth(int newHealth) {
  currentHealth += newHealth;
}

int BaseCharacter::get_currentHealth() { return currentHealth; }

void BaseCharacter::set_maxHealth(int newHealth) { maxHealth += newHealth; }
int BaseCharacter::get_maxHealth() { return maxHealth; }

/*-----------------------------------------------------------------------------
----------------------------  Inventory Functions  ----------------------------
------------------------------------------------------------------------------*/

void BaseCharacter::update_Gold(int newGold) { gold += newGold; }
int BaseCharacter::get_Gold() { return gold; }

/*-----------------------------------------------------------------------------
-------------------------------Location Functions------------------------------
-----------------------------------------------------------------------------*/
void BaseCharacter::set_currentLocation(int newX, int newY) {
  x = newX;
  y = newY;
}
int BaseCharacter::get_currentX() { return x; }
int BaseCharacter::get_currentY() { return y; }

void BaseCharacter::set_previousLocation(int oldX, int oldY) {
  previousX = oldX;
  previousY = oldY;
}

int BaseCharacter::get_previousX() { return previousX; }
int BaseCharacter::get_previousY() { return previousY; }

/*-----------------------------------------------------------------------------
--------------------------------Level Functions--------------------------------
-----------------------------------------------------------------------------*/
void BaseCharacter::set_level(int newLevel) { level += newLevel; }
int BaseCharacter::get_level() { return level; }

/*-----------------------------------------------------------------------------
----------------------------------Stat Functions-------------------------------
-----------------------------------------------------------------------------*/

void BaseCharacter::set_strength(int newStrength) { strength += newStrength; }
int BaseCharacter::get_strength() { return strength; }

void BaseCharacter::set_dexterity(int newDexterity) {
  dexterity += newDexterity;
}
int BaseCharacter::get_dexterity() { return dexterity; }

void BaseCharacter::set_speed(int newSpeed) { speed += newSpeed; }
int BaseCharacter::get_speed() { return speed; }

void BaseCharacter::set_defense(int newDefense) { defense += newDefense; }
int BaseCharacter::get_defense() { return defense; }

void BaseCharacter::set_magic(int newMagic) { magic += newMagic; }
int BaseCharacter::get_magic() { return magic; }

void BaseCharacter::set_healing(int newHealing) { healing += newHealing; }
int BaseCharacter::get_healing() { return healing; }

/*-----------------------------------------------------------------------------
----------------------------------Game Play------------------------------------
-----------------------------------------------------------------------------*/

std::string BaseCharacter::get_type() { return type; }

void BaseCharacter::set_route(std::string route) { currentRoute = route; }
std::string BaseCharacter::get_route() { return currentRoute; }
