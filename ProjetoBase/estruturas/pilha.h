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

void inicializaPilha(Pilha *pilha);
void empilha(Pilha *pilha, void *novoElemento);
void desempilha(Pilha *s);

#endif