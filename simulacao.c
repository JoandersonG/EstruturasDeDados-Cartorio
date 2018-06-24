#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "relatorioFinal.h"
#include "priority.h"

int inserir_cliente_fila(priority * pr,int c,int ct,int p,char o,char *b){
  if(pr==NULL){
    printf("Erro 1 em inserir_cliente_fila\n");
    return -1;
  }

  elaborar_elem_adicionar_elem_pri(pr,c,ct,p,o,b);
  return 1;
}
int ler_linhas_entrada(priority* pr, int n){

  int c,ct,p;
  char o,b[26];
  char lixo;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %c",&c,&ct,&p,&o);
    scanf("%c\n",&lixo);
    setbuf(stdin, NULL);
    scanf("%[^\n]s",b);
    setbuf(stdin, NULL);
    formatar_bem(b);
    inserir_cliente_fila(pr,c,ct,p,o,b);
  }//adicionei todos os clientes em suas filas
  return 1;
}
int gerar_relatorio_final(rel *r, int cpf, int cpf3, char op, char * bem){
  if(r==NULL){
    printf("Erro 1 em gerar_relatorio_final\n");
    return -1;
  }
  decoda_entrada_rel(r,cpf,cpf3,op,bem);
  return 1;
}
int remover_cliente_fila(priority *pr){
  if(pr==NULL){
    printf("Erro 1 em remover_cliente\n");
    return -1;
  }
  remover_frente_pri(pr);
  return 1;
}
int enviar_cliente_atendimento(priority *pr,pilha *p){
  //removo da fila, insiro na pilha
  if(pr==NULL){
    printf("Erro 1 em enviar_cliente_atendimento\n");
    return -1;
  }
  //para enviar para guichê,
  //tenho que empilhar
  int cpf=0,cpf3=0,prioridade=0;
  char o=' ',b[26]="";
  //enviar_atend(pr,&cpf,&cpf3,&prioridade,&o,b);
  mostrar_frente_pri(pr,&cpf,&cpf3,&prioridade,&o,b);
  //printf("CPF: %d. Bem: %s\n",cpf,b);
  //aqui tenho todas as informações para mandar para a pilha nas vars
  if(cpf==0) {
		printf("Erro 2 em enviar_cliente_atendimento\n");
		return -1;//cpf 0 é ausência de cliente para enviar;
	}
	//printf("inserindo: %d,%d,%c,%s\n",cpf,cpf3,o,b);
  inserir_pilha_elaborar_no(p,cpf,cpf3,o,b);
  remover_frente_pri(pr);
  return 1;
}
int gerar_imprimir_relatorio_parcial(pilha* p,rel *r,int k){
  if(p==NULL){
    printf("Erro 1 em gerar_imprimir_relatorio_parcial\n");
    return -1;
  }
  int cpf=0,cpf3=0;
  char o=' ',b[26]="";

  printf("-:| RELATÓRIO PARCIAL |:-\n");
  printf("%d\n",k);
  //há k pilhas de tamanho tam
  pilha *aux;

  for (int i = 0; i < k; i++) {
    aux=endereco_pilha(p,i);
    printf("Guiche %d: %d\n",i+1,tamanho_pilha(aux));
  //  imprime_topo_pilha(aux);

	//  aux=inverter_pilha(aux);
  //  trocar_i_de_pilha(p,i,aux);
  //  imprime_topo_pilha(aux);
    //aux é ponteiro para a pilha invertida;
    while(!pilha_vazia(aux)){
		//	printf("Entrou no while\n");
      mostrar_topo_pilha(aux,&cpf,&cpf3,&o,b);
  //      printf("Rel parc%s\n",b);

      if(cpf!=0){
        //cpf 0 ignora

      gerar_relatorio_final(r,cpf,cpf3,o,b);

    //  imprimir:
      printf("[%d,%d,%c,%s]\n",cpf,cpf3,o,b);
      }
      remover_pilha(aux);
    }

  }
  return 1;
}
int imprimir_relatorio_final(rel *r){
  if(r==NULL){
    printf("Erro 1 em imprimir_relatorio_final\n");
    return -1;
  }
  // printf(" Teste: \n");
  // imprimir_todos_cpfs(r);
  // printf(" Fim do Teste \n");
  printf("-:| RELATÓRIO FINAL |:-\n");  //falta o k;
  int aux=tamanho_relatorio(r);
  printf("%d\n",aux);
  while(!relatorio_vazio(r)){
    imprimir_cpf_inicio(r);
    //imprimir_todos_cpfs(r);
    remover_noh_rel_inicio(r);
  }
/*
*/
  return 1;
}
int main(){
  int l,m,n;
  int k;
  scanf("%d%d%d",&l,&m,&n);
  //l: quantidade de níveis de prioridade
  //m: quantidade de guiches
  //n: quantidade de clientes


  priority* pr= criar_x_prioridades(l);
  ler_linhas_entrada(pr,n);

  k=n/m;
  if(n%m!=0){
    k++;
  }
  pilha* pi=criar_pilhas(k,m);//tenho q criar m pilhas de tamanho n/m
  pilha* aux;
  //  enquanto a fila de prioridade  não estiver vazia,
  //  enviar_cliente_atendimento();
  while(!fila_pri_vazia(pr)){
    for (int i = 0; i < m; i++) {
        if(fila_pri_vazia(pr)) break;
        aux=endereco_pilha(pi,i);
        enviar_cliente_atendimento(pr,aux);
    }
  }
  rel *r=criar_rel_fin();

  gerar_imprimir_relatorio_parcial(pi,r,m);
  imprimir_relatorio_final(r);
  //destruir tudo
  free(pi);
  free(r);
  free(pr);
  pi=NULL;
  r=NULL;
  pr=NULL;

  return 0;
}
