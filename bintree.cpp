#include <iostream>
#include "bintree.h"
#include "node.h"

#define LEFT_NULL  (!pnode->getLeftNode() && pnode->getRightNode())
#define RIGHT_NULL (pnode->getLeftNode() && !pnode->getRightNode())
#define COMPLETO   (pnode->getLeftNode() && pnode->getRightNode())


BinTree::BinTree()
{
  this->root = NULL;
}

/* checa a existencia de um nó */
bool BinTree::existe(int info)
{
    Node* pnode = this->root;

    while(true)
    {
        if(pnode == NULL)
            return false;

        if(pnode->getInfo() == info)
            return true;

        if(pnode->getInfo() < info)
            pnode = pnode->getRightNode();

        else if(pnode->getInfo() > info)
            pnode = pnode->getLeftNode();
    }
}

/* retorna o nó que possue o inteiro passado, NULL cajo não encontre */
Node* BinTree::consultar(int info)
{
  Node* pnode = this->root;

  while(true)
  {
      if(pnode == NULL)
          return NULL;

      if(pnode->getInfo() == info)
          return pnode;

     if(info < pnode->getInfo())
          pnode = pnode->getLeftNode();

     else if(info > pnode->getInfo())
          pnode = pnode->getRightNode();

  }
}

void BinTree::inserir(int info)
{
    Node* pnode = this->root;
    Node* novo;

    if(!this->root)
    {
        novo = new Node(info);
        this->root = novo;
        return;
    }

    while(true)
    {
        if(info < pnode->getInfo())
        {
            if(pnode->getLeftNode() == NULL)
            {
                novo = new Node(info);
                pnode->setLeftNode(novo);
                return;
            }

            pnode = pnode->getLeftNode();
        }

        if(info > pnode->getInfo())
        {
            if(pnode->getRightNode() == NULL)
            {
                novo = new Node(info);
                pnode->setRightNode(novo);
                return;
            }

             pnode = pnode->getRightNode();
        }

        if(info == pnode->getInfo())
        {
            std::cout << "Elemento ja faz parte da arvore\n";
            return;
        }
    }
}

/* retorna o node com menor informação pela direita de pnode */
Node* BinTree::buscarMenor(Node* pnode)
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
Node* BinTree::buscarMaior(Node* pnode)
{
    /* começa procurando pela esquerda de pnode (maior do lado esquerdo)*/
    pnode = pnode->getLeftNode();

    while(true)
      {
        if(pnode->getRightNode() == NULL)
            return pnode;

        if(pnode->getRightNode() != NULL)
            pnode = pnode->getRightNode();
      }
}


/* retorna o pai de pnode, NULL caso pnode seja raíz */
Node* BinTree::buscarPai(Node* pnode)
{
   Node* ppai = this->root;

   if(pnode == this->root || pnode == NULL)
      return NULL;

   while(true)
  {
       if(ppai->getLeftNode() == pnode || ppai->getRightNode() == pnode)
          return ppai;

       if(ppai->getInfo() < pnode->getInfo())
          ppai = ppai->getRightNode();

       else if(ppai->getInfo() > pnode->getInfo())
          ppai = ppai->getLeftNode();
  }

}

