#include "tabelaSimbolos.h"


void inicializaTabelaSimbolos(TabelaSimbolos* tabelaSimbolos) {
	tabelaSimbolos = (TabelaSimbolos*) malloc(sizeof(TabelaSimbolos));
	tabelaSimbolos->tamanho = 0;
	tabelaSimbolos->cabeca = NULL;
}

void insereTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, NodoSimbolo* nodo) {
	nodo->proximo = tabelaSimbolos->cabeca;
	tabelaSimbolos->cabeca = nodo; 
	tabelaSimbolos->tamanho++;
}

NodoSimbolo *cria_nodo(char *token, int nivel, int deslocamento) {
	NodoSimbolo *nodo = (NodoSimbolo*) malloc(sizeof(NodoSimbolo));
	nodo->ident = (char *) malloc(sizeof(token));
	strcpy(nodo->ident, token);
	nodo->nivel = nivel;
	nodo->deslocamento = deslocamento;
	return nodo;
}

TabelaSimbolos* remove_nodo(TabelaSimbolos* tabelaSimbolos, int tamanho) {

	int quantidade = tabelaSimbolos->tamanho > tamanho ? tamanho : tabelaSimbolos->tamanho;
	NodoSimbolo *temporario;
	while (quantidade--) {
		temporario = tabelaSimbolos->cabeca;
		tabelaSimbolos->cabeca = tabelaSimbolos->cabeca->proximo;
		free(temporario);
		tabelaSimbolos->tamanho--;
	}
	return tabelaSimbolos;
}
