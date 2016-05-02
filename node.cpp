#include <iostream>
#include "node.h"


/*
 * constructor
 */
template <typename T>
Node <T>::Node(T info)
{
    this->left = NULL;
    this->right = NULL;
    this->info = info;
}

/*
 * Destructor
 */
template <typename T>
Node <T>::~Node()
{
  this->Node = NULL;
  this->left = NULL;
  this->right = NULL;
}

/*
 * Retorna node da esquerda
 */
template <typename T>
Node<T>* Node<T>::getLeftNode()
{
    return this->left;
}

/*
 * Retorna node da direita
 */
template <typename T>
Node<T>* Node <T>::getRightNode()
{
  return this->right;
}

/*
 * Retorna a informacao T do node
 */
template <typename T>
Node<T>* Node<T>::getInfo()
{
  return this->info;
}

/*
 * Altera a informacao T do node.
 */
template<typename T>
void setInfo(T info)
{
   this->info = info);
}

/*
 * Altera a referencia de node da esquerda
 */
template <typename T>
void Node<T>::setLeftNode(Node<T>* new_left)
{
  this->left = new_left;
}

/*
 * Altera a referencia de node da direita
 */
template <typename T>
void Node<T>::setRightNode(Node<T>* new_right)
{
  this->right = new_right;
}

/*
 * Verifica se o node eh folha
 */
template <typename T>
bool Node<T>::isLeaf()
{
    if(this->getLeftNode() == NULL && this->getRightNode() == NULL)
      return 1;

    else return 0;
}
