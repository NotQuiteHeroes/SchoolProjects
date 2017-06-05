#include "node.h"
#include <cmath>

/*=============================================================================
===============================================================================
==================================== node =====================================
===============================================================================
=============================================================================*/

// constructor
node::node(int xPos, int yPos, int d, int p) {
  currentX = xPos;
  currentY = yPos;
  nodeLevel = d;
  priority = p;
}

void node::updatePriority(const int &xDest, const int &yDest) {
  priority = nodeLevel + estimate(xDest, yDest) * 10; // A*
}

// give better priority to going straight rather than diagonally
void node::nextLevel(const int &direction) {
  nodeLevel += (directions == 4 ? (direction % 2 == 0 ? 10 : 14) : 10);
}

int node::estimate(const int &xDest, const int &yDest) {
  int xDistance, yDistance, distance;
  xDistance = xDest - currentX;
  yDistance = yDest - currentY;

  // Manhattan distance
  distance = std::fabs(xDistance) + std::fabs(yDistance);
  return (distance);
}
