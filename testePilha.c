#include <stdio.h>
#include <string.h>
//#include "fila.h"
//#include "priority.h"
#include "pilha.h"
//#include "relatorioFinal.h"
int main(){
  char o,a[]="Bota Como Nova";
  int cpf, cpf3;
  pilha* p=criar_pilhas(3,2);
  pilha* aux=endereco_pilha(p,1);
  printf("Esperado 1: %d\n",pilha_vazia(aux));
  aux=endereco_pilha(p,0);
printf("Esperado 1: %d\n",pilha_vazia(aux));
  inserir_pilha_elaborar_no(aux,123,321,'T',a);
printf("Esperado 0: %d\n",pilha_vazia(p));
//  aux=endereco_pilha(p,1);
  inserir_pilha_elaborar_no(aux,456,654,'A',a);
  a[0]=' ';
  cpf=0;
  mostrar_topo_pilha(aux,&cpf,&cpf3,&o,a);
  printf("Esperado 456: %d\n",cpf);
  printf("Esperado 456: ");
  imprime_topo_pilha(aux);
  printf("\n");
  printf("Esperado 2: %d\n",tamanho_pilha(aux));
  aux=inverter_pilha(aux,2);
  remover_pilha(aux);
  printf("Esperado 123: ");
  imprime_topo_pilha(aux);
  printf("\n");
  aux=endereco_pilha(p,1);
  printf("Esperado 1: %d\n",pilha_vazia(aux));
  imprime_topo_pilha(aux);
  printf("\n");
//  destruir_pilhas(p,2);
  /*
  */
}
