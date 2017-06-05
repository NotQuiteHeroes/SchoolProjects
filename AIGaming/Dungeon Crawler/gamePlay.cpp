#include "gamePlay.h"
#include "map.h"
#include "node.h"
#include <iostream>
#include <queue>

/*=============================================================================
===============================================================================
================================ GamePlay =====================================
===============================================================================
=============================================================================*/
// currently set for four directions (S, E, N, W)
// use xDirections = {1, 1, 0, -1, -1, -1, 0, 1}
// and yDirections = {0, 1, 1, 1, 0, -1, -1, -1}
// to allow for eight directions (S, SE, E, NW, N, NW, W, SW)
int GamePlay::xDirections[] = {1, 0, -1, 0};
int GamePlay::yDirections[] = {0, 1, 0, -1};

// singleton
GamePlay *GamePlay::Instance() {
  static GamePlay instance;
  return &instance;
}

/*-----------------------------------------------------------------------------
-------------------------------Character Positioning---------------------------
-----------------------------------------------------------------------------*/

// gets open position on board to place character at
void GamePlay::get_openCharacterPosition(BaseCharacter *character) {
  int row = rand() % 19;
  int column = rand() % 19;

  while (map[row][column] != 0) {
    row = rand() % 19;
    column = rand() % 19;
  }

  // update characters currentX and currentY
  character->set_currentLocation(row, column);

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

  // update arrays that hold all characters placement information
  characterX[pos] = row;
  characterY[pos] = column;
}

void GamePlay::set_characterPosition(BaseCharacter *character) {
  int toSet;

  // 9 = Barbarian
  // 8 = Elf
  // 7 = Goblin
  // 6 = Wizard
  if (character->get_type() == "Barbarian") {
    toSet = 9;
  } else if (character->get_type() == "Elf") {
    toSet = 8;
  } else if (character->get_type() == "Goblin") {
    toSet = 7;
  } else if (character->get_type() == "Wizard") {
    toSet = 6;
  }

  // get character's position to place on map
  int x = character->get_currentX();
  int y = character->get_currentY();

  map[x][y] = toSet;
}

// move character, given a route in string form
void GamePlay::move_character(BaseCharacter *character, std::string route) {
  // get character's current position and update character's previousLocation
  int x = character->get_currentX();
  int y = character->get_currentY();
  character->set_previousLocation(x, y);

  // if route is within character's movement range
  if (route.length() <= character->get_speed()) {
    // if route is one movement and its the player's turn, move one
    // if not player, don't move character
    // because then character will overlap with enemy/treasure
    if (route.length() == 1 && character->isPlayer) {
      int tempRoute = atoi(route.c_str());
      // update x and y position based on coordinates from xDirections and
      // yDirections
      x += get_xPosition(tempRoute);
      y += get_yPosition(tempRoute);
    } else if (route.length() == 1) {
      x += 0;
      y += 0;
    } else {
      // if route is greater than one, move character to position directly
      // before last position in route
      for (int i = 0; i < route.length() - 1; i++) {
        // get single character from route string
        char tempChar = route.at(i);
        // convert it to integer (**Note: atoi requires reference)
        int tempInt = atoi(&tempChar);
        // update x and y position based on coordinates from xDirections and
        // yDirections
        x += get_xPosition(tempInt);
        y += get_yPosition(tempInt);
      }
    }
  } else {
    // if full route is not within character's range, move character as far as
    // movement range will allow
    for (int i = 0; i <= character->get_speed(); i++) {
      // get single character from route string
      char tempChar = route.at(i);
      // convert character to integer (**Note: atoi requires reference)
      int tempInt = atoi(&tempChar);
      // update x and y position based on coordinates from xDirections and
      // yDirections
      x += get_xPosition(tempInt);
      y += get_yPosition(tempInt);
    }
  }
  check_validMove(x, y, character);
}

