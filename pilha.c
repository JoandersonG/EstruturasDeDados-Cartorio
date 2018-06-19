#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodeh{
	int cpfc,cpft;
	char bem[26];
	char op;
};
struct pilha{
	int topo;
	int capacidade;
	struct nodeh *noh;
};

//typedef struct node no;
//typedef struct pilha pilha;
pilha* endereco_pilha(pilha* p,int i){
	if(p==NULL){
		printf("Erro 1 em endereco_pilha\n");
		return p;
	}
	return &p[i];
}
/*
noo elaborar_no(int cpfc,int cpft, char op, char* bem){
	noo n;
	n.cpfc=cpfc;
	n.cpft=cpft;
	n.op=op;
	strcpy(n.bem,bem);
	return n;
}
*/
pilha* criar_pilhas(int tam,int k){
	pilha *p =(pilha*) malloc(sizeof(pilha)*k);
	if(p==NULL){
		printf("Erro 1 em criar_pilhas\n");
		return p;
	}
  //	printf("Criado: %d pilhas.\n",k);
	for (int i = 0; i < k; i++) {
		(p[i]).noh = (noo*) malloc(sizeof(noo)*tam);
		if((p[i]).noh==NULL){
			printf("Erro 2 em criar_pilhas\n");
			return p;
		}
		p[i].topo=-1;
		p[i].capacidade=tam;
	}
  //	printf("Criado: %d nós em cada pilha.\n",tam);
	return p;
}
int destruir_pilhas(pilha *p,int m){
	if(p==NULL){
		printf("Erro 1 em destruir_pilha\n");
		return -1;
	}
	for (int i = 0; i < m; i++) {
		destruir_pilha(&p[i]);
	}
	p=NULL;
	return 1;

}
int destruir_pilha(pilha* p){
	if(p==NULL){
		printf("Erro 1 em destruir_pilha\n");
		return -1;
	}
	/*

		*/
	free(p->noh);
	free(p);
	p=NULL;
	return 1;
}
/*
int pilha_cheia(pilha *p){
	if(p==NULL){
		printf("Erro 1 em pilha_cheia\n");
	}
	if(p->topo==p->capacidade-1){
		return 1;//tá cheia
	}
	return 0;//não cheia
}
*/
int inserir_pilha_elaborar_no(pilha* p,int cpfc,int cpft, char op, char *bem){
	//elaboro o nó e então insiro na pilha;
	noo n;
	n.cpfc=cpfc;
	n.cpft=cpft;
	n.op=op;
	strcpy(n.bem,bem);
	//printf("inserindo: %d,%d,%c,%s\n",cpfc,cpft,op,bem);
	inserir_pilha(p,n);
	return 1;
}
int inserir_pilha(pilha* p,noo n){
	if(p==NULL){
		printf("Erro 1 em inserir_pilha\n");
		return -1;
	}
	if(p->topo==p->capacidade-1){//pilha_cheia
		printf("Erro 2 em inserir_pilha\n");
		return -1;
	}
	p->topo++;
	p->noh[p->topo]=n;
	//printf("inserido: %d,%d,%c,%s\n",p->noh[p->topo].cpfc,p->noh[p->topo].cpft,p->noh[p->topo].op,p->noh[p->topo].bem);
	return 1;
}
int remover_pilha(pilha* p){
	if(p==NULL){
		printf("Erro 1 em remover_pilha\n");
		return -1;
	}
	if(p->topo==-1){//vazia
		printf("Erro 2 em remover_pilha\n");
		return -1;
	}
	p->topo--;
	return 1;
}

int imprime_topo_pilha(pilha* p){
	if(p==NULL){
		printf("Erro 1 em imprime_topo_pilha\n");
	}
	noo n=topo_pilha(p);
	printf("imprime_topo_pilha: %d     %s\n",n.cpfc,n.bem);
	return 1;
}
noo topo_pilha(pilha* p){
	if(p==NULL){
		printf("Erro 1 em topo_pilha\n");
		noo erro;
		erro.cpfc=0;
		erro.cpft=0;
		return erro;
	}
	if(p->topo==-1){//vazia
		printf("Erro 2 em topo_pilha\n");
		noo erro;
		erro.cpfc=0;
		erro.cpft=0;
		return erro;
	}
	return p->noh[p->topo];
}
int mostrar_topo_pilha(pilha* p,int *cpf, int *cpf3,char* o,char *b){
	if(p==NULL){
		printf("Erro 1 em mostrar_topo_pilha\n");
	}
	noo n=topo_pilha(p);
	*cpf=n.cpfc;
	*cpf3=n.cpft;
	*o=n.op;
  //	printf("Em mostrar_topo_pilha: CPF: %d. Bem: %s\n",n.cpfc,n.bem);
	strcpy(b,n.bem);
	return 1;
}
// int trocar_i_de_pilha(pilha* pMain,int i,pilha* p2){
// 	if(pMain==NULL){
// 		printf("Erro 1 em trocar_i_de_pilha\n");
// 		return -1;
// 	}
// 	pMain[i]=*p2;
// 	return 1;
// }
pilha* inverter_pilha(pilha* p){
	// pilha* aux = (pilha*) malloc(sizeof(pilha));
	// if(aux==NULL){
	// 	printf("Erro 1 em inverter_pilha\n");
	// }
	// aux->noh = (noo*) malloc(sizeof(noo)*p->capacidade);
	// if(aux->noh==NULL){
	// 	printf("Erro 2 em inverter_pilha\n");
	// }
	// int j = p->topo;

	//-----------
  //printf("%d\n",p->noh[p->topo].cpfc);
	// for (size_t i = 0; i <= p->topo; i++) {
	//
	// }
	/*
	for (int i = 0; i <= p->topo; j--,i++) {
			aux->noh[i]=p->noh[j];
	}
	for (int i = 0; i <p->capacidade; i++) {
		p->noh[i]=aux->noh[i];
	}
	*/
	int cont=0,ppr=p->topo;
	noo n;
	noo auxi[p->topo+1];
	auxi[ppr].cpfc=123;
	while (cont<=ppr) {
		n=topo_pilha(p);
		remover_pilha(p);
		auxi[cont]=n;
		cont++;
	}
	cont=0;
	while (cont<=ppr) {
		n=auxi[cont];
		inserir_pilha(p,n);
		cont++;
	}



  //printf("%d\n",p->noh[p->topo].cpfc);
//	aux->topo=p->topo;
//	aux->capacidade=p->capacidade;
//	destruir_pilha(aux);
//	free(auxi);
	return p;
}
int tamanho_pilha(pilha* p){
	if(p==NULL){
		printf("Erro 1 em tamanho_pilha\n");
		return -1;
	}
	return p->topo+1;
}
int pilha_vazia(pilha* p){
	if(p==NULL){
		printf("Erro 1 em pilha_vazia\n");
		return -1;
	}
	if(p->topo==-1){
	  return 1;
	}
	return 0;
}
