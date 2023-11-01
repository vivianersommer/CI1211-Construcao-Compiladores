#include "deslocamentos.h"

PilhaDeslocamentos *inicializaPilhaDeslocamentos() {

    PilhaDeslocamentos *pilhaDeslocamentos = (PilhaDeslocamentos*) malloc(sizeof(PilhaDeslocamentos));
    pilhaDeslocamentos->deslocamentos = inicializaPilha(pilhaDeslocamentos->deslocamentos);
    return pilhaDeslocamentos;
}

void empilhaDescolamento(PilhaDeslocamentos *pilhaDeslocamentos, int identificador) {

    Deslocamento *deslocamento = (Deslocamento*) malloc(sizeof(Deslocamento));
    deslocamento->identificador = identificador;
    empilha(pilhaDeslocamentos->deslocamentos, deslocamento);
}

int desempilhaDescolamento(PilhaDeslocamentos *pilhaDeslocamentos) {
    Deslocamento *deslocamento = desempilha(pilhaDeslocamentos->deslocamentos);
    return deslocamento->identificador;
}