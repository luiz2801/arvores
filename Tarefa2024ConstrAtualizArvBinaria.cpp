/* 

TRABALHO
ENVIAR ATÉ 28/10/2024 

O programa já contém uma função (mostrada na aula) para criar uma árvore completa:
-  os elementos são fornecidos em pré-ordem
- quando não há mais filhos, à esquerda ou à direita, deve-se fornecer o caractere que simboliza NULL ( "/" )  para indicar isso.

A tarefa á:
Completar o programa (percurso ordem central, pós-ordem, etc.) 
Criar funções adicionais (inserindo no menu do programa):

- Inserção de um valor "val"  em um filho à esquerda de determinado nó (com determinado conteúdo) 

- Inserção de um valor "val"  em um filho à direita de determinado nó (com determinado conteúdo) 
(são funções de retorno do tipo bool - se a tarefa foi realizada ou é impossível)

- Fornecer a soma dos elementos 
- Multiplicar todos os elementos por um certo valor.

Obs: decompor o problema, conforme discutido em sala: uma função que retorne o 
ponteiro para o nó em questão (ou NULL se ele não existir)

Sugestão: quando forem testar, desenhem em papel a árvore. Criem a árvore e explorem as opções inserir a esquerda (ou a direita) de determinado nó - acompanhem se a evolução da árvore está correta com as funções de percurso que exibem os nós em pré-ordem, pós-ordem ou central. 

*/



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

void construir_arvore(ptNo & p ) {
   tDado x;   
   
   cin >> x;
   if (x == '/') {        // não construir nó - não há subárvore naquele ponto
      p = NULL;
      return;
   }
   // alocar o nó
   p = new NoArvBin;
   p->dado = x;
  
   cout << "Ins. à esquerda de " << p->dado << ". " << endl;
   construir_arvore(p->esq );
   cout << "Ins. à direita de " << p->dado << ". " << endl;   
   construir_arvore(p->dir);
}   
   


void visitar (ptNo p)
{
   cout << p->dado << "  ";
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



// função já desenvolvida na última aula
ptNo localizaNo(ptNo p, tDado val)
{
     ptNo buscaEsq;     

     if (p == NULL)    //  não há elementos a procurar
         return NULL;
     if (p->dado == val)    // elemento encontrado
          return p;
      // tentativa na subárvore da esquerda - é retornado, se a busca teve sucesso
      buscaEsq = localizaNo(p->esq, val);
      if (buscaEsq != NULL)
           return buscaEsq;
      // tentativa na subárvore da direita - é retornado, com sucesso ou não
      return localizaNo(p->dir, val);
}
// inserir nó a direita de um já existente com certo conteúdo guardando o valor recebido 
// retornar true ou false caso tenha sido possível ou não a inserção
bool insereDireita(ptNo p, tDado contNo, tDado contNovoNo)
{
    ptNo loc = localizaNo(ptNo p, tDado contNo); // verifica se nó está presente na árvore
    if loc == NULL || loc->dir != NULL{
        return false; } // retorna falso se não tem nó ou se a direita n estivre livre

    ptNo newArrow = (ptNo*)malloc(sizeoff(ptNo)); // ponteiro novo para receber o dado a ser adicionado
    newArrow -> dado = contNovoNo; // atribui valor indicado pelo ponteiro o dado passado como parâmetro 
    contNovoNo -> esq, contNovoNo -> dir = NULL;
    return true    
}

    

bool insereEsquerda(ptNo p, tDado contNo, tDado contNovoNo)
{
    
 } 


void liberarArvore(ptNo &p)
{
     if (p != NULL)   // condiçao de parada
     {
         liberarArvore(p->esq);    // libera toda a subárvore da esquerda
         liberarArvore(p->dir);    // libera toda a subárvore da direita
         cout << "Liberando nó contendo o elemento " << p->dado << endl;         
         delete p;
         p = NULL;
     }        
}

void  exibirMenu( )
{
      cout << "1 -  Construir a árvore" << endl;
      cout << "2 -  Inserir a esquerda de nó"  << endl;
      cout << "3 -  Inserir a direita de nó"  << endl;
      cout << "4 -  Mostrar a árvore em pré-ordem"  << endl;
      cout << "5 -  Mostrar a árvore em pós-ordem"  << endl;
      cout << "6 -  Mostrar a árvore em ordem central"  << endl;
      cout << "7 -  Encerrar programa"  << endl << endl;
      cout << "Escolha uma opção:  " ;
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
                 construir_arvore(p);
                 break;
            case 2:
                 cout << "Forneca o conteúdo do nó de referência: ";
                 cin >> contNo;
                 cout << "Forneca o conteúdo do novo nó: ";
                 cin >> contNovoNo;
                 insereEsquerda(p, contNo, contNovoNo);
                 break;
            case 3:
                 cout << "Forneca o conteúdo do nó de referência: ";
                 cin >> contNo;
                 cout << "Forneca o conteúdo do novo nó: ";
                 cin >> contNovoNo;
                 insereDireita(p, contNo, contNovoNo);
                 break;
            case 4:
                 percorrer_pre_ordem(p);
                 cout << endl;
                 break;
            case 5:
                 percorrer_pos_ordem(p);
                 cout << endl;
                 break;
            case 6:
                 percorrer_ordem_central(p);
                 cout << endl;
                 break;
            case 7:
                 fimProg = true;
                 //break;
       }
   } while (! fimProg);
   liberarArvore(p);

}
