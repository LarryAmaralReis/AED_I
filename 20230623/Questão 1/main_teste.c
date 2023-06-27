#include <stdio.h>
#include <stdlib.h>
#include "aviao.h"
#include "aviao.c"

int main() {
    FILA* filaDecolagem = cria_Fila();

    int opcao;
    do {
        printf("Escolha uma opção:\n");
        printf("1 - Listar o número de aviões aguardando na fila de decolagem\n");
        printf("2 - Autorizar a decolagem do primeiro avião da fila\n");
        printf("3 - Adicionar um avião à fila de espera\n");
        printf("4 - Listar todos os aviões na fila de espera\n");
        printf("5 - Listar as características do primeiro avião da fila\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int tamanho = tamanho_Fila(filaDecolagem);
                if (tamanho >= 0)
                    printf("Número de aviões aguardando na fila de decolagem: %d\n", tamanho);
                else
                    printf("Erro ao obter o tamanho da fila.\n");
                break;
            }
            case 2: {
                if (!Fila_vazia(filaDecolagem)) {
                    AVIAO av;
                    if (consulta_Fila(filaDecolagem, &av)) {
                        printf("Autorizando a decolagem do avião com identificador %d\n", av.identificador);
                        remove_Fila(filaDecolagem);
                    } else {
                        printf("Erro ao consultar o avião na fila de decolagem.\n");
                    }
                } else {
                    printf("Não há aviões na fila de decolagem.\n");
                }
                break;
            }
            case 3: {
                AVIAO av;
                printf("Informe o identificador do avião: ");
                scanf("%d", &av.identificador);
                printf("Informe o nome do avião: ");
                scanf("%s", av.nome);
                if (insere_Fila(filaDecolagem, av)) {
                    printf("Avião adicionado à fila de decolagem.\n");
                } else {
                    printf("Erro ao adicionar o avião à fila de decolagem.\n");
                }
                break;
            }
            case 4: {
                imprime_Fila(filaDecolagem);
                break;
            }
            case 5: {
                if (!Fila_vazia(filaDecolagem)) {
                    AVIAO av;
                    if (consulta_Fila(filaDecolagem, &av)) {
                        printf("Características do primeiro avião da fila de decolagem:\n");
                        printf("Identificador: %d\n", av.identificador);
                        printf("Nome: %s\n", av.nome);
                    } else {
                        printf("Erro ao consultar o avião na fila de decolagem.\n");
                    }
                } else {
                    printf("Não há aviões na fila de decolagem.\n");
                }
                break;
            }
            case 0: {
                printf("Encerrando o programa...\n");
                break;
            }
            default: {
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
            }
        }

        printf("\n");
    } while (opcao != 0);

    libera_Fila(filaDecolagem);

    return 0;
}
