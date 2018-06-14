#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "priority.h"
#include "fila.h"

struct prioridade{
	fila* ponf;//ponteiro para fila
	struct prioridade* prox;
	int prioridade;
};

priority* criar_x_prioridades(int nfilas){

	priority* pri;
	priority* pq;
	priority* aux;

	pri= (priority*) malloc(sizeof(priority));
	pri->ponf=criar_fila();
	pri->prioridade=nfilas;
  //	printf("Fila criada. Prioridade: %d\n",pri->prioridade);
	pq=pri;

  //	pri é o ponteiro q aponta para o primeiro elemento da fila de prioridade

	for (int i = nfilas-1; i > 0; --i)//roda tantas vezes quanto o necessário?
	{
		aux = (priority*) malloc(sizeof(priority));

		pri->prox=aux;
		pri->prox->ponf=criar_fila();
		pri->prox->prioridade=i;
	//	printf("Fila criada. Prioridade: %d\n",pri->prox->prioridade);
		pri=pri->prox;
	}
	//no fim, pq aponta para o último elemento, no fim da fila
	pri->prox=NULL;
	if(pq->prox==NULL){
  //		printf("4.pq->prox==NULL. Falha na alocação\n");
	}
	return pq;
}
int elaborar_elem_adicionar_elem_pri(priority* p,int cpf, int cpf3, int prioridade, char op, char *bem){
	priority* aux=p;

	if(p->prox==NULL){
  //		printf("p->prox==NULL\n");
	}
	while(aux->prox!=NULL){

		if(aux->prioridade==prioridade){
			break;
		}
		aux=aux->prox;
	}//encontrei a prioridade dele

	if(prioridade!=aux->prioridade){
	//	printf("Erro 3: prioridade inexistente\n");
		return -1;//prioridade inexistente
	}
	int et=elaborar_cliente_inserir_cliente(aux->ponf,cpf,cpf3,prioridade,op,bem);//inseri ele em sua fila correta
  //	printf("Inserido cliente de cpf: %d na prioridade %d\n",c.cpf,aux->prioridade);
	if(et==-1){
  //		printf("Erro 2: cliente não inserido\n");
		return -2;//cliente não inserido
	}
	return 1;
}
int remover_frente_pri(priority* p){
	priority* aux=p;

	while(aux->prox!=NULL && fila_vazia(aux->ponf))
	{
		aux=aux->prox;
	}//aqui eu saí no último elemento ou no certo
	if(fila_vazia(aux->ponf))
	{
		return -1;//sem clientes para remover
	}
	remover_cliente(aux->ponf);
	return 1;
}
int mostrar_frente_pri(priority *p,int *cpf,int *cpf3, int* prioridade,char *o,char* b){
	if(p==NULL){
		printf("Erro 1 em enviar_atend\n");
		return -1;
	}
	cliente c=enviar_guiche(p);
	*cpf=c.cpf;
	*cpf3=c.cpf3;
	*prioridade=c.prioridade;
	*o=c.op;
	strcpy(b,c.bem);
	return 1;
}
cliente enviar_guiche(priority* p){
	if(p==NULL){
		printf("Erro 1 em enviar_guiche\n");
	}
	cliente cli;
	priority* aux=p;

	while (1) {
		if(aux->prox==NULL){
			if(fila_vazia(aux->ponf)){
				cli.cpf=0;
				cli.cpf3=0;//ignorar cpf 0
				cli.op='I';//ignorar
				cli.prioridade=0;//ignorar
				cli.prox=NULL;
				return cli;
			}
			else{
				cli= mostrar_cliente(aux->ponf);
				break;
			}
		}
		else{
			if(fila_vazia(aux->ponf)){
				aux=aux->prox;
				continue;
			}
			else{
				cli= mostrar_cliente(aux->ponf);
				break;
			}
		}
	}

  //	cli=mostrar_cliente(aux->ponf);
  //	printf("Enviei (e removi) cliente de cpf: %d\n",cli.cpf);
	//	int aux2=remover_cliente(aux->ponf);
  //	if(aux2==-1)
  //		printf("Erro em enviar_guiche\n");
	return cli;
}
priority* destruir_fila_pri(priority* p){
	//tou removendo os elementos???
	priority* aux=p;
	while(p!=NULL){
		aux=p;
		destruir_fila(p->ponf);
		p=p->prox;
		free(aux);
	}
	return p;
}
int exibir_todos(priority* p){
	cliente cli;
	while(p!=NULL){
		while(p->ponf->inicio!=NULL){
			cli=mostrar_cliente(p->ponf);
			printf("%d\n",cli.cpf);
			remover_cliente(p->ponf);
		}
		p=p->prox;
	}
	return 1;
}
int fila_pri_vazia(priority *p){
	cliente c=enviar_guiche(p);
	//se c.prioridade ==0, então entrou no caso em que não há elementos no guiche
	if(c.prioridade==0){
		return 1;
	}
	return 0;
}
