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

int excluir(TB_HASH tab, int chave) {
    int h = m_Hash(chave);
    int originalH = h;
    int i = 1;
    while (tab[h] != NULL) {
        if (tab[h]->key == chave) {
            free(tab[h]);  // Deallocate the memory for the element
            tab[h] = NULL; // Set the pointer to NULL
            return 1;      // Element successfully deleted
        }
        h = (chave + i) % M; // Linear probing for the next position
        i++;
        if (h == originalH) break; // Element not found, exit the loop
    }
    return 0; // Element not found
}

int encontrarMaior(TB_HASH tab) {
    int maior = INT_MIN;
    for (int i = 0; i < M; i++) {
        if (tab[i] != NULL && tab[i]->key > maior) {
            maior = tab[i]->key;
        }
    }
    return maior;
}

int encontrarMenor(TB_HASH tab) {
    int menor = INT_MAX;
    for (int i = 0; i < M; i++) {
        if (tab[i] != NULL && tab[i]->key < menor) {
            menor = tab[i]->key;
        }
    }
    return menor;
}

float calcularMedia(TB_HASH tab) {
    int soma = 0;
    int count = 0;
    for (int i = 0; i < M; i++) {
        if (tab[i] != NULL) {
            soma += tab[i]->key;
            count++;
        }
    }
    if (count > 0) {
        return (float) soma / count;
    } else {
        return 0.0;
    }
}

int removerPorPosicao(TB_HASH tab, int posicao) {
    if (posicao < 0 || posicao >= M || tab[posicao] == NULL) return 0;
    free(tab[posicao]);
    tab[posicao] = NULL;
    return 1;
}

int buscarPosicaoPorNumero(TB_HASH tab, int numero) {
    int h = m_Hash(numero);
    int originalH = h;
    int i = 1;
    while (tab[h] != NULL) {
        if (tab[h]->key == numero) {
            return h; // Position found
        }
        h = (originalH + i) % M; // Linear probing to the next position
        i++;
        if (h == originalH) break; // Element not found, exit the loop
    }
    return -1; // Number not found
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