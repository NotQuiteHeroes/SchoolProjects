#include "gamePlay.h"
#include "map.h"
#include "states.h"
#include <iostream>
#include <string>

/*=============================================================================
===============================================================================
================================== Attack =====================================
===============================================================================
=============================================================================*/

void Attack::enterState(BaseCharacter *character) {
  GamePlay::Instance()->checkHealthStatus(character);
  // get enemy for character
  BaseCharacter *enemy = GamePlay::Instance()->get_enemy(character);

  std::cout << character->get_type() << " enters battle with "
            << enemy->get_type() << std::endl;
}

/*-----------------------------------------------------------------------------
--------------------------------- Magic Attack --------------------------------
-----------------------------------------------------------------------------*/
MagicAttack *MagicAttack::Instance() {
  static MagicAttack instance;
  return &instance;
}
void MagicAttack::enterState(BaseCharacter *character) {
  Attack::enterState(character);
  std::cout << "Magic Attack!\n";
}

void MagicAttack::executeState(BaseCharacter *character) {
  // roll to determine if attack lands or misses
  int attackRoll = GamePlay::Instance()->roll(1, 20);

  // get character's enemy
  BaseCharacter *enemy = GamePlay::Instance()->get_enemy(character);

  if (attackRoll == 1) {
    // critical miss, damages self
    character->set_currentHealth(-attackRoll);
    std::cout << character->get_type() << ": Critical miss!\n";
    // if attackRoll is greater than enemy's defense, its a hit
  } else if (attackRoll > enemy->get_defense()) {
    std::cout << character->get_type() << ": Hit! Deals " << enemy->get_type()
              << character->get_magic() << " damage!\n";
    enemy->set_currentHealth(-(character->get_magic()));
    // if attackRoll is less than enemy's defense, miss
  } else {
    std::cout << character->get_type() << ": Miss!";
  }

  // check character's health to determine if need to search for health
  // or change to death state
  GamePlay::Instance()->checkHealthStatus(character);

  character->getFSM()->changeState(EndTurn::Instance());
}

void MagicAttack::exitState(BaseCharacter *character) {}

/*-----------------------------------------------------------------------------
---------------------------------- Melee Attack -------------------------------
-----------------------------------------------------------------------------*/
MeleeAttack *MeleeAttack::Instance() {
  static MeleeAttack instance;
  return &instance;
}

void MeleeAttack::enterState(BaseCharacter *character) {
  Attack::enterState(character);
  std::cout << "Melee Attack!\n";
}

void MeleeAttack::executeState(BaseCharacter *character) {
  // roll to determine if attack hits or misses
  int attackRoll = GamePlay::Instance()->roll(1, 20);

  // get character's enemy
  BaseCharacter *enemy = GamePlay::Instance()->get_enemy(character);

  // critical miss damages self
  if (attackRoll == 1) {
    character->set_currentHealth(-attackRoll);
    // if attackRoll is greater than enemy's defense, then its a hit
  } else if (attackRoll > enemy->get_defense()) {
    std::cout << character->get_type() << ": Hit! Deals " << enemy->get_type()
              << " " << character->get_strength() << " damage!\n";
    enemy->set_currentHealth(-(character->get_strength()));
    // if attackRoll is not greater than enemy's defense, its a miss
  } else {
    std::cout << character->get_type() << ": Miss!\n";
  }

  // check character and enemy health to see if change state should be to
  // search
  // for health or death state
  GamePlay::Instance()->checkHealthStatus(character);

  character->getFSM()->changeState(EndTurn::Instance());
}

void MeleeAttack::exitState(BaseCharacter *character) {}

/*-----------------------------------------------------------------------------
--------------------------------- Sneak Attack --------------------------------
-----------------------------------------------------------------------------*/

SneakAttack *SneakAttack::Instance() {
  static SneakAttack instance;
  return &instance;
}

void SneakAttack::enterState(BaseCharacter *character) {
  Attack::enterState(character);
  std::cout << "Sneak Attack!\n";
  // attackRoll to determine if attack hits or misses
  int attackRoll = GamePlay::Instance()->roll(1, 20);

  // get character's enemy
  BaseCharacter *enemy = GamePlay::Instance()->get_enemy(character);

  // critical miss damages self
  if (attackRoll == 1) {
    std::cout << character->get_type() << ": Critical miss!" << std::endl;
    character->set_currentHealth(-attackRoll);
    // if attackRoll is greater than enemy's defense, its a hit
  } else if (attackRoll > enemy->get_defense()) {
    std::cout << character->get_type() << ": Hit! Deals " << enemy->get_type()
              << " " << character->get_dexterity() << " damage!\n";
    enemy->set_currentHealth(-(character->get_dexterity()));
    // if attackRoll is not greater than enemy's defense, its a miss
  } else {
    std::cout << character->get_type() << ": Miss!\n";
  }

  // check character and enemy health to determine if state should change to
  // search for health or death
  GamePlay::Instance()->checkHealthStatus(character);

  character->getFSM()->changeState(EndTurn::Instance());
}

