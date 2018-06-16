#include <stdio.h>
#include <string.h>
//#include "fila.h"
#include "priority.h"
//#include "relatorioFinal.h"
//#include "pilha.h"
int main(){
  int cpf=0,cpf3,pri;
  char o,bem[26];
  char a[]="Um diario";
  priority* p=criar_x_prioridades(3);

  elaborar_elem_adicionar_elem_pri(p,123,321,1,'A',a);
  mostrar_frente_pri(p,&cpf,&cpf3,&pri,&o,bem);
  printf("Esperado 123: %d\n",cpf);
  printf("Esperado 'Um diario': %s\n",bem);
  elaborar_elem_adicionar_elem_pri(p,456,654,2,'A',a);
  mostrar_frente_pri(p,&cpf,&cpf3,&pri,&o,bem);
  printf("Esperado 456: %d\n",cpf);
  remover_frente_pri(p);
  mostrar_frente_pri(p,&cpf,&cpf3,&pri,&o,bem);
  printf("Esperado 123: %d\n",cpf);
  remover_frente_pri(p);
  mostrar_frente_pri(p,&cpf,&cpf3,&pri,&o,bem);
  printf("Era esperado erro: %d\n",cpf);
  if(!fila_pri_vazia(p)){
    printf("Erro: não vazia\n");
  }
  destruir_fila_pri(p);
}
