#include "bintree.h"
#include <iostream>
#include "node.h"
#define LEFT_NULL  (!pnode->getLeftNode() && pnode->getRightNode())
#define RIGHT_NULL (pnode->getLeftNode() && !pnode->getRightNode())

template <typename T>
BinTree<T> ::BinTree()
{
  this->root = NULL;
}

template <typename T>
Node<T>* BinTree<T> :: getRoot()
{
    return this->root;
}

template <typename T>
void BinTree<T> :: setRoot(Node<T>* new_root)
{
  this->root = new_root;
}

template <typename T>
Node<T>* BinTree<T> ::consultar(const T info, const Node<T>* node)
{
  if(node == info)
    return node;

  if(info < node->getInfo())
    return consultar(info, node->getLeftNode());

  if(info > node->getInfo())
    return consultar(info, node->getRightNode());

  if(node == NULL)
    return node;
}


template <typename T>
void BinTree <T> :: inserir(Node<T>* pnode , T info)
{
    Node<T>* novo;

    if(this->getRoot() == NULL)
    {
        novo = new Node<T>(info);
        this->setRoot(novo);
        return;
    }

    if(info < pnode->getInfo())
    {
        if(pnode->getLeftNode() == NULL)
        {
            novo = new Node<T>(info);
            pnode->setLeftNode(novo);
            return;
        }

        return inserir(pnode->getLeftNode(), info);
    }

    if(info > pnode->getInfo())
    {
        if(pnode->getRightNode() == NULL)
        {
            novo = new Node<T>(info);
            pnode->setRightNode(novo);
            return;
        }

        return inserir(pnode->getRightNode(), info);
    }

    if(info == pnode->getInfo())
    {
        std::cout << "Elemento ja faz parte da arvore\n";
        return;
    }

}


/* retorna o node com menor informação pela direita de pnode */
template <typename T>
Node<T>* BinTree<T>::buscarMenor(Node<T>* pnode)
{
    /* começa procurando pela direita de pnode(procura o menor do lado direito) */
    pnode = pnode->getRightNode();

    while(true)
    {
        if(pnode->getLeftNode() == NULL)
            return pnode;

        else
            pnode = pnode->getLeftNode();
    }
}


/*retorna o nó com maior informação pela esquerda de pnode */
template <typename T>
Node<T>* BinTree<T>::buscarMaior(Node<T>* pnode)
{
    /* começa pela esquerda */
    pnode = pnode->getLeftNode();

    while(true)
      {
        if(pnode->getRightNode() == NULL)
            return pnode;

        if(pnode->getRightNode() != NULL)
            pnode = pnode->getRightNode();
      }
}


template <typename T>
Node<T>* BinTree<T>::buscarPai(Node<T>* pnode)
{
   Node<T>* ppai = this->getRoot();

   if(pnode == this->getRoot() || pnode == NULL)
      return NULL;

   while(true)
      {
       if(ppai->getLeftNode()->getInfo() == pnode->getInfo() || ppai ->getRightNode()->getInfo() == pnode->getInfo())
          return ppai;

       if(ppai->getInfo() < pnode->getInfo())
          ppai = ppai->getRightNode();

       else if(ppai->getInfo() > pnode->getInfo())
          ppai = ppai->getLeftNode();
      }
}

template <typename T>
bool BinTree<T>::remover(T info)
{
  Node<T>* pnode;     /* nó que será excluído, é retornado pelo método consultar() */
  Node<T>* ppai;      /* ponteiro para o pai, é o pai de pnode, retornado pelo método buscarPai() */
  Node<T>* node_subs; /* nó substituto, ocupará o lugar de pnode. Pode conter ou a maior ou a menor informação */
  Node<T>* ppai_subs; /* pai do nó substituto, necessário para realizar algumas trocas */

  pnode = consultar(info, this->root); /* encontra o nó que será excluído */
  ppai = buscarPai(pnode);             /* encontra o pai de pnode, se pnode for raíz, retorna NULL */

  if(pnode == NULL)
      return false;

  if(pnode->isLeaf())
  {
      delete pnode;
      if(pnode == this->root)
          setRoot(NULL);
  }


  /* node_subs será o menor nó do lado esquerdo */
  else if(LEFT_NULL || pnode) //MACRO DEFINIDA NO INÍCIO DO ARQUIVO
  {
        node_subs = buscarMenor(pnode);
        ppai_subs = buscarPai(node_subs);

        /*  se o pai do menor já é o próprio pnode, para removê-lo
         *  basta fazer com que o menor aponte para o nó esquerdo de pnode
         *  OBS: o menor nao tem nenhum filho à esquerda
        */
        if(ppai_subs == pnode)
        {   node_subs->setLeftNode(pnode->getLeftNode());
            delete pnode;
            return true;
        }

        ppai_subs->setLeftNode(node_subs->getRightNode());
        /* como menor é o mais a esquerda, seu nó esquerdo é nulo,
         * então o seu pai(ppai2) deixa de apontar para ele(menor) e
         * passa a apontar para seu nó direito(que pode ser nulo ou não)
         */

        if(pnode == this->root)
        {   /* menor é é a nova raíz */
            node_subs->setLeftNode(root->getLeftNode());
            node_subs->setRightNode(root->getRightNode());
            this->setRoot(node_subs);
         }

        else
        {   /* verifica se pnode está do lado direito ou esquerdo do pai e o substitui pelo menor */
            if(ppai->getRightNode() == pnode)
                ppai->setRightNode(node_subs);
            else
                ppai->setLeftNode(node_subs);

            node_subs->setRIghtNode(pnode->getRightNode());
            node_subs->setLeftNode(pnode->getLeftNode());
        }

        delete pnode;
        return true;
    }

  /* nesse caso, o node_subs será o maior nó do lado esquerdo */
  else if(RIGHT_NULL || pnode) //MACRO  DEFINIDA NO INÍCIO DO ARQUIVO
    {
      node_subs = buscarMaior(pnode);
      ppai_subs = buscarPai(node_subs);

      /*  se o pai do maior já é o próprio pnode, para removê-lo
       *  basta fazer com que o maior aponte para o nó direito de pnode
       *  OBS: o maior nao tem nenhum filho à direita
       */
      if(ppai_subs == pnode)
      {   node_subs->setRightNode(pnode->getRighttNode());
          delete pnode;
          return true;
      }

      ppai_subs->setRighttNode(node_subs->getLeftNode());
      /* como maior é o maior, não há mais ninguém na sua direita
       * então o seu pai(ppai2) deixa de apontar para ele(maior) e
       * passa a apontar para seu nó esquerdo (que pode ser nulo ou não)
       */

      if(pnode == this->root)
      {   /* maior agora é a raíz */
          node_subs->setLeftNode(this->root->getLeftNode());
          node_subs->setRightNode(this->root->getRightNode());
          setRoot(node_subs);
       }

      else
      {
          /* verifica se pnode está do lado direito ou esquerdo do pai e o substitui pelo maior */
          if(ppai->getLeftNode() == pnode)
              ppai->setLefttNode(node_subs);

          else
              ppai->getRightNode(node_subs);

          node_subs->seLeftNode(pnode->getLeftNode());
          node_subs->setRightNode(pnode->getRightNode());
      }

      delete pnode; /* chama o destrutor de pnode */
      return true;
    }
}

