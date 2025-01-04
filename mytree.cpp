#include <iostream>
#include <stdlib.h>
using namespace std;


typedef int tDado;
struct noArv{
    noArv *esq;
    noArv *dir;
    tDado dado;
};
typedef noArv * ptNo;

int buildTree(ptNo &p)
{
    tDado x;
    cout << "Digite um valor para o nó (use -1 para NULL): ";
    cin >> x;
    if (x == -1){
        p = NULL;
        return;
    }
    p = new noArv;
    p -> dado = x;
    p -> esq = NULL;
    p -> dir = NULL;
    cout << "Ins. à esquerda de " << p->dado << ". " << endl;
    buildTree(p->esq);
    cout << "Ins. à direita de " << p->dado << ". " << endl;
    buildTree(p->dir);
    return 1;
}

void showNode(ptNo p){
    cout <<"\n" << p ->dado << endl;
}

void preOrder (ptNo p){
    if (p->dado == NULL){
        return;
    }
    
    showNode(p);
    preOrder(p->esq);
    preOrder(p->dir);
}

void inOrder(ptNo p){
    if (p->dado == NULL){
        return;
    }
    inOrder(p->esq);
    showNode(p);
    inOrder(p->dir);
}

void postOrder(ptNo p){
    if (p->dado == NULL){
        return;
    }
    postOrder(p->esq);
    postOrder(p->dir);
    showNode(p);    
}


ptNo exists(ptNo p, int x){
    if (p == NULL)
    return;
    if (p -> dado == x){
        return p;
    }
    exists(p -> esq, x);
    exists(p -> dir, x);
}


int maxValue(ptNo &p){
    if (p == NULL){
        return;
    }
    int x = std::numeric_limits<int>::min();
    if (p -> dado > x){
        x = p -> dado;
    }

    maxValue(p -> esq);
    maxValue(p -> dir);
    return x;
}

int minValue(ptNo &p){
    if (p == NULL){
        return;
    }
    int x = std::numeric_limits<int>::max();
    if (p -> dado > x){
        x = p -> dado;
    }

    minValue(p -> esq);
    minValue(p -> dir);
    return x;
}

void addL(ptNo &p, int x, int y) //p = raiz, x = valor novo e y = valor buscado
{
    ptNo q = exists(p, y);
    if (q == NULL || q -> esq != NULL)
    {
        return;
    }
    ptNo s = new noArv;
    s -> dado = x;
    q -> esq = s;
    s -> esq = s -> dir = NULL;
}

void addR(ptNo &p, int x, int y) //p = raiz, x = valor novo e y = valor buscado
{
    ptNo q = exists(p, y);
    if (q == NULL || q -> dir != NULL)
    {
        return;
    }
    ptNo s = new noArv;
    s -> dado = x;
    q -> dir = s;
    s -> esq = s -> dir = NULL;
}


int sum(ptNo p)
{
    int x = 0;
    int x = x + p -> dado;
    sum(p -> esq);
    sum(p -> dir);
    cout <<x;
    return x;
}
