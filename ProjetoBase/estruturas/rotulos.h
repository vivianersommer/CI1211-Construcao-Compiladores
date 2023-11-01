#ifndef __ROTULOS__
#define __ROTULOS__

#include <string.h>
#include "pilha.h"

typedef struct Rotulo {
    int identificador;
}Rotulo;

typedef struct PilhaRotulos {
    Pilha *rotulos;
}PilhaRotulos;

PilhaRotulos *inicializaPilhaRotulos();
int geraRotulos(PilhaRotulos *pilhaRotulos);
int desempilhaRotulo(PilhaRotulos *pilhaRotulos);
void empilhaRotulo(PilhaRotulos *pilhaRotulos, int identificador);

#endif