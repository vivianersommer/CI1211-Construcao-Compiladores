#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pilha.h"

typedef enum TipoVariavel {
	INTEIRO
} TipoVariavel;

typedef enum TipoParametro {
	VALOR,
	REFERENCIA
} TipoParametro;

typedef enum TipoNodo {
    VARIAVEL,
    PROCEDIMENTO,
    FUNCAO,
    PF,
    ROTULO
} TipoNodo;

typedef struct NodoSimbolo {
	char *identificacao;
	TipoNodo tipoNodo;
	int nivel;
	int deslocamento;
	TipoVariavel tipoVariavel;
	int rotulo;
	int numeroParametros;
	int *parametros;
	int tamanhoParametros;
} NodoSimbolo;

typedef struct TabelaSimbolos{
	Pilha *pilha;
} TabelaSimbolos;

TabelaSimbolos *inicializaTabelaSimbolos();
void insereNodoVariavelTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, char *ident, int nivel, int deslocamento);
void insereNodoPFTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, char *ident, int nivel);
void insereNodoProcedimentoTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, char *ident, int nivel, int rotulo);
void insereNodoFuncaoTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, char *ident, TipoVariavel tipoVariavel);
void adicionaParametrosNodoProcedimento(TabelaSimbolos *tabelaSimbolos, char* ident, TipoParametro tipoParam, TipoVariavel tipoVar, int quantidade);
void atualizaDeslocamentoParametros(TabelaSimbolos *tabelaSimbolos, char* ident);
NodoSimbolo *buscaNodoTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, char* variavel);
TabelaSimbolos* removeNodoTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, int tamanho);
void insereTipoVariavelTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, int quantidade, TipoVariavel tipoVariavel);
void imprimeNodoSimbolo(void *nodo);
void imprimeTabela(TabelaSimbolos* tabelaSimbolos);