#ifndef __PILHA__
#define __PILHA__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Pilha {
    void **elementos;
    int tamanhoAtual;
    int tamanhoMaximo;
}Pilha;

Pilha *inicializaPilha();
void empilha(Pilha *pilha, void *novoElemento);
void *desempilha(Pilha *s);
void *buscaPilha(Pilha *pilha, int equal_func(void *, void *), void *elemento);
void imprimePilha(Pilha *pilha, void imprimeElemento(void*));

#endif