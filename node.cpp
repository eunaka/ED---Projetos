#include <iostream>
#include "node.h"

template <typename T>
Node <T>::Node(T info)
{
    this->left = NULL;
    this->right = NULL;
    this->info = info;
}

template <typename T>
Node <T>::~Node()
{
  this->Node = NULL;
  this->left = NULL;
  this->right = NULL;
}

template <typename T>
Node<T>* Node<T>::getLeftNode()
{
    return this->left;
}

template <typename T>
Node<T>* Node <T>::getRightNode()
{
  return this->right;
}

template <typename T>
Node<T>* Node<T>::getInfo()
{
  return this->info;
}

template <typename T>
void Node<T>::setLeftNode(Node<T>* new_left)
{
  this->left = new_left;
}

template <typename T>
void Node<T>::setRightNode(Node<T>* new_right)
{
  this->right = new_right;
}

template <typename T>
bool Node<T>::isLeaf()
{
    if(this->getLeftNode() == NULL && this->getRightNode() == NULL)
      return 1;

    else return 0;
}
