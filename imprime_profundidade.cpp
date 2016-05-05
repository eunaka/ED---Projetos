
public:
/*
 * Imprime todos os elementos presentes na
 * arvore por profundidade. Ou seja, cada linha
 * impressa contera todos os elementos de uma
 * mesma profundidade.
 */
//template <typename T>
void BinTree::imprimirArvore()
{ 
	int i = 0;
   std::cout << std::endl;
	while(1)
	{
	/*
	 * cada iteracao imprime a profundidade.
	 * Quando for uma profundidade que possui todos os nodes
	 * com valor nullo significa que todos os elementos
	 * foram impressos.
	 */
		if(imprime_profundidade(this->root, i) == false)
			return;
			
		std::cout << std::endl;
		i++;
	}
}


//template <typename T>
int BinTree::getProfundidade(T info)
{
   Node* pnode = this->root;
   int profundidade = -1;          /* caso o elemento seja nulo            */
   
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
   
   return -1;                       /* caso nenhum elemento seja encontrado */
}

private:
/*
 * Imprime os nodes que estao em uma certa
 * profundidade. Deve ser chamado passando
 * a raiz da arvore como parametro.
 */
//template <typename T>
bool BinTree::imprime_profundidade(Node<T>* pnode, int profundidade)
{
   if(pnode == NULL)
   {
      std::cout << "  ";
      return false;
   }

   if(getProfundidade(pnode->getInfo()) == profundidade)
   {
  	   std::cout << pnode->getInfo() << "\t";
     	return true;
   }
   /*
    * por ser um metodo recursivo, quando chegar em uma
    * profundidade que nao existem elementos, ou seja,
    * quando todos os nodes sao nulos, as chamadas recursivas
    * irao todas retornar false. Por definicao, o operador
    * or ( || ) retorna false se todos os termos forem false.
    * Se apenas um termo retornad true, sera true.
    */
   else
      return imprime_profundidade(pnode->getLeft(), profundidade)
             || imprime_profundidade(pnode->getRight(), profundidade);
}







