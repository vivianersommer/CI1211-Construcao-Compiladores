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

void inicializaPilhaDeslocamentos(PilhaDeslocamentos *pilhaDeslocamentos);
void empilhaDescolamento(PilhaDeslocamentos *pilhaDeslocamentos, int identificador);
void desempilhaDescolamento(PilhaDeslocamentos *pilhaDeslocamentos);

#endif