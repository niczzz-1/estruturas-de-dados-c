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
    printf("------------------------\n\n");
    testar_pilha();
    printf("------------------------\n\n");
    testar_fila();
    return 0;
}

void testar_fila(void){
    printf("Iniciando testes de fila...\n");
    fila *f;

    // ### INICIALIZANDO FILA ###

    printf("Inicializando fila...\n");
    f = fila_inicializar();
    // esperado: f -> inicio == NULL e f -> fim == NULL
    assert(f->inicio == NULL && f->fim == NULL);
    printf("[OK] fila inicializada\n");

    // ### TESTANDO FRENTE FILA 1 ###

    printf("Testando frente fila...\n");
    const no *frente1 = fila_frente(f);
    // esperado: frente1 = NULL;
    assert(frente1 == NULL);
    printf("[OK] primeiro teste de frente (NULL).\n");

    // ### ENFILEIRANDO VALORES ###

    printf("Enfileirando elementos...\n");
    printf("Esperado: 1 -> 2 -> 3 -> NULL | Obtido:\n");
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
    printf("[OK] elementos enfileirados.\n");

    // ### TESTANDO FRENTE FILA 2 ###

    printf("Testando frente fila...\n");
    const no *frente2 = fila_frente(f);
    // esperado: frente2 -> info = 1
    assert(frente2 != NULL && frente2->info == 1);
    printf("[OK] segundo teste de frente (1).\n");

    // ### DESENFILEIRANDO VALORES ###

    printf("Desenfileirando valores...\n");
    printf("Esperado: NULL | Obtido:\n");
    desenfileirar(f);
    // esperado: f -> inicio = 2 e f -> fim = 3
    assert(f->inicio->info == 2 && f->fim->info == 3);

    desenfileirar(f);
    // esperado: f -> inicio = 3 e f -> fim = 3
    assert(f->inicio->info == 3 && f->fim->info == 3);

    desenfileirar(f);
    // esperado: f -> inicio = NULL e f -> fim = NULL
    assert(f->inicio == NULL && f->fim == NULL);

    exibir_fila(f);
    // esperado: NULL
    printf("[OK] fila desenfileirada.\n");

    // ### TESTANDO PONTEIROS VAZIOS (INICIO/FIM) ###

    printf("Testando atualizacao de ponteiros vazios...\n");
    enfileirar(f, 4);
    // esperado: f -> inicio = 4 e f -> fim = 4
    assert(f->inicio->info == 4 && f->fim->info == 4);
    printf("[OK] ponteiros atualizam.\n");

    // ### LIBERANDO MEMÓRIA DA FILA ###

    printf("Liberando memoria da fila...\n");
    f = liberar_fila(f);
    // esperado: f -> NULL
    assert(f == NULL);
    printf("[OK] memoria da fila liberada.\n");
    
    // ### INICIALIZANDO FILA ###

    printf("Inicializando fila novamente...\n");
    f = fila_inicializar();
    // esperado: f -> inicio = NULL e f -> fim = NULL
    assert(f->inicio == NULL && f->fim == NULL);
    printf("[OK] fila inicializada.\n");

    // ### TESTANDO DESENFILEIRAR EM FILA VAZIA ###

    printf("Testando funcao desenfileirar em fila vazia...\n");
    desenfileirar(f);
    // esperado: f -> inicio = NULL e f -> fim = NULL (não há elemento a ser desenfileirado)
    assert(f->inicio == NULL && f->fim == NULL);    
    printf("[OK] funcao desenfileirar nao trava.\n");

    // ### ENFILEIRANDO FILA NOVAMENTE ###

    printf("Enfileirando fila novamente...\n");
    printf("Esperado: 3 -> 2 -> 1 -> NULL | Obtido:\n");
    enfileirar(f, 3);
    enfileirar(f, 2);
    enfileirar(f, 1);
    // esperado: f -> inicio = 3 e f -> fim = 1;
    assert(f->inicio->info == 3 && f->fim->info == 1);

    exibir_fila(f);
    // esperado: 3 -> 2 -> 1 -> NULL
    printf("[OK] fila enfileirada novamente.\n");

    // ### TESTANDO FRENTE FILA 3 ###

    printf("Testando frente fila...\n");
    const no *frente3 = fila_frente(f);
    // esperado: frente3 -> info = 3;
    assert(frente3 != NULL && frente3->info == 3);
    printf("[OK] terceiro teste frente (3).\n");

    // ### LIBERANDO MEMÓRIA DA FILA ###

    printf("Liberando memoria da fila...\n");
    f = liberar_fila(f);
    // esperado: f -> NULL
    assert(f == NULL);
    printf("[OK] memoria da fila liberada.\n");

    // ### TESTES COM PONTEIRO NULO ###

    printf("Realizando testes com ponteiro nulo...\n");
    assert(fila_frente(NULL) == NULL);
    assert(liberar_fila(NULL) == NULL);
    enfileirar(NULL, 5);
    desenfileirar(NULL);
    exibir_fila(NULL);
    // esperado: não travar em nenhum
    printf("[OK] testes com ponteiro nulo nao travam\n");

    printf("[SUCESSO] Testes de fila concluidos com exito.\n\n");
}

