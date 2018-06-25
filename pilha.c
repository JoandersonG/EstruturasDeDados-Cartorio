/*
		Joanderson Gonçalves Santos
		Tayná Valverde Rosa
*/

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

pilha* endereco_pilha(pilha* p,int i)
{
	if(p==NULL){
		printf("Erro 1 em endereco_pilha\n");
		return p;
	}
	return &p[i];
}

pilha* criar_pilhas(int tam,int k)
{
	pilha *p =(pilha*) malloc(sizeof(pilha)*k);
	if(p==NULL){
		printf("Erro 1 em criar_pilhas\n");
		return p;
	}
	for (int i = 0; i < k; i++) {
		(p[i]).noh = (noo*) malloc(sizeof(noo)*tam);
		if((p[i]).noh==NULL){
			printf("Erro 2 em criar_pilhas\n");
			return p;
		}
		p[i].topo=-1;
		p[i].capacidade=tam;
	}
	return p;
}
int destruir_pilhas(pilha *p,int m){
	if(p==NULL){
		printf("Erro 1 em destruir_pilha\n");
		return -1;
	}
	for (int i = 0; i < m; i++) {
		free(p[i].noh);
	}
	free(p);
	return 1;

}

int inserir_pilha_elaborar_no(pilha* p,int cpfc,int cpft, char op, char *bem)
{
	//elaboro o nó e então insiro na pilha;
	noo n;
	n.cpfc=cpfc;
	n.cpft=cpft;
	n.op=op;
	strcpy(n.bem,bem);
	inserir_pilha(p,n);
	return 1;
}

int inserir_pilha(pilha* p,noo n)
{
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
	return 1;
}
int remover_pilha(pilha* p)
{
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

int imprime_topo_pilha(pilha* p)
{
	if(p==NULL){
		printf("Erro 1 em imprime_topo_pilha\n");
	}
	noo n=topo_pilha(p);
	printf("imprime_topo_pilha: %d     %s\n",n.cpfc,n.bem);
	return 1;
}
noo topo_pilha(pilha* p)
{
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
int mostrar_topo_pilha(pilha* p,int *cpf, int *cpf3,char* o,char *b)
{
	if(p==NULL){
		printf("Erro 1 em mostrar_topo_pilha\n");
	}
	noo n=topo_pilha(p);
	*cpf=n.cpfc;
	*cpf3=n.cpft;
	*o=n.op;
	strcpy(b,n.bem);
	return 1;
}

int tamanho_pilha(pilha* p)
{
	if(p==NULL){
		printf("Erro 1 em tamanho_pilha\n");
		return -1;
	}
	return p->topo+1;
}

int pilha_vazia(pilha* p)
{
	if(p==NULL){
		printf("Erro 1 em pilha_vazia\n");
		return -1;
	}
	if(p->topo==-1){
	  return 1;
	}
	return 0;
}
