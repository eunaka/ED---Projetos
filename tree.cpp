#include "arvore.h"

void Tree::add(int info)
{
   if(root == NULL)
   {
      Node* novo = new Node(info);
      root = novo;
   }
   else
   {
      Node* pnode = root;
      while(1)
      {
         if(info == pnode->info)
         {
            cout << "Ja existe esse no na arvore" << endl;
         }
         else if(info < pnode->info)
         {
            if(pnode->left == NULL)
            {
               Node* aux = new Node(info);
               
               pnode->left = aux;
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
               Node* aux = new Node(info);
               
               pnode->right = aux;
               break;
            }
            else
            {
               pnode = pnode->right;
            }
         }
      }
   }
}

void Tree::del(int info)
{
   
}

template<typename T>
T& Tree::getNode(int info)
{
   Node* pnode = root;
   
   wilhile(pnode != NULL)
   {
      if(pnode->info == info)
         return pnode;
      
      else if(info < pnode->info)
      {
         pnode = pnode->left;
      }
      else
      {
         pnode = pnode->right;
      }
   }
   return NULL;
}

bool Tree::existe(int info)
{
   if(getNode(info) == NULL)
      return false;
   else
      return true;
}






