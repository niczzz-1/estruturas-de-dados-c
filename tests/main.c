#include <stdio.h>
#include <assert.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"

void testar_lista(void);
void testar_pilha(void);
void testar_fila(void);

int main(void){
    testar_lista();
    testar_pilha();
    testar_fila();
    return 0;
}

void testar_fila(void){
    printf("Iniciando testes de fila...\n");
    fila *f;
    
    f = fila_inicializar();
    // esperado: f -> inicio == NULL e f -> fim == NULL
    assert(f->inicio == NULL && f->fim == NULL);

    const no *frente1 = fila_frente(f);
    // esperado: frente1 = NULL;
    assert(frente1 == NULL);

    enfileirar(f, 1);
    // esperado: f -> inicio = 1 e f -> fim = 1
    assert(f->inicio->info == 1 && f->fim->info == 1);

    enfileirar(f, 2);
    // esperado: f -> inicio = 1 e f -> fim = 2
    assert(f->inicio->info == 1 && f->fim->info == 2);

    enfileirar(f, 3);
    // esperado: f -> inicio = 1 e f -> fim = 3
    assert(f->inicio->info == 1 && f->fim->info == 3);

    exibir_fila(f);
    // esperado: 1 -> 2 -> 3 -> NULL

    const no *frente2 = fila_frente(f);
    // esperado: frente2 -> info = 1
    assert(frente2 != NULL && frente2->info == 1);

    desenfileirar(f);
    // esperado: f -> inicio = 2 e f -> fim = 3
    assert(f->inicio->info == 2 && f->fim->info == 3);

    desenfileirar(f);
    // esperado: f -> inicio = 3 e f -> fim = 3
    assert(f->inicio->info == 3 && f->fim->info == 3);

    desenfileirar(f);
    // esperado: f -> inicio = NULL e f -> fim = NULL
    assert(f->inicio == NULL && f->fim == NULL);

    enfileirar(f, 4);
    // esperado: f -> inicio = 4 e f -> fim = 4
    assert(f->inicio->info == 4 && f->fim->info == 4);

    f = liberar_fila(f);
    // esperado: f -> NULL
    assert(f == NULL);
    
    f = fila_inicializar();
    // esperado: f -> inicio = NULL e f -> fim = NULL
    assert(f->inicio == NULL && f->fim == NULL);

    desenfileirar(f);
    // esperado: f -> inicio = NULL e f -> fim = NULL (não há elemento a ser desenfileirado)

    enfileirar(f, 3);
    enfileirar(f, 2);
    enfileirar(f, 1);
    // esperado: f -> inicio = 3 e f -> fim = 1;
    assert(f->inicio->info == 3 && f->fim->info == 1);

    exibir_fila(f);
    // esperado: 3 -> 2 -> 1 -> NULL

    const no *frente3 = fila_frente(f);
    // esperado: frente3 -> info = 3;
    assert(frente3 != NULL && frente3->info == 3);

    f = liberar_fila(f);
    // esperado: f -> NULL
    assert(f == NULL);

    // testes com ponteiro nulo:

    assert(fila_frente(NULL) == NULL);
    assert(liberar_fila(NULL) == NULL);
    enfileirar(NULL, 5);
    desenfileirar(NULL);
    exibir_fila(NULL);
    // esperado: não travar em nenhum

    printf("Testes de fila concluidos com exito.\n\n");
}

