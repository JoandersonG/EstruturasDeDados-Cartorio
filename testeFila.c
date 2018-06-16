#include <stdio.h>
#include <string.h>
#include "fila.h"
//#include "priority.h"
//#include "relatorioFinal.h"
//#include "pilha.h"

int main(){
	cliente a,b,c;
	a.cpf=123;
	a.cpf3=321;
	char as[]="Moto anos 50's";
	strcpy(a.bem,as);

	b.cpf=456;
	b.cpf3=654;
	char bem[]="Carro novo";

	fila* f=criar_fila();
	if(fila_vazia(f)){
		printf("Cero, vazia 1\n");
	}
	inserir_cliente(f,a);
	if(fila_vazia(f)){
		printf("Erro 1, vazia\n");
	}
	elaborar_cliente_inserir_cliente(f,456,654,2,'A',bem);
	cliente aux = mostrar_cliente(f);
	printf("cpf esp 123: %d\n",aux.cpf);
	remover_cliente(f);
	aux = mostrar_cliente(f);
	printf("cpf esp 456: %d\n",aux.cpf);
	remover_cliente(f);
	if(fila_vazia(f)){
		printf("certo, vazia\n");
	}
	f=destruir_fila(f);
	if(f==NULL){
		printf("Tudo certo\n");
	}
}
