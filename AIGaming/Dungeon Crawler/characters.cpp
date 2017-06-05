#include "characters.h"
#include "gamePlay.h"

/*=============================================================================
===============================================================================
=================================  Characters  ================================
===============================================================================
=============================================================================*/

/*-----------------------------------------------------------------------------
---------------------------------  Player  ------------------------------------
-----------------------------------------------------------------------------*/

Player::Player(int pLevel, std::string pType) {
  currentHealth = maxHealth = GamePlay::Instance()->roll(1, 20) * pLevel;
  x = previousX = 0;
  y = previousY = 0;
  level = pLevel;
  strength = GamePlay::Instance()->roll(1, 8) * pLevel + 3;
  dexterity = GamePlay::Instance()->roll(1, 8) * pLevel + 1;
  speed = GamePlay::Instance()->roll(1, 8) * pLevel + 3;
  defense = GamePlay::Instance()->roll(1, 8) * pLevel + 3;
  magic = GamePlay::Instance()->roll(1, 8) * pLevel + 1;
  healing = GamePlay::Instance()->roll(1, 8) * pLevel + 3;
  gold = 0;
  type = pType;
  isPlayer = true;

  stateMachine = new StateMachine(this);
  stateMachine->setCurrentState(PlayerWander::Instance());
}

Player::~Player() { delete stateMachine; }

void Player::Update() { stateMachine->Update(); }

/*-----------------------------------------------------------------------------
---------------------------------  Barbarian  ---------------------------------
-----------------------------------------------------------------------------*/

Barbarian::Barbarian(int pLevel) {
  currentHealth = maxHealth = GamePlay::Instance()->roll(1, 20) * pLevel;
  x = previousX = 0;
  y = previousY = 0;
  level = pLevel;
  strength = GamePlay::Instance()->roll(1, 8) * pLevel + 5;
  dexterity = GamePlay::Instance()->roll(1, 8) * pLevel - 1;
  speed = GamePlay::Instance()->roll(1, 8) * pLevel + 2;
  defense = GamePlay::Instance()->roll(1, 8) * pLevel + 3;
  magic = GamePlay::Instance()->roll(1, 8) * pLevel - 1;
  healing = GamePlay::Instance()->roll(1, 8) * pLevel + 2;
  gold = 0;
  type = "Barbarian";
  isPlayer = false;

  stateMachine = new StateMachine(this);
  stateMachine->setCurrentState(SearchForEnemy::Instance());
}

Barbarian::~Barbarian() { delete stateMachine; }

void Barbarian::Update() { stateMachine->Update(); }

/*-----------------------------------------------------------------------------
-----------------------------------  Elf  -------------------------------------
-----------------------------------------------------------------------------*/

Elf::Elf(int pLevel) {
  currentHealth = maxHealth = GamePlay::Instance()->roll(1, 20) * pLevel;
  x = previousX = 0;
  y = previousY = 0;
  level = pLevel;
  strength = GamePlay::Instance()->roll(1, 8) * pLevel - 1;
  dexterity = GamePlay::Instance()->roll(1, 8) * pLevel + 5;
  speed = GamePlay::Instance()->roll(1, 8) * pLevel + 3;
  defense = GamePlay::Instance()->roll(1, 8) * pLevel - 1;
  magic = GamePlay::Instance()->roll(1, 8) * pLevel + 1;
  healing = GamePlay::Instance()->roll(1, 8) * pLevel + 3;
  gold = 0;
  type = "Elf";
  isPlayer = false;

  stateMachine = new StateMachine(this);
  stateMachine->setCurrentState(SearchForTreasure::Instance());
}

Elf::~Elf() { delete stateMachine; }

void Elf::Update() { stateMachine->Update(); }

/*-----------------------------------------------------------------------------
---------------------------------  Goblin  ------------------------------------
-----------------------------------------------------------------------------*/

Goblin::Goblin(int pLevel) {
  currentHealth = maxHealth = GamePlay::Instance()->roll(1, 20) * pLevel;
  x = previousX = 0;
  y = previousY = 0;
  level = pLevel;
  strength = GamePlay::Instance()->roll(1, 8) * pLevel + 4;
  dexterity = GamePlay::Instance()->roll(1, 8) * pLevel - 1;
  speed = GamePlay::Instance()->roll(1, 8) * pLevel + 4;
  defense = GamePlay::Instance()->roll(1, 8) * pLevel + 2;
  magic = GamePlay::Instance()->roll(1, 8) * pLevel + 2;
  healing = GamePlay::Instance()->roll(1, 8) * pLevel - 1;
  gold = 0;
  type = "Goblin";
  isPlayer = false;

  stateMachine = new StateMachine(this);
  stateMachine->setCurrentState(SearchForEnemy::Instance());
}

Goblin::~Goblin() { delete stateMachine; }

void Goblin::Update() { stateMachine->Update(); }

/*-----------------------------------------------------------------------------
---------------------------------  Wizard  ------------------------------------
-----------------------------------------------------------------------------*/

Wizard::Wizard(int pLevel) {
  currentHealth = maxHealth = GamePlay::Instance()->roll(1, 20) * pLevel;
  x = previousX = 0;
  y = previousY = 0;
  level = pLevel;
  strength = GamePlay::Instance()->roll(1, 8) * pLevel - 1;
  dexterity = GamePlay::Instance()->roll(1, 8) * pLevel - 1;
  speed = GamePlay::Instance()->roll(1, 8) * pLevel + 2;
  defense = GamePlay::Instance()->roll(1, 8) * pLevel + 3;
  magic = GamePlay::Instance()->roll(1, 8) * pLevel + 5;
  healing = GamePlay::Instance()->roll(1, 8) * pLevel + 2;
  gold = 0;
  type = "Wizard";
  isPlayer = false;

  stateMachine = new StateMachine(this);
  stateMachine->setCurrentState(SearchForTreasure::Instance());
}

Wizard::~Wizard() { delete stateMachine; }

void Wizard::Update() { stateMachine->Update(); }
