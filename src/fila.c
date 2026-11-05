#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

fila* fila_inicializar(void){
    fila *f;

    f = malloc(sizeof(fila));
    if (f == NULL)
        return NULL;
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

const no* fila_frente(const fila *f){
    if (f == NULL) return NULL;
    return f->inicio;
}

void enfileirar(fila *f, int valor){
   if (f == NULL) return;

   no *novo;

   novo = malloc(sizeof(no));
   if (novo == NULL)
    return;
   novo->info = valor;
   novo->prox = NULL;

   if (f->inicio == NULL)
    f->inicio = novo;

   else f->fim->prox = novo;

   f->fim = novo;
}

void desenfileirar(fila *f){
    if (f == NULL) return;

    if (f->inicio == NULL)
            return;

    no *aux;

    if (f->inicio == f->fim)
        f->fim = NULL;

    aux = f->inicio;
    f->inicio = aux->prox;
    free(aux);
}

void exibir_fila(const fila *f){
    if (f == NULL) return;

    const no *aux;

    aux = f->inicio;
    while(aux != NULL){
        printf("%d -> ", aux->info);
        aux = aux->prox;
    }
    printf("NULL\n");
}

fila* liberar_fila(fila *f){
    if (f == NULL) 
        return NULL;
    
    no *aux, *aux2;

    aux = f->inicio;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }

    free(f);
    return NULL;
}


