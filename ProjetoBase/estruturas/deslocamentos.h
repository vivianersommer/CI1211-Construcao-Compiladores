#ifndef __DESLOCAMENTOS__
#define __DESLOCAMENTOS__

#include <string.h>
#include "pilha.h"

typedef struct Deslocamento {
    int identificador;
} Deslocamento;

typedef struct PilhaDeslocamentos {
    Pilha *deslocamentos;
} PilhaDeslocamentos;

PilhaDeslocamentos *inicializaPilhaDeslocamentos();
void empilhaDescolamento(PilhaDeslocamentos *pilhaDeslocamentos, int identificador);
int desempilhaDescolamento(PilhaDeslocamentos *pilhaDeslocamentos);

#endif