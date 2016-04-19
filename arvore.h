#ifndef TREE_H
#define TREE_H

class Tree
{
  public:
     Node* root;
     
     void Tree()
     {
        root = NULL;
     }
     
     void ~Tree()
     {
        delete(root);
     }
     void add(int info);
     void del(int info);
     template<typename T> T& getNode(int info);
     bool existe(int info);
}

template<typename T> class Node
{
   public:
      Node* right;
      Node* left;
      int info;
      
      void Node(int i)
      {
         right = NULL;
         left = NULL;
         info = i;
      }
      
      void ~Node()
      {
         delete(right);
         delete(left);
         delete(info);
      }
}

#endif
