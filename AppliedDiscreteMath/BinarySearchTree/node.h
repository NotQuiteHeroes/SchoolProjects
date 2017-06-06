#ifndef _Node_
#define _Node_

#include <string>

// node struct
// holds contact information
// and pointers to neighboring nodes
struct Node {
  std::string key;
  std::string phone;
  std::string address;

  Node *left;
  Node *right;
};

#endif
