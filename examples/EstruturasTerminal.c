#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"

void terminal_lista(void);

int main(void){
    terminal_lista();
    return 0;
}

void terminal_lista(void){
    no *inicio;
    int opcao;
    int valor;

    inicio = lista_inicializar();

    do{
        printf("      LISTA     ");
        printf("[1] Exibir Lista\n");
        printf("[2] Inserir no inicio\n");
        printf("[3] Inserir no fim\n");
        printf("[4] Remover no inicio\n");
        printf("[5] Remover no fim\n");
        printf("[6] Buscar\n");
        printf("[7] Encerrar teste\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1: exibir_lista(inicio);
                    break;
                

            case 2: printf("Digite um valor inteiro para ser adicionado: ");
                    scanf("%d", &valor);
                    inicio = inserir_elemento_inicio_lista(inicio, valor);
                    exibir_lista(inicio);
                    break;

            case 3: printf("Digite um valor inteiro para ser adicionado: ");
                    scanf("%d", &valor);
                    inicio = inserir_elemento_fim_lista(inicio, valor);
                    exibir_lista(inicio);
                    break;

            case 4: inicio = remover_inicio_lista(inicio);
                    exibir_lista(inicio);
                    break;

            case 5: inicio = remover_fim_lista(inicio);
                    exibir_lista(inicio);
                    break;

            case 6: inicio = liberar_lista(inicio);
                    printf("Teste de lista encerrado...\n");
                    break;
            
            default: printf("Essa opção não existe. Escolha uma opção válida.\n");
        }
        printf("\n");
        system("pause");
        system("cls");       
    }while (opcao != 6);
}