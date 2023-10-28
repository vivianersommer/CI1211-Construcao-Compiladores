#include "rotulos.h"

int numeroRotulos;

void inicializaPilhaRotulos(PilhaRotulos *pilhaRotulos) {

    numeroRotulos = 0;
    pilhaRotulos = (PilhaRotulos*) malloc(sizeof(PilhaRotulos));
    inicializaPilha(pilhaRotulos->rotulos);
}

int geraRotulos(PilhaRotulos *pilhaRotulos) {

    Rotulo *rotulo = (Rotulo*) malloc(sizeof(Rotulo));
    rotulo->identificador = numeroRotulos;

    empilha(pilhaRotulos->rotulos, rotulo);

    numeroRotulos = numeroRotulos + 1;

    return rotulo->identificador;
}

void desempilhaRotulo(PilhaRotulos *pilhaRotulos) {

    desempilha(pilhaRotulos->rotulos);
}

void empilhaRotulo(PilhaRotulos *pilhaRotulos, int identificador) {

    Rotulo *rotulo = (Rotulo*) malloc(sizeof(Rotulo));
    rotulo->identificador = identificador;
    empilha(pilhaRotulos->rotulos, rotulo);
}