void testar_pilha(void){
    printf("Iniciando testes de pilha...\n");
    no *topo;

    // ### INICIALIZANDO PILHA ###

    printf("Inicializando pilha...\n");
    topo = pilha_inicializar();
    // esperado: topo -> NULL
    assert(topo == NULL);
    printf("[OK] pilha inicializada.\n");

    // ### TESTANDO TOPO PILHA 1 ###

    printf("Testando topo da pilha...\n");
    const no *t1 = pilha_topo(topo);
    // esperado: topo = NULL
    assert(t1 == NULL);

    exibir_pilha(topo);
    // esperado: NULL
    printf("[OK] teste pilha topo.\n");

    // ### EMPILHANDO ELEMENTOS ###

    printf("Empilhando elementos...\n");
    printf("Esperado: 3 -> 2 -> 1 -> NULL | Obtido:\n");
    topo = push(topo, 1);
    // esperado: topo -> 1 -> NULL
    assert(topo != NULL && topo->info == 1);

    topo = push(topo, 2); 
    // esperado: topo -> 2 -> 1 -> NULL
    assert(topo != NULL && topo->info == 2);

    topo = push(topo, 3);
    // esperado: topo -> 3 -> 2 -> 1 -> NULL
    assert(topo != NULL && topo->info == 3);

    exibir_pilha(topo);
    // esperado:  3 -> 2 -> 1 -> NULL
    printf("[OK] elementos empilhados.\n");

    // ### DESEMPILHANDO ELEMENTOS ###

    printf("Desempilhando elementos...\n");
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
    printf("[OK] elementos desempilhados.\n");

    // ### TESTANDO POP EM PILHA VAZIA ###

    printf("Testando pop em pilha vazia...\n");
    topo = pop(topo);
    // esperado = NULL
    assert(topo == NULL);
    printf("[OK] pop nao trava em pilha vazia.\n");

    // ### EMPILHANDO PILHA NOVAMENTE E TESTANDO TOPO PILHA 2 ###

    printf("Empilhando pilha novamente e testando topo...\n");
    topo = push(topo, 1);
    topo = push(topo, 2);
    topo = push(topo, 3);
    // esperado: topo -> 3 -> 2 -> 1 -> NULL

    const no *t2 = pilha_topo(topo);
    // esperado: topo = 3
    assert(t2 != NULL && t2->info == 3);

    exibir_pilha(topo);
    // esperado: 3 -> 2 -> 1 -> NULL
    printf("[OK] topo atualiza com nova pilha.\n");

    // ### LIBERANDO MEMÓRIA PILHA ###

    printf("Liberando memoria da pilha...\n");
    topo = liberar_pilha(topo);
    // esperado: topo -> NULL
    assert(topo == NULL);

    exibir_pilha(topo);
    // esperado: NULL
    printf("[OK] memoria da pilha liberada.\n");

    printf("[SUCESSO] Testes de pilha concluidos com exito.\n\n");
}

void testar_lista(void){
    printf("Iniciando testes de lista...\n");
    no *inicio;

    // ### INICIALIZANDO LISTA ###

    printf("Inicializando lista...\n");
    inicio = lista_inicializar();
    // esperado: inicio -> NULL
    assert(inicio == NULL);

    exibir_lista(inicio);
    // esperado: NULL (Não há nenhum elemento na lista)
    printf("[OK] lista inicializada.\n");

    // ### INSERINDO ELEMENTOS NA LISTA ###

    printf("Inserindo elementos na lista...\n");
    printf("Esperado: 3 -> 1 -> 2 -> 3 -> NULL | Obtido:\n");
    inicio = inserir_elemento_inicio_lista(inicio, 1);
    // esperado: inicio -> 1 -> NULL
    assert(inicio->info == 1);

    inicio = inserir_elemento_fim_lista(inicio, 2);
    // esperado: inicio -> 1 -> 2 -> NULL
    assert(inicio->prox->info == 2);

    inicio = inserir_elemento_fim_lista(inicio, 3);
    // esperado: inicio -> 1 -> 2 -> 3 -> NULL
    assert(inicio->prox->prox->info == 3);

    inicio = inserir_elemento_inicio_lista(inicio, 3);
    // esperado: inicio -> 3 -> 1 -> 2 -> 3 -> NULL
    assert(inicio->info == 3);

    exibir_lista(inicio);
    // esperado: 3 -> 1 -> 2 -> 3 -> NULL
    printf("[OK] elementos inseridos na lista.\n");

    // ### REALIZANDO BUSCAS NA LISTA ###

    printf("Realizando buscas na lista...\n");
    const no *achado1 = buscar_lista(inicio, 3);
    // esperado: achado, com info 3 (primeira aparição)
    assert(achado1 != NULL && achado1->info == 3);

    const no *achado2 = buscar_lista(inicio, 2);
    // esperado: achado, com info 2
    assert(achado2 != NULL && achado2->info == 2);
    printf("[OK] buscas de elementos existentes.\n");

    printf("Realizando busca de elemento inexistente...\n");
    // esperado: NULL
    assert(buscar_lista(inicio, 7) == NULL);
    printf("[OK] busca de elemento inexistente retorna NULL.\n");

    // ### REMOVENDO ELEMENTOS DA LISTA E A LIBERANDO ###

    printf("Removendo elementos da lista...\n");
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
    printf("[OK] elementos da lista removidos e memoria da lista liberada.\n");

    // ### TESTANDO FUNÇÕES COM LISTA VAZIA ###

    printf("Realizando funcoes com lista vazia...\n");
    inicio = remover_fim_lista(inicio);
    // esperado: NULL
    assert(inicio == NULL);

    inicio = remover_inicio_lista(inicio);
    // esperado: NULL
    assert(inicio == NULL);
    printf("[OK] funcoes nao travam com lista vazia.\n");

    // ### INSERIR E REMOVER ELEMENTO EM LISTA VAZIA ###

    printf("Inserindo e removendo elemento em lista vazia...\n");
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
    printf("[OK] lista vazia atualiza corretamente.\n");

    printf("[SUCESSO] Testes de lista concluidos com exito.\n\n");
}