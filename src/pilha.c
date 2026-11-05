#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

no* pilha_inicializar(void){
    return NULL;
}

const no* pilha_topo (const no *topo){
    return topo;
}

no* push(no *topo, int valor){
    no *novo;

    novo = malloc(sizeof(no));
    if (novo == NULL)
        return topo;
    novo->info = valor;
    novo->prox = topo;
    return novo;
}

no* pop(no *topo){
    if (topo == NULL)
        return NULL;

    no *aux;

    aux = topo;
    topo = topo->prox;
    free (aux);
    return topo;
}

void exibir_pilha(const no *topo){
    const no *aux;

    aux = topo;
    while(aux != NULL){
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
    printf("NULL\n");
}

no* liberar_pilha(no *topo){
    no *aux, *aux2;

    aux = topo;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    return NULL;
}