void GamePlay::check_validMove(int x, int y, BaseCharacter *character) {
  bool north, south, east, west;

  if (character->isPlayer == false) {
    if (is_valid(x, y) == false) {
      north = is_valid(x, y - 1);
      south = is_valid(x, y + 1);
      east = is_valid(x + 1, y);
      west = is_valid(x - 1, y);
    }

    if (north) {
      y -= 1;
    } else if (south) {
      y += 1;
    } else if (east) {
      x += 1;
    } else if (west) {
      x -= 1;
    }
  }
  // update character's currentX and currentY
  character->set_currentLocation(x, y);

  // update arrays holding character's place on board
  if (character->get_type() == "Barbarian") {
    characterX[0] = x;
    characterY[0] = y;
  } else if (character->get_type() == "Elf") {
    characterX[1] = x;
    characterY[1] = y;
  } else if (character->get_type() == "Goblin") {
    characterX[2] = x;
    characterY[2] = y;
  } else if (character->get_type() == "Wizard") {
    characterX[3] = x;
    characterY[3] = y;
  }

  // put character on map in new location
  set_characterPosition(character);

  // mark previous location as free on map
  map[character->get_previousX()][character->get_previousY()] = 0;
}

bool GamePlay::is_valid(int x, int y) {
  if (x < 0 || x > 19 || y < 0 || y > 19) {
    return false;
  }

  if (map[x][y] == 0) {
    return true;
  } else {
    return false;
  }
}
/*-----------------------------------------------------------------------------
-------------------------------Treasure Positioning---------------------------
-----------------------------------------------------------------------------*/
// set treasure on the map
void GamePlay::set_treasure() {
  int row, column;
  for (int i = 0; i < 3; i++) {
    row = rand() % 19;
    column = rand() % 19;

    while (map[row][column] != 0) {
      row = rand() % 19;
      column = rand() % 19;
    }

    map[row][column] = 5;
    treasureX[i] = row;
    treasureY[i] = column;

    treasureOnMap += 1;
  }
}

void GamePlay::set_treasureIndex(int newTreasureIndex) {
  treasureIndex = newTreasureIndex;
}

