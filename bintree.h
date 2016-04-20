
#ifndef BINTREE_H
#define BINTREE_H
#include "node.h"

template <class T>
class BinTree
{
    private:
        Node <T> root;

    public:
        BinTree();
       ~BinTree();

        void inserir(T t);
        bool remover(T t);
        bool existe(T t);
        Node<T>* consultar(const T t, const Node<T>* node);
        void printaArvore();


};

#endif // BINTREE_H
