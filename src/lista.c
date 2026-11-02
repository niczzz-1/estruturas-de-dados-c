#include <stdio.h>
#include <stdlib.h>
#include "lista.h" 

no* inserir_elemento_inicio(no *inicio, int valor){
    no *novo;

    novo = malloc(sizeof(no));
    if (novo == NULL)
        return inicio;
    novo->info = valor;
    novo->prox = inicio;
    return novo;
}

no* inserir_elemento_fim(no *inicio, int valor){
    no *novo, *aux;

    novo = malloc(sizeof(no));
    if (novo == NULL)
        return inicio;
    novo->info = valor;
    novo->prox = NULL;

    if (inicio == NULL)
        return novo;

    aux = inicio;
    while (aux->prox != NULL)
        aux = aux->prox;
    
    aux->prox = novo;
    return inicio;
}

const no* buscar(const no *inicio, int valor){
    const no *aux; 
    
    aux = inicio;
    while(aux != NULL && aux->info != valor)
        aux = aux->prox;

    return aux;
}

no* remover_inicio(no *inicio){
    if (inicio == NULL)
        return NULL;
    
    no *aux;
    
    aux = inicio->prox;
    free(inicio);
    return aux;
}

no* remover_fim(no *inicio){
    if (inicio == NULL)
        return NULL;

    if (inicio->prox == NULL){
        free(inicio);
        return NULL;
    }
    
    no *aux;

    aux = inicio;
    while(aux->prox->prox != NULL)
        aux = aux->prox;
    free(aux->prox);
    aux->prox = NULL;
    return inicio;
}

void exibir_lista(const no *inicio){
    const no *aux;

    aux = inicio;
    while(aux != NULL){
        printf("%d -> ", aux->info);
        aux = aux->prox;
    }
    printf("NULL\n");
}

no* liberar_lista(no *inicio){
    no *aux, *aux2;

    aux = inicio;
    while(aux != NULL){
        aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    return NULL;
}