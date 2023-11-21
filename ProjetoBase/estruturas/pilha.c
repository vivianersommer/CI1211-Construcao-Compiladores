#include "pilha.h"
#define MAX 20

Pilha *inicializaPilha(Pilha *pilha) {

    pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->elementos = (void **) malloc(MAX*sizeof(void *));
    pilha->tamanhoMaximo = MAX;
    pilha->tamanhoAtual = 0;
    return pilha;
}

void empilha(Pilha *pilha, void *elemento) {

    if (pilha->tamanhoAtual == pilha->tamanhoMaximo) {
        pilha->elementos = realloc(pilha->elementos, 2 * pilha->tamanhoMaximo * sizeof(void*));
        pilha->tamanhoMaximo = 2 * pilha->tamanhoMaximo;
    }

    pilha->elementos[pilha->tamanhoAtual] = elemento;
    pilha->tamanhoAtual++;
}


void *desempilha(Pilha *pilha) {

    pilha->tamanhoAtual--;
    return pilha->elementos[pilha->tamanhoAtual];
}

void *buscaPilha(Pilha *pilha, int equal_func(void *, void *), void *elemento) {

    for (int i = pilha->tamanhoAtual-1; i >= 0; i--) {
        if (equal_func(pilha->elementos[i], elemento)) {
            return pilha->elementos[i];
        }
    }

    return NULL;
}

void imprimePilha(Pilha *pilha, void imprimeElemento(void*)) {
    if (pilha->tamanhoAtual ==0)
    {
        printf("PILHA VAZIA");
    }

    for (int i=0; i<pilha->tamanhoAtual; i++) {
        imprimeElemento(pilha->elementos[i]);
    }

    printf("\n");

}