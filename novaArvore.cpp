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