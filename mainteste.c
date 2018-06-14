#include <stdio.h>
#include "fila.h"

int main(){
	cliente joan;
	cliente tayna;
	cliente diego;
	cliente aux;

	joan.cpf=123;
	tayna.cpf=456;
	diego.cpf=789;

	struct queue *f;
	f=criar_fila();
	if (fila_vazia(f)==1) {
		printf("Fila Vazia\n");
	}
	else if(fila_vazia(f)==-1){
		printf("Fila Nula\n");
	}
	else
		printf("Fila com elemento\n");

	printf("%d",inserir_cliente(f,joan));
	aux=mostrar_cliente(f);
	printf("%d\n",aux.cpf);
	printf("%d\n",remover_cliente(f));
	printf("%d\n",inserir_cliente(f,tayna));
	printf("%d\n",inserir_cliente(f,diego));
	aux=mostrar_cliente(f);
	printf("%d\n",aux.cpf);
	printf("%d\n",remover_cliente(f));
	aux=mostrar_cliente(f);
	printf("%d\n",aux.cpf);
	printf("%d\n",remover_cliente(f));
	printf("%d\n",fila_vazia(f));
	printf("Destruindo:\n");
	f=destruir_fila(f);

	if (fila_vazia(f)==1) {
		printf("Fila Vazia\n");
	}
	else if(fila_vazia(f)==-1){
		printf("Fila Nula\n");
	}
	else{
		printf("Fila com elemento\n");
	}
	/*
*/
}
