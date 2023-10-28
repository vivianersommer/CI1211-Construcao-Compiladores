#include "deslocamentos.h"

void inicializaPilhaDeslocamentos(PilhaDeslocamentos *pilhaDeslocamentos) {

    pilhaDeslocamentos = (PilhaDeslocamentos*) malloc(sizeof(PilhaDeslocamentos));
    inicializaPilha(pilhaDeslocamentos->deslocamentos);
}

void empilhaDescolamento(PilhaDeslocamentos *pilhaDeslocamentos, int identificador) {

    Deslocamento *deslocamento = (Deslocamento*) malloc(sizeof(Deslocamento));
    deslocamento->identificador = identificador;
    empilha(pilhaDeslocamentos->deslocamentos, deslocamento);
}

void desempilhaDescolamento(PilhaDeslocamentos *pilhaDeslocamentos) {
    desempilha(pilhaDeslocamentos->deslocamentos);
}