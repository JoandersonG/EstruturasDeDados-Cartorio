simulacao: simulacao.o pilha.o fila.o priority.o relatorioFinal.o
	gcc-7 simulacao.o pilha.o fila.o priority.o relatorioFinal.o -o simulacao

simulacao.o: simulacao.c
	gcc-7 -c simulacao.c  -g -Wall -Wextra -Werror -Wpedantic

pilha.o: pilha.c pilha.h
	gcc-7 -c pilha.c  -g -Wall -Wextra -Werror -Wpedantic

fila.o: fila.c fila.h
	gcc-7 -c fila.c  -g -Wall -Wextra -Werror -Wpedantic

priority.o: priority.c priority.h # fila.c fila.h
	gcc-7 -c priority.c  -g -Wall -Wextra -Werror -Wpedantic

relatorioFinal.o: relatorioFinal.c relatorioFinal.h
	gcc-7 -c relatorioFinal.c  -g -Wall -Wextra -Werror -Wpedantic

clean:
	rm *.o simulacao
