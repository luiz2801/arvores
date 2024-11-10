#include <iostream>
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
    int x;
    if (p -> dado > x){
        x = p -> dado;
    }
    if (p == NULL){
        return;
    }
    maxValue(p -> esq);
    maxValue(p -> dir);
    return x;
}

int minValue(ptNo &p){
    int x;
    if (p -> dado < x){
        x = p -> dado;
    }
    if (p == NULL){
        return;
    }
    minValue(p -> esq);
    minValue(p -> dir);
    return x;
}

