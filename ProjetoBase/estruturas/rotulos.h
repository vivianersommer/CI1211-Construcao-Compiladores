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

void inicializaPilhaRotulos(PilhaRotulos *pilhaRotulos);
int geraRotulos(PilhaRotulos *pilhaRotulos);
void desempilhaRotulo(PilhaRotulos *pilhaRotulos);
void empilhaRotulo(PilhaRotulos *pilhaRotulos, int identificador);

#endif