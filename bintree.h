#ifndef BINTREE_H
#define BINTREE_H
#include "node.h"

template <class T>
class BinTree
{
    private:
        Node <T> root;
        /* Métodos auxiliares da classe, usado apenas internamente pelos métodos da classe */
        Node<T>* buscarMenor(Node<T>*);
        Node<T>* buscarMaior(Node<T>*);
        Node<T>* buscarPai(Node<T>*);
        int imprime_sobrinhos(Node<T>* pnode, int profundidade, T info);

    public:
        BinTree();
       ~BinTree();

      //  void printaArvore();
        void inserir(Node<T>*, T);
      //  void removerDireita(Node<T>*);
      //  void removerEsquerda(Node<T>*);
        bool remover(T);
      //  bool existe(T);
        void setRoot(Node<T>*);
        Node<T>* consultar(const T, const Node<T>*);
        Node<T>* getRoot();
        void Sobrinhos(T info);
        int getProfundidade(T info);
};

#endif // BINTREE_H
