#ifndef pilha_h
#define pilha_cheia

typedef struct node no;
typedef struct pilha pilha;

no elaborar_no(int cpfc,int cpft, char op, char* bem);
pilha* criar_pilhas(int tam,int k);
int destruir_pilhas(pilha *p,int m);
int destruir_pilha(pilha* p);
int inserir_pilha_elaborar_no(pilha* p,int cpfc,int cpft, char op, char *bem);
int inserir_pilha(pilha* p,no n);
int remover_pilha(pilha* p);
int imprime_topo_pilha(pilha* p);
no topo_pilha(pilha* p);
int mostrar_topo_pilha(pilha* p,int *cpf, int *cpf3,char* o,char *b);
pilha* inverter_pilha(pilha* p,int tamNoh);
int tamanho_pilha(pilha* p);
#endif