int GamePlay::get_treasureIndex() { return treasureIndex; }
/*-----------------------------------------------------------------------------
----------------------------------Pathfinding----------------------------------
-----------------------------------------------------------------------------*/
// return path in form of string
// For 4 directions:
// 0 = S
// 1 = E
// 2 = N
// 3 = W
// For 8 directions:
// 0: South
// 1: South East
// 2: East
// 3: North East
// 4: North
// 5: North West
// 6: West
// 7: South West
std::string GamePlay::path_find(const int &xStart, const int &yStart,
                                const int &xFinish, const int &yFinish) {
  std::priority_queue<node> pq[2];         // list of open Nodes
  int pqIndex = 0;                         // index for priority queue
  int evaluated_nodes_map[height][width];  // map of closed nodes
  int toEvaluate_nodes_map[height][width]; // map of open nodes
  int directions_map[height][width];       // map of directions
  int i, j, x, y, xdx, ydy;
  char c;

  // reset the node maps
  for (x = 0; x < height; x++) {
    for (y = 0; y < width; y++) {
      evaluated_nodes_map[x][y] = 0;
      toEvaluate_nodes_map[x][y] = 0;
    }
  }

  // create the start node and push into list of open nodes
  node startNode(xStart, yStart, 0, 0);
  startNode.updatePriority(xFinish, yFinish);
  pq[pqIndex].push(startNode);

  // mark it on the open nodes map
  toEvaluate_nodes_map[x][y] = startNode.getPriority();

  // A* search
  while (!pq[pqIndex].empty()) {
    // get the current node with the highest priority from open Nodes
    node currentNode(pq[pqIndex].top().getxPos(), pq[pqIndex].top().getyPos(),
                     pq[pqIndex].top().getLevel(),
                     pq[pqIndex].top().getPriority());

    // remove the node from the open list
    pq[pqIndex].pop();
    toEvaluate_nodes_map[currentNode.getxPos()][currentNode.getyPos()] = 0;
    // mark it on the closed Nodes map
    evaluated_nodes_map[currentNode.getxPos()][currentNode.getyPos()] = 1;

    // quit searching when the destination is reached
    if (currentNode.getxPos() == xFinish && currentNode.getyPos() == yFinish) {
      // generate the path from finish to start
      std::string path = "";
      int x, y;
      x = currentNode.getxPos();
      y = currentNode.getyPos();
      while (!(x == xStart && y == yStart)) {
        j = directions_map[x][y];

        // change fours to eights if eight directions desired
        c = '0' + (j + 4 / 2) % 4;
        path = c + path;
        x += xDirections[j];
        y += yDirections[j];
      }
      // empty the leftover Nodes
      while (!pq[pqIndex].empty()) {
        pq[pqIndex].pop(); // maybe doesn't delete nodes
      }
      return path;
    } else {
      // generate moves (child Nodes) in all possible directions
      // change four to eight if eight directions desired
      for (i = 0; i < 4; i++) {
        xdx = currentNode.getxPos() + xDirections[i];
        ydy = currentNode.getyPos() + yDirections[i];

        if (!(xdx < 0 || xdx > height - 1 || ydy < 0 || ydy > width - 1 ||
              map[xdx][ydy] == 1 || evaluated_nodes_map[xdx][ydy] == 1)) {
          // generate a child node
          node neighborNode(xdx, ydy, currentNode.getLevel(),
                            currentNode.getPriority());
          neighborNode.nextLevel(i);
          neighborNode.updatePriority(xFinish, yFinish);

          // if not in open Nodes list, add to list
          if (toEvaluate_nodes_map[xdx][ydy] == 0) {
            toEvaluate_nodes_map[xdx][ydy] = neighborNode.getPriority();
            pq[pqIndex].push(neighborNode);

            // mark parent node direction
            // change fours to eights if eight directions desired
            directions_map[xdx][ydy] = (i + 4 / 2) % 4;
          } else if (toEvaluate_nodes_map[xdx][ydy] >
                     neighborNode.getPriority()) {
            // update the priority info
            toEvaluate_nodes_map[xdx][ydy] = neighborNode.getPriority();

            // update the parent direction info
            // change fours to eights if eight directions desired
            directions_map[xdx][ydy] = (i + 4 / 2) % 4;

            // replace the node by emptying one queue to the other
            // the node to be replaced will be ignored
            // and the new node will be pushed in instead
            while (!(pq[pqIndex].top().getxPos() == xdx &&
                     pq[pqIndex].top().getyPos() == ydy)) {
              pq[1 - pqIndex].push(pq[pqIndex].top());
              pq[pqIndex].pop();
            }

            // remove the wanted node
            pq[pqIndex].pop();
            // againt maybe does not delete

            // empty the larger size queue to the smaller one
            if (pq[pqIndex].size() > pq[1 - pqIndex].size()) {
              pqIndex = 1 - pqIndex;
            }
            while (!pq[pqIndex].empty()) {
              pq[1 - pqIndex].push(pq[pqIndex].top());
              pq[pqIndex].pop();
              // maybe does not delete
            }
            pqIndex = 1 - pqIndex;

            // add the better node instead
            pq[pqIndex].push(neighborNode);
          }
        }
      }
    }
  }
  return ""; // no route found
}
// get directional change from hardcoded arrays that contain x and y
// coordinates
int GamePlay::get_xPosition(int pos) { return xDirections[pos]; }
int GamePlay::get_yPosition(int pos) { return yDirections[pos]; }

