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
void insereTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, NodoSimbolo* nodo);
NodoSimbolo *cria_nodo(char *token, int nivel, int deslocamento);
TabelaSimbolos* remove_nodo(TabelaSimbolos* tabelaSimbolos, int tamanho);