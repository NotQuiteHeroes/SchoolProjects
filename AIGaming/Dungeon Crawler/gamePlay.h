#ifndef _GAMEPLAY_
#define _GAMEPLAY_

#include "baseCharacter.h"
#include <map>
#include <string>

/*=============================================================================
===============================================================================
==================================  GamePlay  =================================
===============================================================================
==============================================================================*/
class GamePlay {
public:
  static GamePlay *Instance();
  BaseCharacter *characters[4];

  int roll(int numberOfRolls, int sides);
  static void print_map();

  void get_openCharacterPosition(BaseCharacter *character);
  void set_characterPosition(BaseCharacter *character);
  int get_characterX(int character);
  int get_characterY(int character);
  void update_map(int x, int y, int toSet);
  int get_mapTile(int x, int y);

  void set_treasure();
  int get_treasureIndex();
  void set_treasureIndex(int newTreasureIndex);
  void open_treasureChest(BaseCharacter *character);

  int get_xPosition(int pos);
  int get_yPosition(int pos);
  std::string path_find(const int &xStart, const int &yStart,
                        const int &xFinish, const int &yFinish);
  void move_character(BaseCharacter *character, std::string route);
  void check_validMove(int x, int y, BaseCharacter *character);
  bool is_valid(int x, int y);

  void set_enemy(BaseCharacter *character, BaseCharacter *enemy);
  BaseCharacter *get_enemy(BaseCharacter *character);

  std::string find_closestEnemy(BaseCharacter *character);
  std::string find_closestTreasure(BaseCharacter *character);

  void set_characters(BaseCharacter *char1, BaseCharacter *char2,
                      BaseCharacter *char3, BaseCharacter *char4);
  BaseCharacter *get_character(int pos);
  void checkHealthStatus(BaseCharacter *character);

  std::map<BaseCharacter *, BaseCharacter *> enemies;
  int characterX[4];
  int characterY[4];

  void print_help();
  void print_stats(BaseCharacter *character);

private:
  GamePlay() {}
  GamePlay(const GamePlay &);
  GamePlay &operator=(const GamePlay &);

  static const int height = 20;
  static const int width = 20;

  int treasureOnMap;
  int treasureX[4];
  int treasureY[4];
  int treasureIndex;

  // number of possible directions to go at any position
  // 8 for N, NE, E, SE, S, SW, W, NW
  // 4 for N, S, E, W
  static int xDirections[4];
  static int yDirections[4];
};

#endif
