#include "pilha.h"
#define MAX 100

void inicializaPilha(Pilha *pilha) {

    pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->elementos = (void **) malloc(MAX*sizeof(void *));
    pilha->tamanhoMaximo = MAX;
    pilha->tamanhoAtual = 0;
}

void empilha(Pilha *pilha, void *elemento) {

    if (pilha->tamanhoAtual == pilha->tamanhoMaximo) {
        pilha->elementos = realloc(pilha->elementos, 2 * pilha->tamanhoMaximo * sizeof(void*));
        pilha->tamanhoMaximo = 2 * pilha->tamanhoMaximo;
    }

    pilha->elementos[pilha->tamanhoAtual] = elemento;
    pilha->tamanhoAtual++;
}


void desempilha(Pilha *pilha) {

    if (pilha->tamanhoAtual <= 0) {
        printf("Erro ao desempilhar -----------------------------\n");
    }

    pilha->tamanhoAtual--;
}
