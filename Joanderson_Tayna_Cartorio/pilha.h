/*
		Joanderson Gonçalves Santos
		Tayná Valverde Rosa
*/

#ifndef pilha_h
#define pilha_cheia

typedef struct nodeh noo;
typedef struct pilha pilha;

pilha* criar_pilhas(int tam,int k);
int destruir_pilhas(pilha *p,int m);
int inserir_pilha_elaborar_no(pilha* p,int cpfc,int cpft, char op, char *bem);
int inserir_pilha(pilha* p,noo n);
int remover_pilha(pilha* p);
int imprime_topo_pilha(pilha* p);
noo topo_pilha(pilha* p);
int mostrar_topo_pilha(pilha* p,int *cpf, int *cpf3,char* o,char *b);
int tamanho_pilha(pilha* p);
int pilha_vazia(pilha* p);
pilha* endereco_pilha(pilha* p,int i);
#endif
