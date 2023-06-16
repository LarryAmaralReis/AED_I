#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
// Criar a lista OK
// Inserir um elemento da lista sem importar a ordem. OK.
// Inserir um elemento da lista de forma ordenada. OK.
// Retornar a quantidade de elementos na lista. OK.
// Buscar sequencialmente um elemento na lista. OK.
// Busca binária de elemento na lista (Lista linear sequência). OK.
// Excluir um elemento da lista (pela posição ou pelo valor) OK.
// Imprimir os elementos da lista. OK.

LISTA *cria_lista() {
    LISTA *li;
    li = (LISTA *) malloc(sizeof(LISTA));
    if (li != NULL) li->qtd = 0;
    return li;
}

void libera_lista(LISTA *li) {
    free(li);
}

int tamanho_lista(LISTA *li) {
    if (li == NULL) return -1;
    else return li->qtd;
}

int lista_cheia(LISTA *li) {
    if (li == NULL) return -1;
    else if (li->qtd == MAX) return 1;
    else return 0;
}

int lista_vazia(LISTA *li) {
    if (li == NULL) return -1;
    else if (li->qtd == 0) return 1;
    else return 0;
}

int insere_lista_inicio(LISTA *li, int elemento) {
    if (li == NULL || lista_cheia(li) == 1) return 0;
    else if (lista_vazia(li) == 1) {
        li->dados[0] = elemento;
        li->qtd++;
        return 1;
    } else {
        int i;
        for (i = li->qtd - 1; i >= 0; i--) {
            li->dados[i + 1] = li->dados[i];
        }
        li->dados[0] = elemento;
        li->qtd++;
        return 1;
    }
}

int insere_lista_meio(LISTA *li, int elemento) {
    if (li == NULL || lista_cheia(li) == 1) return 0;
    if (lista_vazia(li) == 1) return insere_lista_inicio(li, elemento);
    int i;
    for (i = li->qtd - 1; i >= li->qtd / 2; i--) {
        li->dados[i + 1] = li->dados[i];
    }
    li->dados[li->qtd / 2] = elemento;
    li->qtd++;
    return 1;
}

int insere_lista_final(LISTA *li, int elemento) {
    if (li == NULL || lista_cheia(li) == 1) return 0;
    li->dados[li->qtd] = elemento;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(LISTA *li, int elemento) {
    if (li == NULL || lista_cheia(li) == 1) return 0;
    int i = 0, j;
    while (i < li->qtd && li->dados[i] < elemento) i++;
    for (j = li->qtd - 1; j >= i; j--) li->dados[j + 1] = li->dados[j];
    li->dados[i] = elemento;
    li->qtd++;
    return 1;
}

int remove_lista_inicio(LISTA *li) {
    if (li == NULL || lista_vazia(li) == 1) return 0;
    int i;
    for (i = 0; i < li->qtd - 1; i++) {
        li->dados[i] = li->dados[i + 1];
    }
    li->qtd--;
    return 1;
}

int remove_lista_meio(LISTA *li) {
    if (li == NULL || lista_vazia(li) == 1) return 0;
    int i;
    for (i = li->qtd / 2; i < li->qtd - 1; i++) {
        li->dados[i] = li->dados[i + 1];
    }
    li->qtd--;
    return 1;
}

int remove_lista_fim(LISTA *li) {
    if (li == NULL || lista_vazia(li) == 1) return 0;
    li->qtd--;
    return 1;
}

int remove_lista(LISTA *li, int elemento) {
    if (li == NULL || lista_vazia(li) == 1) return 0;
    if (li->dados[0] == elemento) remove_lista_inicio(li);
    if (li->dados[li->qtd - 1] == elemento) remove_lista_fim(li);
    int i = 1;
    while (i < li->qtd && li->dados[i] != elemento) i++;
    if (i == li->qtd) return 0;
    for (i; i < li->qtd - 1; i++) {
        li->dados[i] = li->dados[i + 1];
    }
    li->qtd--;
    return 1;
}

int remove_lista_pos(LISTA *li, int pos) {
    if (li == NULL || lista_vazia(li) == 1 || pos <= 0 || pos > li->qtd) return 0;
    int i;
    for (i = pos - 1; i < li->qtd - 1; i++) {
        li->dados[i] = li->dados[i + 1];
    }
    li->qtd--;
    return 1;
}

int consulta_lista_pos(LISTA *li, int pos, int *elemento) {
    if (li == NULL || pos <= 0 || pos > li->qtd) return 0;
    *elemento = li->dados[pos - 1];
    return 1;
}

int consulta_lista_elem(LISTA *li, int elem, int *posicao) {
    if (li == NULL || lista_vazia(li) == 1) return 0;
    int i = 0;
    while (i < li->qtd && li->dados[i] != elem) i++;
    if (i == li->qtd) return 0;
    *posicao = i + 1;
    return 1;
}

int busca_sequencial(LISTA *li, int elemento) {
    if (li == NULL || lista_vazia(li) == 1) return -1;
    int i;
    for (i = 0; i < li->qtd; i++) {
        if (li->dados[i] == elemento)
            return i + 1; // Retorna a posição do elemento encontrado
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

int busca_binaria(LISTA *li, int elemento) {
    if (li == NULL || lista_vazia(li) == 1) return -1;
    int inicio = 0;
    int fim = li->qtd - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (li->dados[meio] == elemento)
            return meio + 1; // Retorna a posição do elemento encontrado
        else if (li->dados[meio] < elemento)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

void imprimir_lista(LISTA *li) {
    if (li == NULL || lista_vazia(li) == 1) return;
    int i;
    printf("\n[\t");
    for (i = 0; i < li->qtd; i++) {
        printf("%d\t", li->dados[i]);
    }
    printf("]\n");
}
int quantidade_repetidos(LISTA *li, int elemento) {
    if (li == NULL || lista_vazia(li) == 1) return 0;

    int contador = 0;
    for (int i = 0; i < li->qtd; i++) {
        if (li->dados[i] == elemento) {
            contador++;
        }
    }
    return contador;
}

