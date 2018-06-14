#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int cpfc,cpft;
	char bem[26];
	char op;
};
struct pilha{
	int topo;
	int capacidade;
	struct node *noh;
};

//typedef struct node no;
//typedef struct pilha pilha;

no elaborar_no(int cpfc,int cpft, char op, char* bem){
	no n;
	n.cpfc=cpfc;
	n.cpft=cpft;
	n.op=op;
	strcpy(n.bem,bem);
	return n;
}
pilha* criar_pilhas(int tam,int k){
	pilha *p =(pilha*) malloc(sizeof(pilha)*k);
	if(p==NULL){
		printf("Erro 1 em criar_pilhas\n");
		return p;
	}
	for (int i = 0; i < k; i++) {
		p[i]->noh = (no*) malloc(sizeof(no)*tam);
		if(p[i]->noh==NULL){
			printf("Erro 2 em criar_pilhas\n", );
			return p;
		}
		p[i]->topo=-1;
		p[i]->capacidade=tam;
	}
	return p;
}
int destruir_pilhas(pilha *p,int m){
	if(p==NULL){
		printf("Erro 1 em destruir_pilha\n");
		return -1;
	}
	for (int i = 0; i < m; i++) {
		destruir_pilha(p[i]);
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
	no n;
	n.cpfc=cpfc;
	n.cpft=cpft;
	n.op=op;
	strcpy(n.bem,bem);
	inserir_pilha(p,n);
	return 1;
}
int inserir_pilha(pilha* p,no n){
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
	no n=topo_pilha(p);
	printf("%s\n",n.bem);
	return 1;
}
no topo_pilha(pilha* p){
	no erro;
	if(p==NULL){
		printf("Erro 1 em topo_pilha\n");
		return erro;
	}
	if(p->topo==-1){//vazia
		printf("Erro 2 em topo_pilha\n");
		return erro;
	}
	return p->noh[p->topo];
}
int mostrar_topo_pilha(pilha* p,int *cpf, int *cpf3,char* o,char *b){
	if(p==NULL){
		printf("Erro 1 em mostrar_topo_pilha\n");
	}
	no n=topo_pilha(p);
	*cpf=n->cpfc;
	*cpf3=n->cpft;
	*p=n->op;
	strcpy(b,p->bem);
	return 1;
}
pilha* inverter_pilha(pilha* p,int tamNoh){
	pilha* aux = (pilha*) malloc(sizeof(pilha));
	if(aux==NULL){
		printf("Erro 1 em inverter_pilha\n");
	}
	aux->noh = (no*) malloc(sizeof(no)*tamNoh);
	if(aux->noh==NULL){
		printf("Erro 2 em inverter_pilha\n");
	}
	for (int i = 0,int j= p->topo; i <= p->topo; j++,i++) {
			aux->noh[i]=p->noh[j];
	}
	destruir_pilha(p);
	return aux;
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
		printf("Erro 1 em tamanho_pilha\n");
		return -1;
	}
	if(p->topo==-1) return 1;
	return 0;
}