void SneakAttack::executeState(BaseCharacter *character) {}

void SneakAttack::exitState(BaseCharacter *character) {}

/*=============================================================================
===============================================================================
==================================== Wander ===================================
===============================================================================
==============================================================================*/
void Wander::enterState(BaseCharacter *character) {
  std::cout << character->get_type() << ": On the move.\n";
}

/*-----------------------------------------------------------------------------
--------------------------------Player Wander----------------------------------
-----------------------------------------------------------------------------*/

PlayerWander *PlayerWander::Instance() {
  static PlayerWander instance;
  return &instance;
}

void PlayerWander::enterState(BaseCharacter *character) {
  Wander::enterState(character);
}

void PlayerWander::executeState(BaseCharacter *character) {
  int remainingMoves = character->get_speed();
  std::string move;
  int pos;

  if (character->get_type() == "Barbarian") {
    pos = 0;
  } else if (character->get_type() == "Elf") {
    pos = 1;
  } else if (character->get_type() == "Goblin") {
    pos = 2;
  } else if (character->get_type() == "Wizard") {
    pos = 3;
  }

  while (remainingMoves > 0) {
    std::cout << "You have " << remainingMoves << " remaining.\n";
    std::cin >> move;
    // move north
    if (move == "w" || move == "W") {
      GamePlay::Instance()->move_character(character, "2");
      remainingMoves -= 1;
    }
    // move west
    else if (move == "a" || move == "A") {
      GamePlay::Instance()->move_character(character, "3");
      remainingMoves -= 1;
    }
    // move south
    else if (move == "s" || move == "S") {
      GamePlay::Instance()->move_character(character, "0");
      remainingMoves -= 1;
    }
    // move east
    else if (move == "d" || move == "D") {
      GamePlay::Instance()->move_character(character, "1");
      remainingMoves -= 1;
    } else if (move == "help" || move == "Help") {
      GamePlay::Instance()->print_help();
    } else if (move == "info" || move == "Info") {
      GamePlay::Instance()->print_stats(character);
    } else {
      std::cout << "Invalid input. Type help to see direction information.\n";
    }

    int x = character->get_currentX();
    int y = character->get_currentY();
    bool fight = false;

    int southTile = GamePlay::Instance()->get_mapTile(x, y + 1);
    int northTile = GamePlay::Instance()->get_mapTile(x, y - 1);
    int westTile = GamePlay::Instance()->get_mapTile(x - 1, y);
    int eastTile = GamePlay::Instance()->get_mapTile(x + 1, y);

    if (southTile != 0 && southTile != 1) {
      if (southTile == 6) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[3]);
        fight = true;
      } else if (southTile == 7) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[2]);
        fight = true;
      } else if (southTile == 8) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[1]);
        fight = true;
      } else if (southTile == 9) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[0]);
        fight = true;
      } else if (southTile == 5) {
        GamePlay::Instance()->open_treasureChest(character);
      }
    } else if (northTile != 0 && northTile != 1) {
      if (northTile == 6) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[3]);
        fight = true;
      } else if (northTile == 7) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[2]);
        fight = true;
      } else if (northTile == 8) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[1]);
        fight = true;
      } else if (northTile == 9) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[0]);
        fight = true;
      } else if (northTile == 5) {
        GamePlay::Instance()->open_treasureChest(character);
      }
    } else if (westTile != 0 && westTile != 1) {
      if (westTile == 6) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[3]);
        fight = true;
      } else if (westTile == 7) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[2]);
        fight = true;
      } else if (westTile == 8) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[1]);
        fight = true;
      } else if (westTile == 9) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[0]);
        fight = true;
      } else if (westTile == 5) {
        GamePlay::Instance()->open_treasureChest(character);
      }
    } else if (eastTile != 0 && eastTile != 1) {
      if (eastTile == 6) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[3]);
        fight = true;
      } else if (eastTile == 7) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[2]);
        fight = true;
      } else if (eastTile == 8) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[1]);
        fight = true;
      } else if (eastTile == 9) {
        GamePlay::Instance()->set_enemy(character,
                                        GamePlay::Instance()->characters[0]);
        fight = true;
      } else if (eastTile == 5) {
        GamePlay::Instance()->open_treasureChest(character);
      }
    }
    GamePlay::Instance()->print_map();
    std::cout << std::endl;

    if (fight == true) {
      remainingMoves = 0;
      character->getFSM()->changeState(SneakAttack::Instance());
    }
  } // end while
  character->getFSM()->changeState(EndTurn::Instance());
}