bool BinTree::remover(int info)
{
  Node* pnode;     /* nó que será excluído, é retornado pelo método consultar() */
  Node* ppai;      /* ponteiro para o pai, é o pai de pnode, retornado pelo método buscarPai() */
  Node* node_subs; /* nó substituto, ocupará o lugar de pnode. Pode conter ou a maior ou a menor informação */
  Node* ppai_subs; /* pai do nó substituto, necessário para realizar algumas trocas */

  pnode = consultar(info); /* encontra o nó que será excluído */

  if(pnode == NULL)
      return false;

  ppai = buscarPai(pnode);             /* encontra o pai de pnode, se pnode for raíz, retorna NULL */

  /* se for folha */
  if(pnode->isLeaf())
  {
      if(pnode == this->root)
          this->root = NULL;

      delete pnode; /* chama destrutor de pnode */
      pnode = NULL;
      return true;
  }

  /* node_subs será o menor nó do lado direito */
  if(LEFT_NULL || COMPLETO) //MACRO DEFINIDA NO INÍCIO DO ARQUIVO
  {
        node_subs = buscarMenor(pnode);
        ppai_subs = buscarPai(node_subs);

        /*  se o pai do menor já é o próprio pnode, para removê-lo
         *  basta fazer com que o menor aponte para o nó esquerdo de pnode
         *  e o pai de pnode aponte para o menor.
         *  OBS: o menor nao tem nenhum filho à esquerda
        */
        if(ppai_subs == pnode)
        {
            node_subs->setLeftNode(pnode->getLeftNode());

            if(ppai != NULL)  /* checa se pnode está no nó direito ou esquerdo de ppai, e faz ppai apontar para node_subs */
            {
               if(ppai->getLeftNode() == pnode)
                    ppai->setLeftNode(node_subs);

                else if(ppai->getRightNode() == pnode)
                    ppai->setRightNode(node_subs);
            }

            if(pnode == this->root)
                this->root = node_subs; /* o menor será a nova raíz */
            delete pnode;
            pnode = NULL;
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
            this->root = node_subs;
         }

        else
        {   /* verifica se pnode está do lado direito ou esquerdo do pai e o substitui pelo menor */
            if(ppai->getRightNode() == pnode)
                ppai->setRightNode(node_subs);
            else
                ppai->setLeftNode(node_subs);

            node_subs->setRightNode(pnode->getRightNode());
            node_subs->setLeftNode(pnode->getLeftNode());
        }
        pnode = NULL;
        delete pnode;
        return true;
    }

  /* nesse caso, o node_subs será o maior nó do lado esquerdo */
  else if(RIGHT_NULL || COMPLETO) //MACRO  DEFINIDA NO INÍCIO DO ARQUIVO
    {
      node_subs = buscarMaior(pnode);
      ppai_subs = buscarPai(node_subs);

      /*  se o pai do maior já é o próprio pnode, para removê-lo
       *  basta fazer com que o maior aponte para o nó direito de pnode
       *  e o pai de pnode aponte para o nó substituto(node_subs).
       *  OBS: o maior nao tem nenhum filho à direita
       */
      if(ppai_subs == pnode)
      {
          node_subs->setRightNode(pnode->getRightNode());

          if(ppai != NULL && ppai != ppai_subs)  /* checa se pnode está no nó direito ou esquerdo de ppai, e faz ppai apontar para node_subs */
          {
             if(ppai->getLeftNode() == pnode)
                  ppai->setLeftNode(node_subs);

              else if(ppai->getRightNode() == pnode)
                  ppai->setRightNode(node_subs);
          }

          if(pnode == this->root)
            this->root = node_subs;

          delete pnode;
          pnode = NULL;
          return true;
      }

      ppai_subs->setRightNode(node_subs->getLeftNode());
      /* como node_subs é o maior, não há mais ninguém na sua direita
       * então o seu pai(ppai2) deixa de apontar para ele(maior) e
       * passa a apontar para seu nó esquerdo (que pode ser nulo ou não)
       */

      if(pnode == this->root)
      {   /* maior agora é a raíz */
          node_subs->setLeftNode(pnode->getLeftNode());
          node_subs->setRightNode(pnode->getRightNode());
          this->root = node_subs;
       }

      else
      {
          /* verifica se pnode está do lado direito ou esquerdo do pai e o substitui pelo maior */
          if(ppai->getLeftNode() == pnode)
              ppai->setLeftNode(node_subs);

          else
              ppai->setRightNode(node_subs);

          node_subs->setLeftNode(pnode->getLeftNode());
          node_subs->setRightNode(pnode->getRightNode());
      }

      delete pnode; /* chama o destrutor de pnode */
      return true;
    }
}

/*
 * Imprime no console todos os nodes um nivel
 * abaixo de um node info, exceto os seus descendentes.
 * Tambem imprime a quantidade de sobrinhos
 * impressos.
 */

void BinTree::sobrinhos(int info)
{
   std::cout << std::endl;

   int s = imprime_sobrinhos(this->root, getProfundidade(info), info);                   /* este metodo ja imprime os sobrinhos */

   std::cout << std::endl << "Numero total de sobrinhos: " << s << std::endl;
}

/*
 * Retorna a profundidade de um elemento da
 * arvore. Para elemento nulo, retorna -1.
 * A raiz tem profundidade 0.
 */

int BinTree::getProfundidade(int info)
{
   Node* pnode = this->root;
   int profundidade = -1;          /* caso o elemento seja nulo            */

   while(pnode != NULL)
   {
      profundidade++;
      if(info == pnode->getInfo())
         return profundidade;

      else if(info < pnode->getInfo())
         pnode = pnode->getLeftNode();

      else
         pnode = pnode->getRightNode();
   }

   return -1;                       /* caso nenhum elemento seja encontrado */
}

/*
 * Imprime todos os nodes filhos de uma
 * profundidade, exceto do node info.
 * Retorna a quantidade de nodes impressos.
 */
int BinTree::imprime_sobrinhos(Node* pnode, int profundidade, int info)
{
   int numero_sobrinhos = 0;                     /* quantidade de sobrinhos que um node pode imprimir, maximo de 2 */
   Node* left;
   Node* right;

   if(profundidade < 1)
      return 0;
   if(pnode == NULL)
      return 0;

   if(getProfundidade(pnode->getInfo()) == profundidade)
   {
      if(pnode->getInfo() != info)               /* pnode eh um tio                                                */
      {
         left = pnode->getLeftNode();
         right = pnode->getRightNode();

         if(left != NULL)
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
         return 0;                                /* se pnode for o pai, ele nao tem sobrinhos para imprimir       */
   }
   else                                           /* retorna o numero de sobrinhos da esquerda e da direita        */
      return imprime_sobrinhos(pnode->getLeftNode(), profundidade, info)
             + imprime_sobrinhos(pnode->getRightNode(), profundidade, info);
}

/* comentários abaixo */
void BinTree::limpar(Node* pnode)
{
   if (pnode != NULL)
    {
        limpar(pnode->getLeftNode());
        limpar(pnode->getRightNode());
        if(pnode == this->root) this->root = NULL;
        delete pnode;
     }
}

/* é usado para desalocar a memória utilizada pelos nodes, caso o usuário não remova todos os elementos
 * chama o método acima para realizar as desalocações dos nodes
 */
void BinTree::limparArvore()
{
    if(this->root)
      this->limpar(this->root);
}


