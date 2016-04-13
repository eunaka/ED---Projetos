#ifndef TREE_H
#define TREE_H

class Tree
{
  public:
     Node root;
     
     void Tree()
     {
        root = NULL;
     }
     
     void ~Tree()
     {
        delete();
     }
     void add(int info);
     void del(int info);
     template<typename T> T getNode(int info);
     bool existe(int info);
}

template<typename T> class Node
{
   public:
      Node right;
      Node left;
      int info;
      
      void Node()
      {
         right = NULL;
         left = NULL;
         info = NULL;
      }
      
      void ~Node()
      {
         delete();
      }
}

#endif