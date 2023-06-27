#include <stdio.h>
#include <stdlib.h>
#include "aviao.h"
#include "aviao.c"

int main() {
    PILHA *hangar = cria_Pilha(100);
    int opcao;
    AVIAO aviao;
    int posicao;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Listar o numero de avioes aguardando no hangar\n");
        printf("2. Tirar um aviao do hangar\n");
        printf("3. Adicionar um aviao no hangar\n");
        printf("4. Listar todos os avioes que estao no hangar\n");
        printf("5. Listar as caracteristicas do primeiro aviao do hangar\n");
        printf("6. Tirar um aviao do hangar pela posicao\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Numero de avioes no hangar: %d\n", tamanho_Pilha(hangar));
                break;
            case 2:
                if (remove_Pilha(hangar))
                    printf("Aviao removido do hangar\n");
                else
                    printf("Nao foi possivel remover o aviao do hangar\n");
                break;
            case 3:
                printf("Informe o numero do aviao: ");
                scanf("%d", &aviao.identificador);
                printf("Informe o nome do aviao: ");
                scanf("%s", aviao.nome);
                if (insere_Pilha(hangar, aviao))
                    printf("Aviao adicionado no hangar\n");
                else
                    printf("Nao foi possivel adicionar o aviao no hangar\n");
                break;
            case 4:
                listaAvioes(hangar);
                break;
            case 5:
                listaCaracteristicasPrimeiroAviao(hangar);
                break;
            case 6:
                printf("Informe a posicao do aviao a ser removido: ");
                scanf("%d", &posicao);
                removeAviaoPorPosicao(hangar, posicao);
                break;
            case 0:
                printf("Saindo do programa\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opcao != 0);

    libera_Pilha(hangar);

    return 0;
}
