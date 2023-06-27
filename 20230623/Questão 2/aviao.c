#include <stdio.h>
#include <stdlib.h>
#include "aviao.h"

PILHA *cria_Pilha(int capacidade) {
    PILHA *pilha = (PILHA*)malloc(sizeof(PILHA));
    if (pilha != NULL) {
        pilha->dados = (AVIAO*)malloc(capacidade * sizeof(AVIAO));
        if (pilha->dados == NULL) {
            free(pilha);
            return NULL;
        }
        pilha->tamanho = 0;
        pilha->capacidade = capacidade;
    }
    return pilha;
}

void libera_Pilha(PILHA *pilha) {
    if (pilha != NULL) {
        free(pilha->dados);
        free(pilha);
    }
}

int tamanho_Pilha(PILHA *pilha) {
    if (pilha == NULL)
        return -1;
    return pilha->tamanho;
}

int Pilha_vazia(PILHA *pilha) {
    if (pilha == NULL)
        return -1;
    return (pilha->tamanho == 0);
}

int Pilha_cheia(PILHA *pilha) {
    if (pilha == NULL)
        return -1;
    return (pilha->tamanho == pilha->capacidade);
}

int insere_Pilha(PILHA *pilha, AVIAO aviao) {
    if (pilha == NULL || Pilha_cheia(pilha))
        return 0;
    pilha->dados[pilha->tamanho] = aviao;
    pilha->tamanho++;
    return 1;
}

int remove_Pilha(PILHA *pilha) {
    if (pilha == NULL || Pilha_vazia(pilha))
        return 0;
    pilha->tamanho--;
    return 1;
}

void listaAvioes(PILHA *pilha) {
    if (pilha == NULL || Pilha_vazia(pilha))
        return;
    int i;
    for (i = pilha->tamanho - 1; i >= 0; i--) {
        printf("Aviao %d - Nome: %s\n", pilha->dados[i].identificador, pilha->dados[i].nome);
    }
}

void listaCaracteristicasPrimeiroAviao(PILHA *pilha) {
    if (pilha == NULL || Pilha_vazia(pilha))
        return;
    printf("Aviao %d - Nome: %s\n", pilha->dados[pilha->tamanho - 1].identificador, pilha->dados[pilha->tamanho - 1].nome);
    // Imprimir outras características do primeiro avião
}

void removeAviaoPorPosicao(PILHA *pilha, int posicao) {
    if (pilha == NULL || Pilha_vazia(pilha) || posicao < 1 || posicao > pilha->tamanho)
        return;

    int i;
    for (i = posicao; i < pilha->tamanho; i++) {
        pilha->dados[i - 1] = pilha->dados[i];
    }
    pilha->tamanho--;
}
