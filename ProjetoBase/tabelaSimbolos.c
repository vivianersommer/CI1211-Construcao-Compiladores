#include "tabelaSimbolos.h"


void inicializaTabelaSimbolos(TabelaSimbolos* tabelaSimbolos) {
	tabelaSimbolos = (TabelaSimbolos*) malloc(sizeof(TabelaSimbolos));
	tabelaSimbolos->tamanho = 0;
	tabelaSimbolos->cabeca = NULL;
}

void insereNodoTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, NodoSimbolo* nodo) {
	nodo->proximo = tabelaSimbolos->cabeca;
	tabelaSimbolos->cabeca = nodo; 
	tabelaSimbolos->tamanho++;
}

NodoSimbolo *criaNodo(char *token, int nivel, int deslocamento) {
	NodoSimbolo *nodo = (NodoSimbolo*) malloc(sizeof(NodoSimbolo));
	nodo->ident = (char *) malloc(sizeof(token));
	strcpy(nodo->ident, token);
	nodo->nivel = nivel;
	nodo->deslocamento = deslocamento;
	return nodo;
}

TabelaSimbolos* removeNodoTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, int tamanho) {

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

NodoSimbolo *buscaNodoTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, char* variavel) {
	NodoSimbolo* cabeca = tabelaSimbolos->cabeca;
	int i = 0;

	while ((i < tabelaSimbolos->tamanho) && 
            (strcmp(variavel, cabeca->ident))) {
		cabeca = cabeca->proximo;
		i++;
	}

	return cabeca;
}

void adicionaTipoVariavel(TabelaSimbolos *tabelaSimbolos, int quantidade, TipoVariavel tipo) {
	NodoSimbolo* nodo = tabelaSimbolos->cabeca;
	while (tabelaSimbolos && quantidade--) {
		nodo->tipo = tipo;
		nodo = nodo->proximo;
	}
}