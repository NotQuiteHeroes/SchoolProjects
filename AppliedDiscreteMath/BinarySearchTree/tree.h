#ifndef _TREE_
#define _TREE_

#include "Node.h"

class Tree {
public:
  // constructor and deconstructor
  Tree();
  ~Tree();

  // public functions to act as interface for user
  void insert(std::string keyValue, std::string phoneValue,
              std::string addressValue);
  void destroy();
  void print();

private:
  // private functions perform actual actions the interface references
  void destroy(Node *leaf);
  void insert(std::string keyValue, std::string phoneValue,
              std::string addressValue, Node *leaf);
  void print(Node *node /*, int indent = 0 */);

  // pointer to root node
  Node *root;
};

#endif
