#include <stdio.h>
#include <stdlib.h>
#include "int_hash_ligado.h"

void inicializahash(TB_HASH tab){
    int i;
    for (i = 0; i < M; i++) {
        tab[i] = NULL;
    }
}

int m_hash(int chave){
    return (((2 * chave) + 5) % M);
}

int inserir(TB_HASH tab, int chave){
    int h = m_hash(chave);
    ELEMENTO *anterior = NULL;
    ELEMENTO *e = tab[h];
    while (e != NULL) {
        if (e->key == chave)
            return 0;
        anterior = e;
        e = e->proximo;
    }
    if (e == NULL) {
        e = malloc(sizeof(ELEMENTO));
        e->key = chave;
        e->proximo = NULL;
        if (anterior == NULL)
            tab[h] = e;
        else
            anterior->proximo = e;
    }
    return 1;
}

ELEMENTO *busca(TB_HASH tab, int chave){
    int h = m_hash(chave);
    ELEMENTO *e = tab[h];
    while (e != NULL) {
        if (e->key == chave)
            return e;
        e = e->proximo;
    }
    return NULL;
}

void mostrarHash(TB_HASH tab){
    ELEMENTO *e;
    int i;
    printf("\n--------------------------------------------------");
    for (i = 0; i < M; i++) {
        if (tab[i] != NULL) {
            e = tab[i];
            printf("\n Posição: %d ->", i);
            while (e != NULL) {
                printf(" %d ->", e->key);
                e = e->proximo;
            }
            printf(" NULL");
        } else
            printf("\n Posição: %d NULL", i);
    }
}

int excluir(TB_HASH tab, int chave) {
    int h = m_hash(chave);
    ELEMENTO *anterior = NULL;
    ELEMENTO *e = tab[h];
    while (e != NULL) {
        if (e->key == chave) {
            if (anterior == NULL)
                tab[h] = e->proximo;
            else
                anterior->proximo = e->proximo;
            free(e);
            return 1;
        }
        anterior = e;
        e = e->proximo;
    }
    return 0;
}

int excluirPosicao(TB_HASH tab, int pos) {
    ELEMENTO *anterior = NULL;
    ELEMENTO *e = tab[pos];
    if (pos < 0 || pos >= M)
        return 0;
    if (e == NULL)
        return 0;
    if (anterior == NULL)
        tab[pos] = e->proximo;
    else
        anterior->proximo = e->proximo;
    free(e);
    return 1;
}

int encontrarMaior(TB_HASH tab) {
    int maior = -1;  // Inicializa com um valor inválido
    for (int i = 0; i < M; i++) {
        ELEMENTO *e = tab[i];
        while (e != NULL) {
            if (e->key > maior) {
                maior = e->key;
            }
            e = e->proximo;
        }
    }
    return maior;
}

int encontrarMenor(TB_HASH tab) {
    int menor = -1;  // Inicializa com um valor inválido
    int primeiro = 1;
    for (int i = 0; i < M; i++) {
        ELEMENTO *e = tab[i];
        while (e != NULL) {
            if (primeiro || e->key < menor) {
                menor = e->key;
                primeiro = 0;
            }
            e = e->proximo;
        }
    }
    return menor;
}

float calcularMedia(TB_HASH tab) {
    int soma = 0;
    int count = 0;
    for (int i = 0; i < M; i++) {
        ELEMENTO *e = tab[i];
        while (e != NULL) {
            soma += e->key;
            count++;
            e = e->proximo;
        }
    }
    if (count > 0) {
        return (float)soma / count;
    }
    return 0.0;
}

int removerPelaPosicao(TB_HASH tab, int pos) {
    if (pos < 0 || pos >= M) {
        return 0;  // Posição inválida
    }

    ELEMENTO *e = tab[pos];
    while (e != NULL) {
        ELEMENTO *proximo = e->proximo;
        free(e);
        e = proximo;
    }

    tab[pos] = NULL;  // A lista ficará vazia após a remoção
    return 1;  // Remoção bem-sucedida
}


int buscarPosicaoPeloNumero(TB_HASH tab, int numero) {
    for (int i = 0; i < M; i++) {
        ELEMENTO *e = tab[i];
        while (e != NULL) {
            if (e->key == numero) {
                return i;  // Retorna a posição se o número for encontrado
            }
            e = e->proximo;
        }
    }
    return -1;  // Retorna -1 se o número não for encontrado
}

int contarNumeros(TB_HASH tab) {
    int count = 0;
    for (int i = 0; i < M; i++) {
        ELEMENTO *e = tab[i];
        while (e != NULL) {
            count++;
            e = e->proximo;
        }
    }
    return count;
}
