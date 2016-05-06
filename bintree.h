#ifndef BINTREE_H
#define BINTREE_H
#include "node.h"

class BinTree
{
    private:
        Node* root;
        /* MÉTODOS AUXILIARES - Usados internamente pelos métodos públicos da classe */
        Node* buscarPai(Node*);
        Node* buscarMenor(Node*);
        Node* buscarMaior(Node*);
        int  imprime_sobrinhos(Node*, int, int);
        void limpar(Node*);

    public:
        BinTree();
        Node* consultar(int);
        bool remover(int);
        bool existe(int);
        void sobrinhos(int);
        void inserir(int);
        void limparArvore();
        int getProfundidade(int);
};


#endif // BINTREE_H
