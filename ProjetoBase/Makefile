 # -------------------------------------------------------------------
 #            Arquivo: Makefile
 # -------------------------------------------------------------------
 #              Autor: Bruno Müller Junior
 #               Data: 08/2007
 #      Atualizado em: [09/08/2020, 19h:01m]
 #
 # -------------------------------------------------------------------

$DEPURA=1

compilador: lex.yy.c compilador.tab.c compilador.o compilador.h tabelaSimbolos.o deslocamentos.o rotulos.o pilha.o
	gcc lex.yy.c compilador.tab.c compilador.o tabelaSimbolos.o deslocamentos.o rotulos.o pilha.o -o compilador -ll -ly -lc

lex.yy.c: compilador.l compilador.h
	flex compilador.l

compilador.tab.c: compilador.y compilador.h
	bison compilador.y -d -v

compilador.o : compilador.h compiladorF.c
	gcc -c compiladorF.c -o compilador.o

pilha.o : estruturas/pilha.h estruturas/pilha.c
	gcc -c estruturas/pilha.c -o pilha.o

deslocamentos.o : estruturas/deslocamentos.h estruturas/deslocamentos.c
	gcc -c estruturas/deslocamentos.c -o deslocamentos.o

rotulos.o : estruturas/rotulos.h estruturas/rotulos.c
	gcc -c estruturas/rotulos.c  -o rotulos.o

tabelaSimbolos.o : estruturas/tabelaSimbolos.h estruturas/tabelaSimbolos.c
	gcc -c estruturas/tabelaSimbolos.c  -o tabelaSimbolos.o

clean :
	rm -f compilador.tab.* lex.yy.c ;
	rm -f compilador.o compilador compilador.output *.o MEPA;