#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include "geometria.h"

//Estruturas da Árvore

typedef struct No {
    struct No *esq;
    struct No *dir;
    struct No *pai;
    Point p;
    int id;
} No;

typedef No* ptrNo;

//Funções

ptrNo cria_no(Point p, ptrNo pai, int id);
bool insere_filho(ptrNo pai, ptrNo filho);
void percurso_nos(ptrNo raiz, void (*callback)(ptrNo));
int conta_folhas(ptrNo raiz);
double comprimento_total(ptrNo raiz);
void libera_arvore(ptrNo raiz);

#endif