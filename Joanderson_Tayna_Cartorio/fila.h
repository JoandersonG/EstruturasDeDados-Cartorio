/*
		Joanderson Gonçalves Santos
		Tayná Valverde Rosa
*/

#ifndef fila_h
#define fila_h


typedef struct client cliente;
typedef struct queue fila;

fila* criar_fila();
fila* destruir_fila(fila *f);
int inserir_cliente(fila *f, cliente c);
int elaborar_cliente_inserir_cliente(fila *f,int cpf, int cpf3, int prioridade, char op, char *bem);
int fila_vazia(fila *f);
int remover_cliente(fila *f);
int mostrar_cliente(fila *f,int* cpf, int* cpf3, int *prioridade, char *op, char *bem);

#endif