void testar_pilha(void){
    printf("Iniciando testes de pilha...\n");
    no *topo;

    topo = pilha_inicializar();
    // esperado: topo -> NULL
    assert(topo == NULL);

    const no *t1 = pilha_topo(topo);
    // esperado: topo = NULL
    assert(t1 == NULL);

    exibir_pilha(topo);
    // esperado: NULL

    topo = push(topo, 1);
    // esperado: topo -> 1 -> NULL
    assert(topo != NULL && topo->info == 1);

    exibir_pilha(topo);
    // esperado: 1 -> NULL

    topo = push(topo, 2); 
    // esperado: topo -> 2 -> 1 -> NULL
    assert(topo != NULL && topo->info == 2);

    exibir_pilha(topo);
    // esperado: 2 -> 1 -> NULL

    topo = push(topo, 3);
    // esperado: topo -> 3 -> 2 -> 1 -> NULL
    assert(topo != NULL && topo->info == 3);

    exibir_pilha(topo);
    // esperado:  3 -> 2 -> 1 -> NULL

    topo = pop(topo); 
    // esperado: topo -> 2 -> 1 -> NULL
    assert(topo != NULL && topo->info == 2);

    exibir_pilha(topo);
    // esperado: 2 -> 1 -> NULL

    topo = pop(topo);
    // esperado: topo -> 1 -> NULL
    assert(topo != NULL && topo->info == 1);

    exibir_pilha(topo);
    // esperado: 1 -> NULL

    topo = pop(topo);
    // esperado: topo -> NULL
    assert(topo == NULL);

    exibir_pilha(topo);
    // esperado: NULL

    topo = pop(topo);
    // esperado = NULL
    assert(topo == NULL);

    topo = push(topo, 1);
    topo = push(topo, 2);
    topo = push(topo, 3);
    // esperado: topo -> 3 -> 2 -> 1 -> NULL

    const no *t2 = pilha_topo(topo);
    // esperado: topo = 3
    assert(t2 != NULL && t2->info == 3);

    exibir_pilha(topo);
    // esperado: 3 -> 2 -> 1 -> NULL

    topo = liberar_pilha(topo);
    // esperado: topo -> NULL
    assert(topo == NULL);

    exibir_pilha(topo);
    // esperado: NULL

    printf("Testes de pilha concluidos com exito...\n\n");
}

void testar_lista(void){
    printf("Iniciando testes de lista...\n");
    no *inicio;

    inicio = lista_inicializar();
    // esperado: inicio -> NULL
    assert(inicio == NULL);

    exibir_lista(inicio);
    // esperado: NULL (Não há nenhum elemento na lista)
    
    inicio = inserir_elemento_inicio_lista(inicio, 1);
    // esperado: inicio -> 1 -> NULL
    assert(inicio->info == 1);

    exibir_lista(inicio);
    // esperado: 1 -> NULL

    inicio = inserir_elemento_fim_lista(inicio, 2);
    // esperado: inicio -> 1 -> 2 -> NULL
    assert(inicio->prox->info == 2);

    exibir_lista(inicio);
    // esperado: 1 -> 2 -> NULL

    inicio = inserir_elemento_fim_lista(inicio, 3);
    // esperado: inicio -> 1 -> 2 -> 3 -> NULL
    assert(inicio->prox->prox->info == 3);

    exibir_lista(inicio);
    // esperado: 1 -> 2 -> 3 -> NULL

    inicio = inserir_elemento_inicio_lista(inicio, 3);
    // esperado: inicio -> 3 -> 1 -> 2 -> 3 -> NULL
    assert(inicio->info == 3);

    exibir_lista(inicio);
    // esperado: 3 -> 1 -> 2 -> 3 -> NULL

    const no *achado1 = buscar_lista(inicio, 3);
    // esperado: achado, com info 3 (primeira aparição)
    assert(achado1 != NULL && achado1->info == 3);

    const no *achado2 = buscar_lista(inicio, 2);
    // esperado: achado, com info 2
    assert(achado2 != NULL && achado2->info == 2);

    // esperado: NULL
    assert(buscar_lista(inicio, 7) == NULL);

    inicio = remover_fim_lista(inicio);
    // esperado: inicio -> 3 -> 1 -> 2 -> NULL
    assert(inicio->prox->prox->prox == NULL);

    exibir_lista(inicio);
    // esperado: 3 -> 1 -> 2 -> NULL
    
    inicio = remover_inicio_lista(inicio);
    // esperado: inicio -> 1 -> 2 -> NULL
    assert(buscar_lista(inicio, 3) == NULL);

    exibir_lista(inicio);
    // esperado: 1 -> 2 -> NULL

    inicio = liberar_lista(inicio);
    // esperado: inicio -> NULL (A estrutura já não ocupa mais espaço na memória);
    assert(inicio == NULL);
    
    exibir_lista(inicio);
    // esperado: NULL

    inicio = remover_fim_lista(inicio);
    // esperado: NULL
    assert(inicio == NULL);

    inicio = remover_inicio_lista(inicio);
    // esperado: NULL
    assert(inicio == NULL);

    inicio = inserir_elemento_inicio_lista(inicio, 8);
    // esperado: inicio -> 8 -> NULL
    assert(inicio->info == 8);

    exibir_lista(inicio);
    // esperado: 8 -> NULL

    inicio = remover_fim_lista(inicio);
    // esperado: inicio -> NULL;
    assert(inicio == NULL);

    exibir_lista(inicio);
    // esperado: NULL

    printf("Testes de lista concluidos com exito.\n\n");
}