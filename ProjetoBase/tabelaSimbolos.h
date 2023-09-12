#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct NodoSimbolo {
	char *ident, *rotulo;
	int nivel, deslocamento;
	struct NodoSimbolo *proximo;
} NodoSimbolo;

typedef struct TabelaSimbolos{
	int tamanho;
	NodoSimbolo *cabeca;
} TabelaSimbolos;

void inicializaTabelaSimbolos(TabelaSimbolos* tabelaSimbolos);
void insereNodoTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, NodoSimbolo* nodo);
NodoSimbolo *criaNodo(char *token, int nivel, int deslocamento);
TabelaSimbolos* removeNodoTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, int tamanho);
NodoSimbolo *buscaNodoTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, char* variavel);