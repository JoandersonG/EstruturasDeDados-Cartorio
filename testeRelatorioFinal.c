#include <stdio.h>
#include <string.h>
//#include "fila.h"
//#include "priority.h"
//#include "pilha.h"
#include "relatorioFinal.h"
int main(){
  char a[]="Camisa da Moda";
  char b[]="Converse All Star";
  rel* r=criar_rel_fin();
  printf("Esperado 1: %d\n",relatorio_vazio(r));
  decoda_entrada_rel(r,456,654,'T',b);
  decoda_entrada_rel(r,123,321,'A',a);

  printf("Esperado 4: %d\n",tamanho_relatorio(r));
  imprimir_cpf_inicio(r);
  remover_noh_rel_inicio(r);
  imprimir_cpf_inicio(r);
  printf("Esperado 3: %d\n",tamanho_relatorio(r));
  remover_noh_rel_inicio(r);
  imprimir_cpf_inicio(r);
  destruir_relatorio(r);
/*
*/
}
