#ifndef FILA_H
#define FILA_H
#include "lista.h"

typedef struct{
    no *inicio;
    no *fim;
}fila;

//Declaração das funções contidas na fila;
fila* fila_inicializar(void);
const no* fila_frente(const fila *f);
void enfileirar(fila *f, int valor);
void desenfileirar(fila *f);
void exibir_fila(const fila *f);
fila* liberar_fila(fila *f);

#endif