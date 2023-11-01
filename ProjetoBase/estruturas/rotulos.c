#include "rotulos.h"

int numeroRotulos;

PilhaRotulos *inicializaPilhaRotulos() {

    numeroRotulos = 0;
    PilhaRotulos *pilhaRotulos = (PilhaRotulos*) malloc(sizeof(PilhaRotulos));
    pilhaRotulos->rotulos = inicializaPilha(pilhaRotulos->rotulos);
    return pilhaRotulos;
}

int geraRotulos(PilhaRotulos *pilhaRotulos) {

    Rotulo *rotulo = (Rotulo*) malloc(sizeof(Rotulo));
    rotulo->identificador = numeroRotulos;

    empilha(pilhaRotulos->rotulos, rotulo);
    numeroRotulos = numeroRotulos + 1;

    return rotulo->identificador;
}

int desempilhaRotulo(PilhaRotulos *pilhaRotulos) {

    Rotulo *rotulo = desempilha(pilhaRotulos->rotulos);
    return rotulo->identificador;
}

void empilhaRotulo(PilhaRotulos *pilhaRotulos, int identificador) {

    Rotulo *rotulo = (Rotulo*) malloc(sizeof(Rotulo));
    rotulo->identificador = identificador;
    empilha(pilhaRotulos->rotulos, rotulo);
}