#ifndef _NODE_
#define _NODE_

/*=============================================================================
===============================================================================
==================================== node =====================================
===============================================================================
=============================================================================*/
class node {
private:
  // current position
  int currentX;
  int currentY;
  // total distance already travelled to reach the node
  int nodeLevel;
  int priority;
  // N, NE, E, SE, S, SW, W, NW
  static const int directions = 4;

public:
  // constructor
  node(int xPos, int yPos, int d, int p);

  int getxPos() const { return currentX; }
  int getyPos() const { return currentY; }
  int getLevel() const { return nodeLevel; }
  int getPriority() const { return priority; }

  void updatePriority(const int &xDest, const int &yDest);

  void nextLevel(const int &direction);

  // Estimation function for the remaining distance to the goal.
  int estimate(const int &xDest, const int &yDest);
};

/*------------------------------------------------------------------------------
---------------------------- Operator Overload ---------------------------------
------------------------------------------------------------------------------*/
// Determine priority (in the priority queue)
inline bool operator<(const node &a, const node &b) {
  return a.getPriority() > b.getPriority();
}

#endif
