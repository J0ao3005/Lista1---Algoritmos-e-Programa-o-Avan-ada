#include "arvore.h"

ptrNo cria_no(Point p, ptrNo pai, int id) {
    No *a = malloc(sizeof(No));
    if (a == NULL) {
        printf("Erro: falha ao alocar no.\n");
        return NULL;
    }
    a->esq = NULL;
    a->dir = NULL;
    a->pai = pai;
    a->p   = p;
    a->id  = id;
    return a;
}

bool insere_filho(ptrNo pai, ptrNo filho) {
    if (pai->esq == NULL) {
        pai->esq = filho;
        return true;
    }
    
    else if (pai->dir == NULL) {
        pai->dir = filho;
        return true;
    }

    else
        return false;
}

void percurso_nos(ptrNo raiz, void (*callback)(ptrNo)) {
    if (raiz == NULL) return;
    callback(raiz);
    percurso_nos(raiz->esq, callback);
    percurso_nos(raiz->dir, callback);
}

int conta_folhas(ptrNo raiz) {
    if (raiz == NULL)
        return 0;
    
    else if (raiz->dir == NULL && raiz->esq == NULL)
        return 1;
    
    else
        return conta_folhas(raiz->dir) + conta_folhas(raiz->esq);
}

double comprimento_total(ptrNo raiz) {
    if(raiz == NULL) return 0;
    double comp_atual = 0;

    if(raiz->pai != NULL) {
        comp_atual = distancia(raiz->p, raiz->pai->p);
    }

    return comp_atual + comprimento_total(raiz->esq) + comprimento_total(raiz->dir);
}

void libera_arvore(ptrNo raiz) {
    if (raiz == NULL) return;
    libera_arvore(raiz->esq);
    libera_arvore(raiz->dir);
    free(raiz);
}