// find route to closest enemy, and update enemies map
std::string GamePlay::find_closestEnemy(BaseCharacter *character) {
  // starting position for route is character's current position
  int Ax = character->get_currentX();
  int Ay = character->get_currentY();

  int path1, path2, path3;
  int path1Index, path2Index, path3Index;

  int shortestPath, shortestPathIndex;

  // repetitive. When looping character's would attack themselves, though
  if (character->get_type() == "Barbarian") {
    // path to elf
    path1 = path_find(Ax, Ay, characterX[1], characterY[1]).length();
    path1Index = 1;
    // path to goblin
    path2 = path_find(Ax, Ay, characterX[2], characterY[2]).length();
    path2Index = 2;
    // path to wizard
    path3 = path_find(Ax, Ay, characterX[3], characterY[3]).length();
    path3Index = 3;
  } else if (character->get_type() == "Elf") {
    // path to barbarian
    path1 = path_find(Ax, Ay, characterX[0], characterY[0]).length();
    path1Index = 0;
    // path to goblin
    path2 = path_find(Ax, Ay, characterX[2], characterY[2]).length();
    path2Index = 2;
    // path to wizard
    path3 = path_find(Ax, Ay, characterX[3], characterY[3]).length();
    path3Index = 3;
  } else if (character->get_type() == "Goblin") {
    // path to barbarian
    path1 = path_find(Ax, Ay, characterX[0], characterY[0]).length();
    path1Index = 0;
    // path to elf
    path2 = path_find(Ax, Ay, characterX[1], characterY[1]).length();
    path2Index = 1;
    // path to wizard
    path3 = path_find(Ax, Ay, characterX[3], characterY[3]).length();
    path3Index = 3;
  } else if (character->get_type() == "Wizard") {
    // path to barbarian
    path1 = path_find(Ax, Ay, characterX[0], characterY[0]).length();
    path1Index = 0;
    // path to elf
    path2 = path_find(Ax, Ay, characterX[1], characterY[1]).length();
    path2Index = 1;
    // path to goblin
    path3 = path_find(Ax, Ay, characterX[2], characterY[2]).length();
    path3Index = 2;
  }

  if (path1 < path2 && path1 < path3) {
    if (path1 > 0) {
      shortestPath = path1;
      shortestPathIndex = path1Index;
    } else {
      // if path is not greater than zero then it's empty
      // get next shortest route
      if (path2 < path3 && path2 != 0) {
        shortestPath = path2;
        shortestPathIndex = path2Index;
      } else {
        shortestPath = path3;
        shortestPathIndex = path3Index;
      }
    }
  } else if (path2 < path1 && path2 < path3) {
    if (path2 > 0) {
      shortestPath = path2;
      shortestPathIndex = path2Index;
    } else {
      // if path is not greater than zero then it's empty
      // get next shortest route
      if (path1 < path3 && path1 != 0) {
        shortestPath = path1;
        shortestPathIndex = path1Index;
      } else {
        shortestPath = path3;
        shortestPathIndex = path3Index;
      }
    }
  } else if (path3 < path1 && path3 < path2) {
    if (path3 > 0) {
      shortestPath = path3;
      shortestPathIndex = path3Index;
    } else {
      // if path is not greater than zero then it's empty
      // get next shortest route
      if (path2 < path1 && path2 != 0) {
        shortestPath = path2;
        shortestPathIndex = path2Index;
      } else {
        shortestPath = path1;
        shortestPathIndex = path1Index;
      }
    }
  }

  // update enemies map by checking what number is at the map at the last
  // coordinate
  // only updates enemies map if enemy is within character's movement range
  // 6 = wizard
  // 7 = goblin
  // 8 = elf
  // 9 = wizard
  if (shortestPath <= character->get_speed()) {
    if (map[characterX[shortestPathIndex]][characterY[shortestPathIndex]] ==
        6) {
      set_enemy(character, characters[3]);
    } else if (map[characterX[shortestPathIndex]]
                  [characterY[shortestPathIndex]] == 7) {
      set_enemy(character, characters[2]);
    } else if (map[characterX[shortestPathIndex]]
                  [characterY[shortestPathIndex]] == 8) {
      set_enemy(character, characters[1]);
    } else if (map[characterX[shortestPathIndex]]
                  [characterY[shortestPathIndex]] == 9) {
      set_enemy(character, characters[0]);
    }
  }
  // return string representation of shortest route to enemy
  return path_find(Ax, Ay, characterX[shortestPathIndex],
                   characterY[shortestPathIndex]);
}

