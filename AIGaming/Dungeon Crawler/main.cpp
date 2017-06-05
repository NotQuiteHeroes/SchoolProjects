#include "characters.h"
#include "gamePlay.h"
#include <iostream>

using namespace std;

int menu();
void game_play(int choice);
/*=============================================================================
===============================================================================
===================================  Main  ===================================
===============================================================================
==============================================================================*/
int main() {

  srand(time(0));

  cout << "Welcome to the Dungeon Crawler!\n";

  int choice = menu();

  cout << "To move, use the WASD keys.\nTo see detailed movement "
          "instructions, type help at any point.\n";
  cout << "To see your game stats, type info at any point.\nGood Luck!\n";
  cout << "-----------------------------------------------------------------\n";
  game_play(choice);

  return 0;
}

int menu() {
  int choice;
  cout << "Choose your character: \n";
  cout << "\t1. The Brutal Barbarian\n";
  cout << "\t2. The Evasive Elf\n";
  cout << "\t3. The Grotesque Goblin\n";
  cout << "\t4. The Wonderous Wizard\n";
  cin >> choice;
  while (choice < 1 || choice > 4) {
    cout << "Invalid entry. Please pick 1 - 4.\n";
    cin >> choice;
  }
  return choice;
}

void game_play(int choice) {
  BaseCharacter *player, *barbarian, *elf, *goblin, *wizard;

  switch (choice) {
  // Player = Barbarian
  case 1: {
    barbarian = new Player(1, "Barbarian");
    player = barbarian;
    elf = new Elf(1);
    goblin = new Goblin(1);
    wizard = new Wizard(1);
    break;
  }
  // Player = Elf
  case 2: {
    barbarian = new Barbarian(1);
    elf = new Player(1, "Elf");
    player = elf;
    goblin = new Goblin(1);
    wizard = new Wizard(1);
    break;
  }
  // Player = Goblin
  case 3: {
    barbarian = new Barbarian(1);
    elf = new Elf(1);
    goblin = new Player(1, "Goblin");
    player = goblin;
    wizard = new Wizard(1);
    break;
  }
  // Player = Wizard
  case 4: {
    barbarian = new Barbarian(1);
    elf = new Elf(1);
    goblin = new Goblin(1);
    wizard = new Player(1, "Wizard");
    player = wizard;
    break;
  }
  } // end switch

  // set treasure on the map
  GamePlay::Instance()->set_treasure();

  // find open positions on map for each character
  GamePlay::Instance()->get_openCharacterPosition(barbarian);
  GamePlay::Instance()->get_openCharacterPosition(elf);
  GamePlay::Instance()->get_openCharacterPosition(goblin);
  GamePlay::Instance()->get_openCharacterPosition(wizard);

  // update map with character positions
  GamePlay::Instance()->set_characterPosition(barbarian);
  GamePlay::Instance()->set_characterPosition(elf);
  GamePlay::Instance()->set_characterPosition(goblin);
  GamePlay::Instance()->set_characterPosition(wizard);

  // add characters to array of pointers to characters
  // for gameplay access
  GamePlay::Instance()->set_characters(barbarian, elf, goblin, wizard);

  GamePlay::print_map();
  std::cout << std::endl;
  std::cout << std::endl;

  // while player is not dead, run through each character's turn
  // In order:
  //  Barbarian
  //  Elf
  //  Goblin
  //  Wizard
  while (player->getFSM()->get_currentState() != Death::Instance()) {
    while (barbarian->getFSM()->get_currentState() != EndTurn::Instance()) {
      barbarian->Update();
      GamePlay::print_map();
      std::cout << std::endl;
      std::cout << std::endl;
    }
    while (elf->getFSM()->get_currentState() != EndTurn::Instance()) {
      elf->Update();
      GamePlay::print_map();
      std::cout << std::endl;
      std::cout << std::endl;
    }
    while (goblin->getFSM()->get_currentState() != EndTurn::Instance()) {
      goblin->Update();
      GamePlay::print_map();
      std::cout << std::endl;
      std::cout << std::endl;
    }
    while (wizard->getFSM()->get_currentState() != EndTurn::Instance()) {
      wizard->Update();
      GamePlay::print_map();
      std::cout << std::endl;
      std::cout << std::endl;
    }

    // To get out of EndTurn state after end of round
    // If character is player and current state is death, stay in that state to
    // end game
    // Otherwise, return to PlayerWander state
    // If not character, return to base state for each character
    if (barbarian->isPlayer &&
        barbarian->getFSM()->get_currentState() == Death::Instance()) {
      barbarian->getFSM()->setCurrentState(Death::Instance());
    } else if (barbarian->isPlayer) {
      barbarian->getFSM()->setCurrentState(PlayerWander::Instance());
    } else {
      barbarian->getFSM()->setCurrentState(SearchForEnemy::Instance());
    }

    if (elf->isPlayer &&
        elf->getFSM()->get_currentState() == Death::Instance()) {
      elf->getFSM()->setCurrentState(Death::Instance());
    } else if (elf->isPlayer) {
      elf->getFSM()->setCurrentState(PlayerWander::Instance());
    } else {
      elf->getFSM()->setCurrentState(SearchForTreasure::Instance());
    }

    if (goblin->isPlayer &&
        goblin->getFSM()->get_currentState() == Death::Instance()) {
      goblin->getFSM()->setCurrentState(Death::Instance());
    } else if (goblin->isPlayer) {
      goblin->getFSM()->setCurrentState(PlayerWander::Instance());
    } else {
      goblin->getFSM()->setCurrentState(SearchForEnemy::Instance());
    }

    if (wizard->isPlayer &&
        wizard->getFSM()->get_currentState() == Death::Instance()) {
      wizard->getFSM()->setCurrentState(Death::Instance());
    } else if (wizard->isPlayer) {
      wizard->getFSM()->setCurrentState(PlayerWander::Instance());
    } else {
      wizard->getFSM()->setCurrentState(SearchForTreasure::Instance());
    }
    cout << "-------------------------------------------------------------\n";
  }
}
