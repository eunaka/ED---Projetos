#include <iostream>
#include "node.h"

/* construtor de Node */
Node::Node(int info)
{
    this->left = NULL;
    this->right = NULL;
    this->info = info;
}

/* destrutor de node */
Node::~Node()
{
  this->left = NULL;
  this->right = NULL;
  std::cout << this->getInfo() << " removido\n\n";
}

Node* Node::getLeftNode()
{
    return this->left;
}

Node* Node::getRightNode()
{
  return this->right;
}

int Node::getInfo()
{
  return this->info;
}

void Node::setLeftNode(Node* new_left)
{
  this->left = new_left;
}

void Node::setRightNode(Node* new_right)
{
  this->right = new_right;
}

bool Node::isLeaf()
{
    if(!this->getLeftNode() && !this->getRightNode())
      return 1;

    else return 0;
}