// find closest path to treasure
std::string GamePlay::find_closestTreasure(BaseCharacter *character) {
  // starting position of route is character's current position
  int Ax = character->get_currentX();
  int Ay = character->get_currentY();

  int treasure1, treasure2, treasure3;
  int shortestPath, tempTreasureIndex;

  // find path to each treasure on map
  // -1 signifies treasure is no longer on map
  if (treasureX[0] != -1 && treasureY[0] != -1) {
    treasure1 = path_find(Ax, Ay, treasureX[0], treasureY[0]).length();
  } else {
    treasure1 = 5000;
  }
  if (treasureX[1] != -1 && treasureY[1] != -1) {
    treasure2 = path_find(Ax, Ay, treasureX[1], treasureY[1]).length();
  } else {
    treasure2 = 5000;
  }
  if (treasureX[2] != -1 && treasureY[2] != -1) {
    treasure3 = path_find(Ax, Ay, treasureX[2], treasureY[2]).length();
  } else {
    treasure3 = 5000;
  }

  // find shortest path amongst three
  if (treasure1 < treasure2 && treasure1 < treasure3) {
    if (treasure1 > 0) {
      shortestPath = treasure1;
      tempTreasureIndex = 0;
    } else {
      // if path is not greater than zero then it's empty
      // get next shortest route
      if (treasure2 < treasure3 && treasure2 != 0) {
        shortestPath = treasure2;
        tempTreasureIndex = 1;
      } else {
        shortestPath = treasure3;
        tempTreasureIndex = 2;
      }
    }
  } else if (treasure2 < treasure1 && treasure2 < treasure3) {
    if (treasure2 > 0) {
      shortestPath = treasure2;
      tempTreasureIndex = 1;
    } else {
      // if path is not greater than zero then it's empty
      // get next shortest route
      if (treasure1 < treasure3 && treasure1 != 0) {
        shortestPath = treasure1;
        tempTreasureIndex = 0;
      } else {
        shortestPath = treasure3;
        tempTreasureIndex = 2;
      }
    }
  } else if (treasure3 < treasure1 && treasure3 < treasure2) {
    if (treasure3 > 0) {
      shortestPath = treasure3;
      tempTreasureIndex = 2;
    } else {
      // if path is not greater than zero then it's empty
      // get next shortest route
      if (treasure2 < treasure1 && treasure2 != 0) {
        shortestPath = treasure2;
        tempTreasureIndex = 1;
      } else {
        shortestPath = treasure1;
        tempTreasureIndex = 0;
      }
    }
  }
  set_treasureIndex(tempTreasureIndex);
  return path_find(Ax, Ay, treasureX[tempTreasureIndex],
                   treasureY[tempTreasureIndex]);
}

/*-----------------------------------------------------------------------------
---------------------------  General Gameplay -------------------------------
-----------------------------------------------------------------------------*/
int GamePlay::roll(int numberOfRolls, int sides) {
  int rollSum = 0;
  for (int i = 0; i < numberOfRolls; i++) {
    rollSum += rand() % sides + 1;
  }
  return rollSum;
}

void GamePlay::print_map() {
  for (int x = 0; x < 20; x++) {
    for (int y = 0; y < 20; y++) {
      if (map[x][y] == 0) {
        std::cout << "."; // open path
      } else if (map[x][y] == 1) {
        std::cout << "O"; // obstacle
      } else if (map[x][y] == 5) {
        std::cout << "#"; // treasure
      } else if (map[x][y] == 6) {
        std::cout << "W"; // wizard
      } else if (map[x][y] == 7) {
        std::cout << "G"; // goblin
      } else if (map[x][y] == 8) {
        std::cout << "E"; // elf
      } else if (map[x][y] == 9) {
        std::cout << "B"; // barbarian
      }
    }
    std::cout << std::endl;
  }
}

