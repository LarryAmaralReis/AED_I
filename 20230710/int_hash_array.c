#include <stdio.h>
#include <stdlib.h>
#include "int_hash_array.h"

void inicializaHash (TB_HASH tab) {
    int i;
    for (i = 0; i < M; i++) {
        tab[i] = NULL;
    }
}

int m_Hash (int chave) {
    return (chave % M);
}

int inserir (TB_HASH tab, int chave) {
    int h = m_Hash(chave);
    if (tab[h] != NULL) return 0; // Colisão: posição já ocupada
    ELEMENTO *novoElemento = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (novoElemento == NULL) return 0; // Falha na alocação de memória
    novoElemento->key = chave;
    tab[h] = novoElemento;
    return 1;
}

void mostrarHash(TB_HASH tab) {
    printf("\n--------------------------------------------------\n");
    for (int i = 0; i < M; i++) {
        if (tab[i] != NULL) printf("Posição %d: %d\n", i, tab[i]->key);
        else printf("Posição %d: vazia\n", i);
    }
    printf("--------------------------------------------------\n");
}

int inserirLinear (TB_HASH tab, int chave) {
    int h = m_Hash(chave);
    int originalH = h;
    int i = 1;
    while (tab[h] != NULL) {
        if (tab[h]->key == chave) return 0; // Elemento com a mesma chave já existe
        h = (chave + i) % M; // Sondagem linear para a próxima posição
        i++;
        if (h == originalH) return 0; // A tabela de hash está cheia
    }
    ELEMENTO *novoElemento = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (novoElemento == NULL) return 0; // Falha na alocação de memória
    novoElemento->key = chave;
    tab[h] = novoElemento;
    return 1;
}

int inserirQuadraticaB (TB_HASH tab, int chave) {
    int h = m_Hash(chave);
    int originalH = h;
    int i = 1;
    while (tab[h] != NULL) {
        if (tab[h]->key == chave) return 0; // Elemento com a mesma chave já existe
        h = (chave + (i*i)) % M; // Sondagem quadrática
        i++;
        if (h == originalH) return 0; // A tabela de hash está cheia
    }
    ELEMENTO *novoElemento = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (novoElemento == NULL) return 0; // Falha na alocação de memória
    novoElemento->key = chave;
    tab[h] = novoElemento;
    return 1;
}

int inserirQuadraticaC (TB_HASH tab, int chave) {
    int h = m_Hash(chave);
    int originalH = h;
    int i = 1;
    while (tab[h] != NULL) {
        if (tab[h]->key == chave) return 0; // Elemento com a mesma chave já existe
        h = (chave + (2*i) + (i*i)) % M; // Sondagem quadrática
        i++;
        if (h == originalH) return 0; // A tabela de hash está cheia
    }
    ELEMENTO *novoElemento = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (novoElemento == NULL) return 0; // Falha na alocação de memória
    novoElemento->key = chave;
    tab[h] = novoElemento;
    return 1;
}

int inserirDuplo (TB_HASH tab, int chave) {
    int h = m_Hash(chave);
    int originalH = h;
    while (tab[h] != NULL) {
        if (tab[h]->key == chave) return 0; // Elemento com a mesma chave já existe
        h = 7 - (chave % 7);
        if (h == originalH) return 0; // A tabela de hash está cheia
    }
    ELEMENTO *novoElemento = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (novoElemento == NULL) return 0; // Falha na alocação de memória
    novoElemento->key = chave;
    tab[h] = novoElemento;
    return 1;
}