void PlayerWander::exitState(BaseCharacter *character) {}

/*-----------------------------------------------------------------------------
----------------------------- Search for Enemy --------------------------------
-----------------------------------------------------------------------------*/

SearchForEnemy *SearchForEnemy::Instance() {
  static SearchForEnemy instance;
  return &instance;
}

void SearchForEnemy::enterState(BaseCharacter *character) {
  Wander::enterState(character);
  std::cout << character->get_type() << ": Searching for enemies!\n";
}

void SearchForEnemy::executeState(BaseCharacter *character) {
  // set character's route to closest enemy
  character->set_route(GamePlay::Instance()->find_closestEnemy(character));

  // if enemy is within character's movement range, move character next to
  // enemy
  // and enter attack state
  if (character->get_route().length() <= character->get_speed()) {
    std::cout << character->get_type()
              << ": Enemy found! Moving in for the attack!\n";
    GamePlay::Instance()->move_character(character, character->get_route());
    character->getFSM()->changeState(SneakAttack::Instance());

    // if enemy is not within character's movement range, move character as
    // close as possible
  } else {
    std::cout << character->get_type() << ": Getting closer!" << std::endl;
    GamePlay::Instance()->move_character(character, character->get_route());
    character->getFSM()->changeState(EndTurn::Instance());
  }
}

void SearchForEnemy::exitState(BaseCharacter *character) {}

/*-----------------------------------------------------------------------------
-------------------------- Search for Treasure --------------------------------
-----------------------------------------------------------------------------*/

SearchForTreasure *SearchForTreasure::Instance() {
  static SearchForTreasure instance;
  return &instance;
}

void SearchForTreasure::enterState(BaseCharacter *character) {
  Wander::enterState(character);
  std::cout << character->get_type() << ": Searching for treasure!\n";
}

void SearchForTreasure::executeState(BaseCharacter *character) {
  // set character's route to closest treasure
  character->set_route(GamePlay::Instance()->find_closestTreasure(character));

  // if treasure is within character's movement range, move character next
  // to treasure
  if (character->get_route().length() <= character->get_speed()) {
    std::cout << character->get_type() << ": Found treasure!\n";
    GamePlay::Instance()->move_character(character, character->get_route());
    GamePlay::Instance()->open_treasureChest(character);
    // if treasure is not within character's movement range, move character
    // as close as possible
  } else {
    std::cout << character->get_type() << ": Getting closer!\n";
    GamePlay::Instance()->move_character(character, character->get_route());
  }
  character->getFSM()->changeState(EndTurn::Instance());
}

void SearchForTreasure::exitState(BaseCharacter *character) {}

/*=============================================================================
===============================================================================
===================================== Death ===================================
===============================================================================
==============================================================================*/

Death *Death::Instance() {
  static Death instance;
  return &instance;
}
void Death::enterState(BaseCharacter *character) {
  std::cout << character->get_type() << ": Died!\n";
  // clear character's position on the map
  GamePlay::Instance()->update_map(character->get_currentX(),
                                   character->get_currentY(), 0);
  // reset gold and level
  character->update_Gold(-(character->get_Gold()));
  character->set_level(-(character->get_level() + 1));
}
void Death::executeState(BaseCharacter *character) {
  // reset character on map
  GamePlay::Instance()->get_openCharacterPosition(character);
  GamePlay::Instance()->set_characterPosition(character);

  character->getFSM()->changeState(EndTurn::Instance());
}
void Death::exitState(BaseCharacter *character) {}

/*=============================================================================
===============================================================================
================================== End Turn ===================================
===============================================================================
==============================================================================*/
EndTurn *EndTurn::Instance() {
  static EndTurn instance;
  return &instance;
}

void EndTurn::enterState(BaseCharacter *character) {
  std::cout << character->get_type() << ": End of turn.\n";
}
void EndTurn::executeState(BaseCharacter *character) {}
void EndTurn::exitState(BaseCharacter *character) {}