void GamePlay::open_treasureChest(BaseCharacter *character) {
  int tempTreasureIndex = get_treasureIndex();
  int treasureType = rand() % 7 + 1;
  std::string treasureName;
  int treasureEffect = GamePlay::Instance()->roll(1, 20);

  switch (treasureType) {
  case 1: {
    treasureName = "gold";
    character->update_Gold(treasureEffect);
    break;
  }

  case 2: {
    treasureName = "dexterity potion";
    character->set_dexterity(treasureEffect);
    break;
  }

  case 3: {
    treasureName = "speed potion";
    character->set_speed(treasureEffect);
    break;
  }

  case 4: {
    treasureName = "magic book";
    character->set_magic(treasureEffect);
    break;
  }

  case 5: {
    treasureName = "healing book";
    character->set_healing(treasureEffect);
    break;
  }

  case 6: {
    treasureName = "healing potion";
    int healingRoll = roll(1, 8) + character->get_healing();
    if (healingRoll + character->get_currentHealth() >
        character->get_maxHealth()) {
      character->set_currentHealth(character->get_maxHealth());
    } else {
      character->set_currentHealth(healingRoll);
    }
    break;
  }

  case 7: {
    treasureName = "weapon";
    character->set_strength(treasureEffect);
    break;
  }
  }

  std::cout << character->get_type() << ": Found " << treasureName
            << " with an effect of " << treasureEffect << std::endl;
  map[treasureX[tempTreasureIndex]][treasureY[tempTreasureIndex]] = 0;
  // mark treasure as no longer on map
  treasureX[tempTreasureIndex] = -1;
  treasureY[tempTreasureIndex] = -1;
  treasureOnMap -= 1;
  if (treasureOnMap == 0) {
    set_treasure();
  }
}

void GamePlay::checkHealthStatus(BaseCharacter *character) {
  BaseCharacter *enemy = get_enemy(character);
  // if character dies, character's state changes to Death
  // enemy gains character's gold, and level increases by one
  if (character->get_currentHealth() <= 0) {
    enemy->update_Gold(character->get_Gold());
    enemy->set_level(1);
    character->getFSM()->changeState(Death::Instance());
  }
  // if character's health is below half, change state to Search for treasure
  // as treasure chests hold health potions
  else if (character->isPlayer != true &&
           character->get_currentHealth() <=
               ((character->get_maxHealth()) / 2)) {
    character->getFSM()->changeState(SearchForTreasure::Instance());
  }
  // if enemy dies, enemy's state changes to Death
  // character gains enemy's gold, and level increases by one
  if (enemy->get_currentHealth() <= 0) {
    character->update_Gold(enemy->get_Gold());
    character->set_level(1);
    enemy->getFSM()->changeState(Death::Instance());
  }
}

void GamePlay::print_help() {
  std::cout << "North: w\nSouth: s\nEast: d\nWest: a\n";
  std::cout << "To view your stats, type info.\n";
}
void GamePlay::print_stats(BaseCharacter *character) {
  std::cout << "Max Health: " << character->get_maxHealth() << std::endl;
  std::cout << "Current Health: " << character->get_currentHealth()
            << std::endl;
  std::cout << "Level: " << character->get_level() << std::endl;
  std::cout << "Strength: " << character->get_strength() << std::endl;
  std::cout << "Dexterity: " << character->get_dexterity() << std::endl;
  std::cout << "Speed: " << character->get_speed() << std::endl;
  std::cout << "Defense: " << character->get_defense() << std::endl;
  std::cout << "Magic: " << character->get_magic() << std::endl;
  std::cout << "Healing: " << character->get_healing() << std::endl;
  std::cout << "Gold: " << character->get_Gold() << std::endl;
}
/*-----------------------------------------------------------------------------
---------------------------  Pointer Containers -------------------------------
-----------------------------------------------------------------------------*/
void GamePlay::set_enemy(BaseCharacter *character, BaseCharacter *enemy) {
  enemies[character] = enemy;
  enemies[enemy] = character;
}

BaseCharacter *GamePlay::get_enemy(BaseCharacter *character) {
  return enemies[character];
}

void GamePlay::set_characters(BaseCharacter *char1, BaseCharacter *char2,
                              BaseCharacter *char3, BaseCharacter *char4) {
  characters[0] = char1;
  characters[1] = char2;
  characters[2] = char3;
  characters[3] = char4;
}

void GamePlay::update_map(int x, int y, int toSet) { map[x][y] = toSet; }
int GamePlay::get_mapTile(int x, int y) { return map[x][y]; }

BaseCharacter *GamePlay::get_character(int pos) { return characters[pos]; }
