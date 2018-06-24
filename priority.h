#include "fila.h"
#ifndef priority_h
#define priority_h



typedef struct prioridade priority;

priority* criar_x_prioridades(int nfilas);
int elaborar_elem_adicionar_elem_pri(priority* p,int cpf, int cpf3, int prioridade, char op, char *bem);
int remover_frente_pri(priority* p);
int mostrar_frente_pri(priority *p,int *cpf,int *cpf3, int* prioridade,char *o,char* b);
//cliente enviar_guiche(priority* p);
priority* destruir_fila_pri(priority* p);
//int exibir_todos(priority* p);
int fila_pri_vazia(priority *p);

#endif
