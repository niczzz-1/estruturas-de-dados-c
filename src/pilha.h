#ifndef PILHA_H
#define PILHA_H
#include "lista.h"

//Declaração das funções contidas na pilha
const no* pilha_topo(const no *topo);
no* pilha_inicializar(void);
no* push(no *topo, int valor);
no* pop(no *topo);
void exibir_pilha(const no *topo);
no* liberar_pilha(no *topo);

#endif