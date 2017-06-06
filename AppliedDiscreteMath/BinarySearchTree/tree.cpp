#include "Tree.h"
#include <iomanip>
#include <iostream>

// constructor sets node to NULL
Tree::Tree() { root = NULL; }

// destructor calls destroy interface
Tree::~Tree() { destroy(); }

// destroy interface
void Tree::destroy() { destroy(root); }

// called by destroy interface
// deletes all leaves of a tree
// works recursively
// starts at bottom of each part of the tree
// deletes the leaf, then works its way back up:
// deletes leftmost node, then the right chid node from the leftmost node's
// parent, then deletes parent and continues in this fashion up the tree
void Tree::destroy(Node *leaf) {
  if (leaf != NULL) {
    destroy(leaf->left);
    destroy(leaf->right);
    delete leaf;
  }
}

// insert interface
// requires contact information as input
void Tree::insert(std::string keyValue, std::string phoneValue,
                  std::string addressValue) {
  if (root != NULL) {
    insert(keyValue, phoneValue, addressValue, root);
  } else {
    // create root node if one doesn't exist
    root = new Node;
    root->key = keyValue;
    root->phone = phoneValue;
    root->address = addressValue;
    root->left = NULL;
    root->right = NULL;
  }
}

// called by insert interface, requires contact information as input
// as well as node to check insertion requirements
// searches down the tree of children nodes
// following rules of left for lower value and right for greater value
// until it reaches an empty node, which it then creates and sets its child node
// pointers to NULL
// recursion stops once new node is created
void Tree::insert(std::string keyValue, std::string phoneValue,
                  std::string addressValue, Node *leaf) {

  // lower value
  if (keyValue < leaf->key) {
    if (leaf->left != NULL) {
      insert(keyValue, phoneValue, addressValue, leaf->left);
    } else {
      leaf->left = new Node;
      leaf->left->key = keyValue;
      leaf->left->phone = phoneValue;
      leaf->left->address = addressValue;
      leaf->left->left = NULL;
      leaf->left->right = NULL;
    }
    // greater value
  } else if (keyValue >= leaf->key) {
    if (leaf->right != NULL) {
      insert(keyValue, phoneValue, addressValue, leaf->right);
    } else {
      leaf->right = new Node;
      leaf->right->key = keyValue;
      leaf->right->phone = phoneValue;
      leaf->right->address = addressValue;
      leaf->right->left = NULL;
      leaf->right->right = NULL;
    }
  }
}

// print interface
void Tree::print() { print(root); }

// called by print interface given node to start printing from
// works recursively, going through left subtree then right subtree
void Tree::print(Node *node) {
  // recursion ends if empty node encountered
  if (node != NULL) {
    // print left subtree
    print(node->left);
    // print current node
    std::cout << node->key << std::endl;
    std::cout << node->phone << std::endl;
    std::cout << node->address << std::endl;
    std::cout << std::endl;
    // print right subtree
    print(node->right);
  }
}
