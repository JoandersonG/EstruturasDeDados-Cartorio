#include <stdio.h>
#include "pilha.h"
#include "relatorioFinal.h"

int main(){
//  struct node um,dois,tres,teste;
  struct pilha *p;
  p=criar_pilha(3);
  char bem[]="Bota velha";
//  inserir_pilha(p,elaborar_no(123,321,'T',bem));
  inserir_pilha_elaborar_no(p,123,321,'T',bem);
  inserir_pilha_elaborar_no(p,456,654,'A',bem);
  inserir_pilha_elaborar_no(p,789,987,'T',bem);

  imprime_topo_pilha(p);
  remover_pilha(p);

  imprime_topo_pilha(p);
  remover_pilha(p);

  imprime_topo_pilha(p);
  remover_pilha(p);

/*
  um.cpfc=123;
  um.cpft=321;

  dois.cpfc=456;
  dois.cpft=654;

  tres.cpfc=789;
  tres.cpft=987;


  inserir_pilha(p,um);
  inserir_pilha(p,dois);
  inserir_pilha(p,tres);

  teste=topo_pilha(p);
  printf("%d\n",teste.cpfc);
  remover_pilha(p);

  teste=topo_pilha(p);
  printf("%d\n",teste.cpfc);
  remover_pilha(p);

  teste=topo_pilha(p);
  printf("%d\n",teste.cpfc);
  remover_pilha(p);

  destruir_pilha(p);
*/
}
