#include <stdlib.h>
#include "relatorioFinal.h"
#include <stdio.h>
#include <string.h>

struct sbem{
  char s;
  char bem[26];
  struct sbem *prox;
};
struct lista_bens{
  struct sbem *ini;
  struct sbem *fim;
  int tamanho;
};
struct node{
  int cpf;
  struct node *prox;
  struct node *ant;
  struct lista_bens *lb;
};
struct relatorio{
  struct node *inicio;
  struct node *fim;
  int tamanho;
};

int elabora_noh_insere_noh(rel* r,int cpf){
  if(r==NULL){
    printf("Erro 1 em insere_noh_elaborar_noh\n");
    return -1;
  }
  no n;
  n.cpf=cpf;
  n.prox=NULL;
  n.ant=NULL;
  n.lb=NULL;
  inserir_noh_no_rel_fin(r,n);
  return 1;
}
rel *criar_rel_fin(){
  rel* r = (rel*) malloc(sizeof(rel));
  if(r==NULL){
    printf("Erro 1 em criar_rel_fin\n");
    return r;
  }
  r->inicio=NULL;
  r->fim=NULL;
  r->tamanho=0;
  return r;
}
int tamanho_relatorio(rel *r){
  if(r==NULL){
    printf("Erro 1 em tamanho_relatorio\n");
    return -1;
  }
  return r->tamanho;
}
int relatorio_vazio(rel *r){
  if(r==NULL){
    printf("Erro 1 em relatorio_vazio\n");
    return -1;
  }
  if(r->tamanho==0){
    return 1;
  }
  return 0;
}
lista_bens *criar_lista_bens(){
  lista_bens *l=(lista_bens*) malloc(sizeof(lista_bens));
  if(l==NULL){
    printf("Erro 1 em criar_lista_bens\n");
    return l;
  }
  l->ini=NULL;
  l->fim=NULL;
  l->tamanho=0;
  return l;
}
int decoda_entrada_rel(rel *r,int c, int ct, char o, char *b){
  if(r==NULL){
    printf("Erro 1 em decoda_entrada_rel\n");
    return -1;
  }
  if(!existe_cpf_rel(r,c)){
    //se não existe, crio nó com esse cpf
  //    printf("Não existia o cpf %d, então, criado.\n",c);
    no n;
    n.cpf=c;
    inserir_noh_no_rel_fin(r,n);
  }
  if(!existe_cpf_rel(r,ct)){
    //se não existe, crio nó com esse cpf
  //    printf("Não existia o cpf %d, então, criado.\n",ct);
    no nn;
    nn.cpf=ct;
    inserir_noh_no_rel_fin(r,nn);
  }
  //cliente:
  no* aux=busca_cpf_rel(r,c);
  inserir_lista_bens(aux->lb,o,b);
  //printf("Em CPF: %d, está %s\n",c,b);
  //terceiro:
  aux=busca_cpf_rel(r,ct);
  if(o=='T'){
    inserir_lista_bens(aux->lb,'A',b);
  }
  else{
    inserir_lista_bens(aux->lb,'T',b);
  }
  return 1;
}
no*  busca_cpf_rel(rel* r, int cpf){
  if(r==NULL){
    printf("Erro 1 em busca_cpf_rel\n");
    no *n=NULL;
    return n;
  }
  no *aux=r->inicio;
  int cont=1;
  while(cont<=r->tamanho && aux->cpf!=cpf){
    aux=aux->prox;
    cont++;
  }
  if(aux->cpf!=cpf){
    //não achou
    aux=NULL;
    return aux;
  }
  return aux;
}
int destruir_relatorio(rel *r){
  if(r==NULL){
    printf("Erro 1 em destruir_relatorio\n");
    return -1;
  }
  while (r->tamanho>1) {
    remover_noh_rel_inicio(r);
  }
  free(r);
  return 1;
}
int destruir_no(no* node){
  if(node==NULL){
    printf("Erro 1 destruir_no\n");
    return -1;
  }
  //aqui eu chamo:
  destruir_lista_bens(node->lb);
  free(node);
  node=NULL;
  return 1;
}
int destruir_lista_bens(lista_bens* lb){
  if(lb==NULL){
    printf("Erro 1 em destruir_lista_bens\n");
    return -1;
  }
  sbem* aux;
  while(lb->tamanho>1){
  //  remover_sbem_inicio(lb->ini);
    aux=lb->ini;
    lb->ini=lb->ini->prox;
    free(aux);
    lb->tamanho--;
  }
  return 1;
}
int inserir_noh_no_rel_fin(rel* r,no n){
  if(r==NULL){
    printf("Erro 1 em inserir_noh_no_rel_fin\n");
    return -1;
  }
  no *node=(no*)malloc(sizeof(no));
  if(node==NULL){
    printf("Erro 2 em inserir_noh_no_rel_fin\n");
    return -1;
  }
  *node=n;
  node->lb=criar_lista_bens();
  if(r->inicio==NULL)//vazia
  {
    r->inicio=node;
    r->fim=node;
    r->inicio->prox=r->inicio;
    r->inicio->ant=r->inicio;
    r->tamanho++;
  //  printf("Colocado num relatório vazio\n");
    return 1;
  }
  no *aux=r->inicio;
  if(aux->cpf>node->cpf){
    //no começo
    r->inicio=node;
    node->prox=aux;
    node->ant=r->fim;
    r->fim->prox=node;
    aux->ant=node;
    r->tamanho++;
    //  printf("Colocado no inicio\n");
    return 1;
  }
  int aux3=1;
  while(aux3<=r->tamanho && node->cpf>aux->cpf){
    aux=aux->prox;
    aux3++;
    //printf("Rodei o while\n");
  }
  if(node->cpf>aux->cpf){
    //coloco no fim
    /*
    aux=r->fim;
    r->fim=node;
    node->prox=r->inicio;
    node->ant=aux;
    r->inicio->ant=node;
    */
    node->prox=aux;
    aux->ant->prox=node;
    node->ant=aux->ant;
    aux->ant=node;
    r->tamanho++;
    //printf("Colocado no fim\n");
    return 1;
  }
  else{
    //coloco no meio
    //node deve ser inserido antes local q aux aponta
    no *aux2=aux;
    aux=aux->ant;
    aux->prox=node;
    node->ant=aux;
    node->prox=aux2;
    aux2->ant=node;
    r->tamanho++;
    //printf("Colocado no meio\n");
  }
  return 1;
}
int inserir_lista_bens(lista_bens* lb, char s,char *bem){
  if(lb==NULL){
    printf("Erro 1 em inserir_sbem\n");
    return -1;
  }

  sbem sbbem;
  sbbem.s=s;
  strcpy(sbbem.bem,bem);

  sbem *ss=(sbem*)malloc(sizeof(sbem));
  *ss=sbbem;
  //se tiver vazia:
  if(lb->tamanho==0){
    lb->tamanho++;
    lb->ini=ss;
    lb->fim=ss;
    ss->prox=NULL;
    return 1;
  }
    //bens ordenados por ordem lexicográfica

  sbem *aux=lb->ini;

  if(strcmp(ss->bem,aux->bem)<0){
    //no inicio
    ss->prox=lb->ini;
    lb->ini=ss;
    lb->tamanho++;
    return 1;

  }

  while(aux->prox!=NULL && strcmp(ss->bem,aux->prox->bem)>=0){
    aux=aux->prox;
  }//saio quando s->bem < aux ou aux==NULL;
  if(aux->prox==NULL){
    //coloco no fim
    lb->fim->prox=ss;
    lb->fim=ss;
    ss->prox=NULL;
    return 1;
  }

  //no meio

  //preciso disso???
  aux=aux->prox;
  //
  //  sbem* aux2=aux->prox;
  ss->prox=aux->prox;
  aux->prox=ss;

  return 1;
}
int existe_cpf_rel(rel *r,int cpf){
  if(r==NULL){
    printf("Erro 1 em existe_cpf_rel\n");
    return -1;
  }
  if(r->inicio==NULL){
    return 0;
  }
  no *aux=r->inicio;

  int cont=1;
  while(cont<=r->tamanho && aux->cpf!=cpf){
    aux=aux->prox;
    cont++;
  }

  if(aux->cpf==cpf){
    return 1;//já existe tal cpf
  }

  return 0;//não existe tal cpf ainda
}
no* mostrar_cpf_ordenado(rel *r){
  if(r==NULL){
    printf("Erro 1 em mostrar_cpf_ordenado\n");
    no *err=NULL;
    return err;
  }
  if(r->tamanho==0){
    printf("Erro 2 em mostrar_cpf_ordenado\n");
    no *err=NULL;
    return err;
  }
  return r->inicio;
}
int imprimir_cpf_inicio(rel *r){
  if(r==NULL){
    printf("Erro 1 em exibir_cpf_inicio\n");
    return -1;
  }
  no* n=mostrar_cpf_ordenado(r);
  printf("%d: %d\n",n->cpf,n->lb->tamanho);
  imprimir_bens(n->lb);
  return 1;
}
int imprimir_bens(lista_bens *lb){
  if(lb==NULL){
    printf("Erro 1 em imprimir_bens\n");
    return -1;
  }
  int cont=1;
  char c;
  while(cont<=lb->tamanho){
    c=lb->ini->s;
    printf("%c %s\n",c,lb->ini->bem);
    lb->ini=lb->ini->prox;
    cont++;
  }
  return 1;
}
/*
*/
int remover_noh_rel_inicio(rel *r){
  if(r==NULL){
    printf("Erro 1 em remover_cpf_rel_ini\n");
    return -1;
  }
  if(r->tamanho==0){
    printf("Erro 2 em remover_cpf_rel_ini\n");
    return -1;
  }
  no *aux=r->inicio;
  r->inicio=r->inicio->prox;
  r->fim->prox=r->inicio;
  r->inicio->ant=r->fim;
  r->tamanho--;
  //  para free (aux) [um nó]:
  destruir_no(aux);
  destruir_lista_bens(aux->lb);
  //  free(aux);
  aux=NULL;
  return 1;
}
int remover_lista_bens_inicio(lista_bens* lb){
  if(lb==NULL){
    printf("Erro 1 em remover_lista_bens_inicio\n");
    return -1;
  }
  if(lb->ini==NULL){
    printf("Erro 2 em remover_lista_bens_inicio\n");
    return -1;
  }
  //  remover_sbem_inicio(lb->ini);
  sbem* aux=lb->ini;
  lb->ini=lb->ini->prox;
  lb->tamanho--;
  free(aux);
  return 1;
}
/*
*/
