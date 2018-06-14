//#define fila_h
#ifndef fila_h
#define fila_h

struct client{
	int cpf,cpf3,prioridade;
	char op;
	char bem[26];
	struct client *prox;
};
typedef struct client cliente;

struct queue{
	cliente *inicio, *fim;
	int tamanho;
};
typedef struct queue fila;

fila* criar_fila();
fila* destruir_fila(fila *f);
int inserir_cliente(fila *f, cliente c);
int elaborar_cliente_inserir_cliente(fila *f,int cpf, int cpf3, int prioridade, char op, char *bem);
int fila_vazia(fila *f);
int remover_cliente(fila *f);
cliente mostrar_cliente(fila *f);

#endif
