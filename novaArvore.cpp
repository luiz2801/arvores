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

void novaArvore(ptNo p){
    tDado novoNo;
    std:: cin >> novoNo;
    if (novoNo == -1){
        return;}

    p = new NoArvBin;
    p -> dado = novoNo; 
    std:: cout<< "Dado à esquerda de " << p-> dado;
    novaArvore(p->esq);
    std:: cout<< "Dado à direita de " << p-> dado;
    novaArvore(p->dir);

}

int visitar(ptNo p){
    std::cout << p ->dado << "  ";
    return p-> dado;
}
void pre_ordem(ptNo p)
{
    if (p == NULL)
    {
        return;
    }
    visitar(p);
    pre_ordem(p->esq);
    pre_ordem(p->dir);
}

void pos_ordem(ptNo p){
    if (p == NULL)
    {
        return;
    }
    pos_ordem(p->esq);
    pos_ordem(p->dir);
    visitar(p);    
}

void central(ptNo p){
        if (p == NULL)
    {
        return;
    }
    central(p->esq);
    visitar(p);
    central(p->dir);
}

int soma(ptNo p)
{
    if (p == NULL) {
        return 0;  // Se o nó é nulo, retorna 0
    }
    int a = p->dado;
    a += soma(p->esq);
    a += soma(p->dir);
    return a;
}

void localizar(ptNo p)
{
    
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
     std::cout << "8 - Somar os dados da árvore" << endl << endl;
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
                 novaArvore(p);
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
                 pos_ordem(p);
                 std::cout << endl;
                 break;
            case 6:
                 central(p);
                 std::cout << endl;
                 break;
            case 7:
                 fimProg = true;
                 //break;
       }
   } while (! fimProg);
   liberarArvore(p);

}
