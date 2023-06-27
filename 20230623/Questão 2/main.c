#include <stdio.h>
#include <stdlib.h>
#include "aviao.h"
#include "aviao.c"

int main() {
    PILHA *hangar = cria_Pilha(100);
    AVIAO aviao;
    int i;

    // Adicionar aviões no hangar
    for (i = 1; i <= 3; i++) {
        aviao.identificador = i;
        sprintf(aviao.nome, "Aviao %d", i);
        insere_Pilha(hangar, aviao);
    }

    // Listar o número de aviões aguardando no hangar
    printf("Numero de avioes no hangar: %d\n", tamanho_Pilha(hangar));

    // Listar todos os aviões no hangar
    printf("Avioes no hangar:\n");
    listaAvioes(hangar);

    // Listar as características do primeiro avião no hangar
    printf("Caracteristicas do primeiro aviao no hangar:\n");
    listaCaracteristicasPrimeiroAviao(hangar);

    // Tirar um avião do hangar
    if (remove_Pilha(hangar))
        printf("Aviao removido do hangar\n");
    else
        printf("Nao foi possivel remover o aviao do hangar\n");

    // Tirar um avião do hangar pela posição
    int posicao = 1;
    removeAviaoPorPosicao(hangar, posicao);

    // Listar todos os aviões no hangar após as remoções
    printf("Avioes no hangar:\n");
    listaAvioes(hangar);

    libera_Pilha(hangar);

    return 0;
}
