#include <iostream>
using namespace std;
 
typedef int tDado;

struct NoArvBin
{
    NoArvBin * esq;  // ponteiro para a subárvora da esquerda
    tDado dado;      // dado armazenado
    NoArvBin * dir;  // ponteiro para a subárvora da direita
};


typedef NoArvBin * ptNo;      // Tipo ptNo - definição de ponteiros para nós de uma árvore

void construirArvore(ptNo & p ) {
   tDado x;   
   
   std::cin >> x;
   if (x == 0) {        // não construir nó - não há subárvore naquele ponto
      p = NULL;
      return;
   }
   // alocar o nó
   p = new NoArvBin;
   p->dado = x;
  
   std::cout << "Ins. à esquerda de " << p->dado << ". " << endl;
   construirArvore(p->esq );
   std::cout << "Ins. à direita de " << p->dado << ". " << endl;   
   construirArvore(p->dir);
}   
   


void visitar (ptNo p)
{
   std::cout << p->dado << "  ";
}

void percorrer_pre_ordem(ptNo p )
{
      if (p!= NULL)
      {
            visitar(p);
            percorrer_pre_ordem(p->esq );
            percorrer_pre_ordem(p->dir );
      }
}

void percorrer_pos_ordem(ptNo p )
{
      if (p!= NULL)
      {
            percorrer_pos_ordem(p->esq );
            percorrer_pos_ordem(p->dir );
            visitar(p);
      }
}

void percorrer_central_ordem(ptNo p )
{
      if (p!= NULL)
      {
            percorrer_central_ordem(p->esq );
            visitar(p);
            percorrer_central_ordem(p->dir );
      }
}


// função já desenvolvida na última aula
ptNo localizaNo(ptNo p, tDado val)
{
     ptNo busca;

     if (p == NULL)    //  não há elementos a procurar
         return NULL;

     if (p->dado == val)    // elemento encontrado
          return p;

     // tentativa na subárvore da esquerda - é retornado, se a busca teve sucesso
     busca = localizaNo(p->esq, val);
     if (busca != NULL)
          return busca;
     // tentativa na subárvore da direita - é retornado, com sucesso ou não
     return localizaNo(p->dir, val);
}

// inserir nó a direita de um já existente com certo conteúdo guardando o valor recebido 
// retornar true ou false caso tenha sido possível ou não a inserção
bool insereDireita(ptNo p, tDado contNo, tDado contNovoNo)
{
     ptNo localizacao = localizaNo(p, contNo); // verifica se nó está presente na árvore
     if (localizacao == NULL || localizacao->dir != NULL)
          return false;
          // retorna falso se não tem nó ou se a direita não estiver livre

     // ponteiro novo para receber o dado a ser adicionado
     ptNo novoPonteiro = (NoArvBin*) malloc(sizeof(ptNo));
     localizacao->dir = novoPonteiro;
     // atribui valor indicado pelo ponteiro o dado passado como parâmetro
     novoPonteiro->dado = contNovoNo;
     novoPonteiro->esq = novoPonteiro->dir = NULL;
     return true;
}

    

bool insereEsquerda(ptNo p, tDado contNo, tDado contNovoNo)
{
     ptNo localizacao = localizaNo(p, contNo); // verifica se nó está presente na árvore
     if (localizacao == NULL || localizacao->esq != NULL)
          // retorna falso se não tem nó ou se a direita não estiver livre
          return false;

     // ponteiro novo para receber o dado a ser adicionado
     ptNo novoPonteiro = (NoArvBin*) malloc(sizeof(ptNo));
     localizacao->esq = novoPonteiro;
     // atribui valor indicado pelo ponteiro o dado passado como parâmetro
     novoPonteiro->dado = contNovoNo;
     novoPonteiro->esq = novoPonteiro->dir = NULL;
     return true;
} 


void liberarArvore(ptNo &p)
{
     if (p != NULL)   // condiçao de parada
     {
         liberarArvore(p->esq);    // libera toda a subárvore da esquerda
         liberarArvore(p->dir);    // libera toda a subárvore da direita
         std::cout << "Liberando nó contendo o elemento " << p->dado << endl;         
         delete p;
         p = NULL;
     }        
}

void  exibirMenu( )
{
     std::cout << "1 -  Construir a árvore" << endl;
     std::cout << "2 -  Inserir a esquerda de nó"  << endl;
     std::cout << "3 -  Inserir a direita de nó"  << endl;
     std::cout << "4 -  Mostrar a árvore em pré-ordem"  << endl;
     std::cout << "5 -  Mostrar a árvore em pós-ordem"  << endl;
     std::cout << "6 -  Mostrar a árvore em ordem central"  << endl;
     std::cout << "7 -  Encerrar programa"  << endl << endl;
     std::cout << "Escolha uma opção:  " ;
}

int main ()
{
   ptNo p = NULL;    // inicializar árvore
   int opc;
   bool fimProg = false;
   tDado contNo,contNovoNo;
   do 
   {
       exibirMenu( );
       cin >> opc;
       switch (opc)
       {
            case 1:
                 construirArvore(p);
                 break;
            case 2:
                 std::cout << "Forneca o conteúdo do nó de referência: ";
                 std::cin >> contNo;
                 std::cout << "Forneca o conteúdo do novo nó: ";
                 std::cin >> contNovoNo;
                 insereEsquerda(p, contNo, contNovoNo);
                 break;
            case 3:
                 std::cout << "Forneca o conteúdo do nó de referência: ";
                 std::cin >> contNo;
                 std::cout << "Forneca o conteúdo do novo nó: ";
                 std::cin >> contNovoNo;
                 insereDireita(p, contNo, contNovoNo);
                 break;
            case 4:
                 percorrer_pre_ordem(p);
                 std::cout << endl;
                 break;
            case 5:
                 percorrer_pos_ordem(p);
                 std::cout << endl;
                 break;
            case 6:
                 percorrer_central_ordem(p);
                 std::cout << endl;
                 break;
            case 7:
                 fimProg = true;
                 //break;
       }
   } while (! fimProg);
   liberarArvore(p);

}
