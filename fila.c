#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

typedef struct client cliente;
typedef struct queue fila;

fila* criar_fila(){
	fila *f= (fila*) malloc(sizeof(fila));
	if(f==NULL){
		printf("Erro: fila nula\n");
	}
	f->inicio=NULL;
	f->fim=NULL;
	f->tamanho=0;
	return f;
}

fila* destruir_fila(fila *f){
	if(f==NULL){
		printf("Erro 1 destruir_fila\n");
		return f;
 }
	while (f->tamanho!=0){
		remover_cliente(f);
		f->tamanho--;
	}
	free(f);
	f=NULL;
	return f;
}

int fila_vazia(fila *f){
	if(f==NULL) return -1;
	if(f->tamanho==0)
		return 1;
	return 0;
}

int inserir_cliente(fila *f, cliente c){
	cliente *cli = (cliente*) malloc (sizeof(cliente));
	if(cli==NULL) return -1;
	*cli = c;
	if(f->inicio==NULL){
		//está vazia e nesse caso esse nó será o primeiro e último
		f->inicio=cli;
		f->fim=cli;
	}
	else{
		f->fim->prox=cli;
		f->fim=f->fim->prox;
	}

  //	f->fim=cli;
	cli->prox=NULL;
	f->tamanho++;

	return 1;
}
int elaborar_cliente_inserir_cliente(fila *f,int cpf, int cpf3, int prioridade, char op, char *bem){
	if(f==NULL){
		printf("Erro 1 em elaborar_cliente_inserir_cliente\n");
	}
	cliente c;
	c.cpf=cpf;
	c.cpf3=cpf3;
	c.prioridade=prioridade;
	c.op=op;
	strcpy(c.bem,bem);

	inserir_cliente(f,c);
	return 1;
}
int remover_cliente(fila *f){

	if (f==NULL) {
		printf("Erro 1 remover_cliente");
		return -1;//se a fila é inválida e nula
	}
	if (f->inicio==NULL){
		printf("Erro 2 remover_cliente");
		return -1;//se a fila está vazia
	}
	cliente *aux=f->inicio;
	f->inicio=f->inicio->prox;
	f->tamanho--;
	free(aux);
	return 1;
}

cliente mostrar_cliente(fila *f){
	//se f->fim for NULL, então está vazia e retorna
	cliente c;
	if(f->inicio==NULL){
		printf("Erro 1 mostrar_cliente\n");
		return c;
	}
	cliente *cli = f->inicio;

	return *cli;
}
