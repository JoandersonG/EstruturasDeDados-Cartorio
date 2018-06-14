#include <stdio.h>
#include <stdlib.h>
#include "relatorioFinal.h"

int main(){

  char a[]="Bota Velha";
  char b[]="Bota Nova";
//  rel * r=criar_rel_fin();
  rel* r=criar_rel_fin();
  decoda_entrada_rel(r,123,321,'A',a);

  printf("Existe cpf 123: %d\n",existe_cpf_rel(r,123));
  decoda_entrada_rel(r,456,654,'T',b);
  printf("Existe cpf 654: %d\n",existe_cpf_rel(r,654));
  no* n= mostrar_cpf_ordenado(r);
  printf("CPF ordenado 1: %d\n",n->cpf);
  printf("Bem ordenado 1: %s\n",n->lb->ini->bem);
  printf("Bem ordenado 1: %s\n",n->lb->fim->bem);
  remover_noh_rel_inicio(r);
  printf("Existe cpf 123: %d\n",existe_cpf_rel(r,123));
  printf("Existe cpf 654: %d\n",existe_cpf_rel(r,654));
  destruir_relatorio(r);
  /*
  */
}
