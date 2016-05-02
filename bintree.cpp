#include "bintree.h"
#include <iostream>
#include "node.h"
#define LEFT_NULL  (!pnode->getLeftNode() && pnode->getRightNode())
#define RIGHT_NULL (pnode->getLeftNode() && !pnode->getRightNode())



/*
 * Construtor
 */
template <typename T>
BinTree <T> ::BinTree()
{
  this->root = NULL;
}

/*
 * Retorna o node raiz da arvore
 */
template <typename T>
Node<T>* BinTree<T> :: getRoot()
{
    return this->root;
}

/*
 * Altera o node raiz da arvore
 */
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
        std::cout << "Elemento ja faz parte da arvore" << std::endl;
        return;
    }

}


/* retorna o node com menor informação
 * pela direita de pnode
 */
template <typename T>
Node<T>* BinTree<T>::buscarMenor(Node<T>* pnode)
{
    /* começa procurando pela direita de pnode */
    pnode = pnode->getRightNode();

    while(true)
    {
        if(pnode->getLeftNode() == NULL)
            return pnode;

        else
            pnode = pnode->getLeftNode();
    }
}


/*retorna o nó com maior informação
 * pela esquerda de pnode
 */
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
  Node<T>* root = this->getRoot();
  Node<T>* pnode;
  Node<T>* ppai;
  Node<T>* menor;
  Node<T>* maior;
  Node<T>*ppai2;

  pnode = consultar(info, root); /* encontra o nó que será excluído */
  ppai = buscarPai(pnode);      /* encontra o pai de pnode, se pnode for raíz, retorna NULL */

  if(pnode == NULL)
      return false;

  if(pnode->isLeaf())
  {
      delete pnode;
      if(pnode == root)
          setRoot(NULL);

      return true;
  }


  if(LEFT_NULL || pnode) //MACRO
    {
        menor = buscarMenor(pnode);/*o menor pode ser o proprio filho, ou seja o pai do menor é o proprio nó*/
        ppai2 = buscarPai(menor);
        ppai2->setLeftNode(menor->getRightNode());  /* como menor é o mais a esquerda, seu nó esquerdo é nulo,
                                                     * então o seu pai(ppai2) deixa de apontar para ele(menor) e
                                                     *  passa a apontar para seu nó direito(que pode ser nulo ou não)
                                                     */
        if(pnode == root)
        {
            menor->setLeftNode(root->getLeftNode());
            menor->setRightNode(root->getRightNode());
            setRoot(menor);
            delete root;
         }

        else
        {
            ppai->setRightNode(menor);
           //repetindo, vi agora,mas nao mudei pq pode ser alguma coisa importante que eu n lembro ppai2->setLeftNode(menor->getRightNode());
            menor->setRightNode(ppai2);
            delete pnode;
        }
            return true;
    }

  else if(RIGHT_NULL || pnode) //MACRO
    {
      maior = buscarMaior(pnode);
      ppai2 = buscarPai(maior);
      ppai2->setRighttNode(maior->getLeftNode()); /* como maior é o mais a direita, seu nó direito é nulo,
                                                   * então o seu pai(ppai2) deixa de apontar para ele(maior) e
                                                   * passa a apontar para seu nó esquerdo (que pode ser nulo ou não)
                                                   */


      if(pnode == root)
      {   /* maior agora é a raíz */
          maior->setLeftNode(root->getLeftNode());
          maior->setRightNode(root->getRightNode());
          setRoot(maior);
          delete root;
       }

      else
      {
          ppai->setLefttNode(maior);  /* nó pai não aponta para maior, invés de pnode */
          maior->seLeftNode(ppai2); /* ocupa agora o lugar de pnode */
          delete pnode;
      }
          return true;
    }
}


/*
 * Imprime no console todos os nodes um
 * nivel abaixo de um node info, exceto
 * os seus descendentes. Tambem imprime
 * a quantidade de sobrinhos impressos.
 */
template <typename T>
void BinTree::Sobrinhos(T info)
{ 
   std::cout << std::endl;

   int s = imprime_sobrinhos(this->root, getProfundidade(info), info);        /* esta funcao ja imprine os sobrinhos e retorna a quantidade de sobnrinhos */
   
   std::cout << std::endl << "Numero total de sobrinhos: " << s << std::endl;
}

/*
 * Retorna a profundidade de um elemento
 * da arvore. Se o elemento nao existir,
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
   int numero_sobrinhos = 0;                                      /* cada node tio podera imprimir ate 2 sobrinhos           */
   
   if(profundidade < 1)                                           /* para ter sobrinhos tem que ter profundidade minima de 1 */
      return 0;
      
   if(pnode == null)
      return 0;
      
   if(getProfundidade(pnode->info) == profundidade)               /* profundidade do tio ser igual ao do node pai            */
   {
      if(pnode->getInfo() != info)                                /* garantir que o node atual eh um tio                     */
      {
         Node* tio = pnode;
         Node* left = tio->getLeft();
         Node* right = tio->getRight();
      
         if(letf != NULL)
         {
            std::cout << left->getInfo() << ", ";
            numero_sobrinhos++;
         }
         if(right != NULL)
         {
            std::cout << right->getInfo() << ", ";
            numero_sobrinhos++;
         }
         
         return numero_sobrinhos;
      }
      else   return 0;                                            /* o pai nao eh tio, portanto 0 sobrinhos                  */
   }
   else
   {                                                              /* retorna a soma dos ramos da esquerda e da direita       */
      return imprime_sobrinhos(pnode->getLeft(), profundidade, info)
             + imprime_sobrinhos(pnode->getRight(), profundidade, info);
   }
}
