#ifndef LISTA_H
#define LISTA_H

typedef struct no{
    int info;
    struct no *prox;
}no;

//Declaração das funções contidas na lista encadeada
no* lista_inicializar(void);
no* inserir_elemento_inicio(no *inicio, int valor);
no* inserir_elemento_fim(no *inicio, int valor);
no* remover_inicio(no *inicio);
no* remover_fim(no *inicio);
const no* buscar(const no *inicio, int valor);
void exibir_lista(const no *inicio);
no* liberar_lista(no *inicio);

#endif