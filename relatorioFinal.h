#ifndef relatorioFinal_h
#define relatorioFinal_h

typedef struct relatorio rel;
typedef struct sbem sbem;
typedef struct lista_bens lista_bens;
typedef struct node no;

rel* criar_rel_fin();
lista_bens* criar_lista_bens();
int decoda_entrada_rel(rel *r,int c, int ct, char o, char *b);
int elabora_noh_insere_noh(rel* r,int cpf);
int destruir_relatorio(rel *r);
int destruir_no(no* node);
int destruir_lista_bens(lista_bens* lb);
int inserir_lista_bens(lista_bens* lb, char s,char *bem);
int existe_cpf_rel(rel *r,int cpf);
no* mostrar_cpf_ordenado(rel *r);
int imprimir_cpf_inicio(rel *r);
int imprimir_bens(lista_bens *lb)
no*  busca_cpf_rel(rel* r, int cpf);
int remover_noh_rel_inicio(rel *r);
int inserir_noh_no_rel_fin(rel* r,no n);
int remover_lista_bens_inicio(lista_bens* lb);
#endif
