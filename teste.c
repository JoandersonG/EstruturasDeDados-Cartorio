#include <stdio.h>
//#include "fila.h"
#include "priority.h"


int main(){
	struct client tayna,aux,joan,diego;



	tayna.cpf=123;
	tayna.prioridade=2;

	joan.cpf=456;
	joan.prioridade=1;

	diego.cpf=789;
	diego.prioridade=2;

	aux.cpf=111;

	priority* p=criar_x_prioridades(3);

	adicionar_elemento(p,tayna);
	adicionar_elemento(p,joan);
	adicionar_elemento(p,diego);

//	exibir_todos(p);

	aux=enviar_guiche(p);
	printf("%d\n",aux.cpf);

	aux=enviar_guiche(p);
	printf("%d\n",aux.cpf);

	aux=enviar_guiche(p);
	printf("%d\n",aux.cpf);

	aux=enviar_guiche(p);
	printf("%d\n",aux.cpf);

	aux=enviar_guiche(p);
	printf("%d\n",aux.cpf);

	p=destruir_fila_pri(p);
	if(p==NULL)
		printf("Certo\n");



	/*


	struct queue *f=criar_fila();
	inserir_cliente(f,tayna);
	aux=mostrar_cliente(f);
	printf("%d\n",aux.cpf);
	remover_cliente(f);
	aux=mostrar_cliente(f);
	printf("%d\n",aux.cpf);
	destruir_fila(f);
	*/

}
