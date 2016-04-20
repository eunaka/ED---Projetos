#include "bintree.h"
#include <iostream>
#include "node.h"

template <typename T>
BinTree <T> ::BinTree()
{
}

template <typename T>
Node<T>* BinTree<T> ::consultar(const T t, const Node<T>* node)
{
  if(node == NULL)
    return;

  if(node->info > t)
    return consultar(t, node->right);

  if(node->info < t)
    return consultar(t, node->left);

  if(node == t)
    return node;

}


template <typename T>
void BinTree <T> ::inserir(T t)
{
  Node* pnode = this->root;
  
  
}

template <typename T>
Node<T>* BinTree<T>::getRoot()
{
    return this->root;
}
