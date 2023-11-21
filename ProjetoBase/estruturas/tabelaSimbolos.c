#include "tabelaSimbolos.h"


TabelaSimbolos *inicializaTabelaSimbolos() {
	TabelaSimbolos *tabelaSimbolos = (TabelaSimbolos*) malloc(sizeof(TabelaSimbolos));
	tabelaSimbolos->pilha = inicializaPilha(tabelaSimbolos->pilha);
	return tabelaSimbolos;
}

void imprimeNodoSimbolo(void *nodo) {
    printf("[identificacao=%s,", ((NodoSimbolo *)nodo)->identificacao);
    printf("tipoNodo=%d,", (int)((NodoSimbolo *)nodo)->tipoNodo);
    printf("nivel=%d,",(int)((NodoSimbolo *)nodo)->nivel );
    printf("deslocamento=%d,", (int)((NodoSimbolo *)nodo)->deslocamento);
    printf("tipoVariavel=%d]\n", (int)((NodoSimbolo *)nodo)->tipoVariavel);
}

void imprimeTabela(TabelaSimbolos* tabelaSimbolos) {
    printf("\nTABELA SIMBOLOS: \n");
    imprimePilha(tabelaSimbolos->pilha, imprimeNodoSimbolo);

}

void insereNodoVariavelTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, char *ident, int nivel, int deslocamento) {
	NodoSimbolo *nodo = (NodoSimbolo*) malloc(sizeof(NodoSimbolo));

	nodo->tipoNodo = VARIAVEL;
	nodo->nivel = nivel;
	nodo->deslocamento = deslocamento;
	nodo->identificacao = (char *) malloc(sizeof(char) * strlen(ident));
	strcpy(nodo->identificacao, ident);

	empilha(tabelaSimbolos->pilha, nodo);
}

void insereNodoParametroFormalTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, char *ident, int nivel) {
	NodoSimbolo *nodo = (NodoSimbolo*) malloc(sizeof(NodoSimbolo));

	nodo->tipoNodo = PARAMETRO_FORMAL;
	nodo->nivel = nivel;
	nodo->deslocamento = 0;
	nodo->identificacao = (char *) malloc(sizeof(char) * strlen(ident));
	strcpy(nodo->identificacao, ident);

	empilha(tabelaSimbolos->pilha, nodo);
}

void insereNodoProcedimentoTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, char *ident, int nivel, int rotulo) {
	NodoSimbolo *nodo = (NodoSimbolo*) malloc(sizeof(NodoSimbolo));

	nodo->tipoNodo = PROCEDIMENTO;
	nodo->nivel = nivel;
	nodo->rotulo = rotulo;
	nodo->numeroParametros = 0;
	nodo->tamanhoParametros = 10;
	nodo->parametros = (int *) malloc (nodo->tamanhoParametros * 2 * sizeof(int));
	nodo->identificacao = (char *) malloc(sizeof(char) * strlen(ident));
	strcpy(nodo->identificacao, ident);

	empilha(tabelaSimbolos->pilha, nodo);
}

void insereNodoFuncaoTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, char *ident, TipoVariavel tipoVariavel) {
	NodoSimbolo *nodo = buscaNodoTabelaSimbolos(tabelaSimbolos, ident);

	nodo->tipoNodo = FUNCAO;
	nodo->tipoVariavel = tipoVariavel;
	nodo->deslocamento = ((-4) - (nodo->numeroParametros));

}


void adicionaParametrosNodoProcedimento(TabelaSimbolos *tabelaSimbolos, char* ident, TipoParametro tipoParam, TipoVariavel tipoVar, int quantidade){
    NodoSimbolo *nodo = buscaNodoTabelaSimbolos(tabelaSimbolos, ident);

    for (int i = 0; i < quantidade; i++){
        if (nodo->numeroParametros >= nodo->tamanhoParametros){
            nodo->tamanhoParametros = 2 * nodo -> tamanhoParametros;
            nodo->parametros = realloc(nodo->parametros, nodo->tamanhoParametros * 2 * sizeof(int));
        }

        nodo->parametros[2 * nodo->numeroParametros] = tipoVar;
        nodo->parametros[2 * nodo->numeroParametros+1] = tipoParam;

        nodo->numeroParametros += 1;
    }
}

void atualizaDeslocamentoParametros(TabelaSimbolos *tabelaSimbolos, char* ident){
    NodoSimbolo *nodo_1 = buscaNodoTabelaSimbolos(tabelaSimbolos, ident);

    int i = tabelaSimbolos->pilha->tamanhoAtual - 1;
    int deslocamento = -4;
    while (deslocamento >= ((-3) - (nodo_1->numeroParametros))) {
        NodoSimbolo *nodo_2 = tabelaSimbolos->pilha->elementos[i];
        nodo_2->deslocamento = deslocamento;
        deslocamento--;
        i--;
    }
}

int checaIgual(void *a, void *b) {

    return !strcmp(((NodoSimbolo *)a)->identificacao, (char *)b);
}

NodoSimbolo *buscaNodoTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, char* variavel){
    NodoSimbolo *nodo = (NodoSimbolo *) buscaPilha(tabelaSimbolos->pilha, checaIgual, (void *)variavel);
    return nodo;
}

TabelaSimbolos* removeNodoTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, int tamanho){
    for (int i=0; i<tamanho; i++){
        desempilha(tabelaSimbolos->pilha);
    }
}

void insereTipoVariavelTabelaSimbolos(TabelaSimbolos* tabelaSimbolos, int quantidade, TipoVariavel tipoVariavel){
    for (int i=tabelaSimbolos->pilha->tamanhoAtual-1; i>=tabelaSimbolos->pilha->tamanhoAtual-quantidade; i--) {
        NodoSimbolo *nodo  = tabelaSimbolos->pilha->elementos[i];
        nodo->tipoVariavel = tipoVariavel;
    }
}

