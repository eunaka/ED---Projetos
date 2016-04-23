#include <iostream>
#include "bintree.h"
#include "node.h"

using namespace std;

/*
 * Imprime no console todos os nodes um nivel
 * abaixo de um node info, exceto os seus descendentes.
 * Tambem imprime a quantidade de sobrinhos
 * impressos.
 */
template <typename T>
void BinTree::Sobrinhos(T info)
{ 
   cout << endl;

   int s = imprime_sobrinhos(this->root, getProfundidade(info), info);
   
   cout << endl << "Numero total de sobrinhos: " << s << endl;
}

/*
 * Retorna a profundidade de um elemento da
 * arvore. Se a raiz da arvore for nula,
 * retorna -1. A raiz tem profundidade 0.
 */
template <typename T>
int BinTree::getProfundidade(T info)
{
   Node* pnode = this->root;
   int profundidade = -1;
   
   while(pnode != NULL)
   {
      profundidade++;
      if(info == pnode->getInfo())
         return profundidade;
         
      else if(info < pnode->info)
         pnode = pnode->getLeft();
         
      else
         pnode = pnode->getRight();
   }
   
   return -1;
}

/*
 * Imprime todos os nodes filhos de uma
 * profundidade, exceto do node info.
 * Retorna a quantidade de nodes impressos.
 */
template <typename T>
int BinTree::imprime_sobrinhos(Node<T>* pnode, int profundidade, T info)
{
   int numero_sobrinhos = 0;
   static int profundidade_node = 0;
   
   if(profundidade < 0)
      return 0;
      
   if(profundidade_node == profundidade && pnode != NULL)
   {
      if(pnode->getInfo() != info)
      {
         Node* tio = pnode;
         Node* left = tio->getLeft();
         Node* right = tio->getRight();
      
         if(letf != NULL)
         {
            cout << left->getInfo() << ", ";
            numero_sobrinhos++;
         }
         if(right != NULL)
         {
            cout << right->getInfo() << ", ";
            numero_sobrinhos++;
         }
         
         return numero_sobrinhos;
      }
   }
   else
   {
      profundidade_node++;
      return imprime_sobrinhos(pnode->getLeft(), profundidade, info) + imprime_sobrinhos(pnode->getRight(), profundidade, info);
   }
}





