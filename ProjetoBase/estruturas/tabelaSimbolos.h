#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef enum TipoVariavel {
	INTEIRO
} TipoVariavel;

typedef struct NodoSimbolo {
	char *ident;
	char *rotulo;
	int nivel;
	int deslocamento;
	TipoVariavel tipo;
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
void adicionaTipoVariavel(TabelaSimbolos *tabelaSimbolos, int quantidade, TipoVariavel tipo);
