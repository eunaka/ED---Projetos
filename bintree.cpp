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
  While(1)
  {
    if(t == pnode->info)
    {
      cout << "Ja existe esse elemento na arvore" << endl;
      break;
    }
    if(t < pnode->info)
    {
      if(pnode->left == NULL)
      {
        Node* novo = new Node(t);
        pnode->left = novo;
        break;
      }
      else
      {
        pnode = pnode->left;
      }
    }
    else
    {
      if(pnode->right == NULL)
      {
        Node* novo = new Node(t);
        pnode->right = novo;
        break;
      }
      else
      {
        pnode = pnode->right;
      }
    }
  }
}

template <typename T>
bool BinTree<T>::remover(T t)
{
  if(this->root == NULL)
    return false;
  
  if(this->root->info == t)
  {
    if(this->root->left == NULL && this->root->right == NULL)
    {
      delete this->root;
    }
    else
    {
      
    }
  }
}

bool RemoverLeft(T t) 
{
  
}

template <typename T>
Node<T>* BinTree<T>::getRoot()
{
    return this->root;
}
