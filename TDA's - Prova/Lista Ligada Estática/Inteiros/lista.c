#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

LISTA *cria_lista() {
    LISTA *li = (LISTA *)malloc(sizeof(LISTA));
    if (li != NULL) {
        li->inicio = -1;
        li->disponivel = 0;
    }
    return li;
}

void libera_lista(LISTA *li) {
    free(li);
}

int tamanho_lista(LISTA *li) {
    if (li == NULL) return -1;
    int tamanho = 0;
    int prox = li->inicio;
    while (prox != -1) {
        tamanho++;
        prox = li->dados[prox].proximo;
    }
    return tamanho;
}

int lista_cheia(LISTA *li) {
    if (li == NULL) return -1;
    return li->disponivel == MAX;
}

int lista_vazia(LISTA *li) {
    if (li == NULL) return -1;
    return li->inicio == -1;
}

int insere_lista_inicio(LISTA *li, int elemento) {
    if (li == NULL || lista_cheia(li)) return 0;

    int posicao = li->disponivel;
    li->dados[posicao].elemento = elemento;
    li->disponivel++;

    li->dados[posicao].proximo = li->inicio;
    li->inicio = posicao;

    return 1;
}

int insere_lista_meio(LISTA *li, int elemento) {
    if (li == NULL || lista_cheia(li)) return 0;

    int posicao = li->disponivel;
    li->dados[posicao].elemento = elemento;
    li->disponivel++;

    int anterior = -1;
    int atual = li->inicio;

    while (atual != -1 && li->dados[atual].elemento < elemento) {
        anterior = atual;
        atual = li->dados[atual].proximo;
    }

    if (anterior == -1) {
        li->dados[posicao].proximo = li->inicio;
        li->inicio = posicao;
    } else {
        li->dados[posicao].proximo = li->dados[anterior].proximo;
        li->dados[anterior].proximo = posicao;
    }

    return 1;
}

int insere_lista_final(LISTA *li, int elemento) {
    if (li == NULL || lista_cheia(li)) return 0;

    int posicao = li->disponivel;
    li->dados[posicao].elemento = elemento;
    li->disponivel++;

    li->dados[posicao].proximo = -1;

    if (li->inicio == -1) {
        li->inicio = posicao;
    } else {
        int atual = li->inicio;
        while (li->dados[atual].proximo != -1) {
            atual = li->dados[atual].proximo;
        }
        li->dados[atual].proximo = posicao;
    }

    return 1;
}

int insere_lista_ordenada(LISTA *li, int elemento) {
    if (li == NULL || lista_cheia(li)) return 0;

    int posicao = li->disponivel;
    li->dados[posicao].elemento = elemento;
    li->disponivel++;

    int anterior = -1;
    int atual = li->inicio;

    while (atual != -1 && li->dados[atual].elemento < elemento) {
        anterior = atual;
        atual = li->dados[atual].proximo;
    }

    if (anterior == -1) {
        li->dados[posicao].proximo = li->inicio;
        li->inicio = posicao;
    } else {
        li->dados[posicao].proximo = li->dados[anterior].proximo;
        li->dados[anterior].proximo = posicao;
    }

    return 1;
}

int remove_lista_inicio(LISTA *li) {
    if (li == NULL || lista_vazia(li)) return 0;

    int posicao = li->inicio;
    li->inicio = li->dados[posicao].proximo;

    li->dados[posicao].proximo = li->disponivel;
    li->disponivel = posicao;

    return 1;
}

int remove_lista_meio(LISTA *li) {
    if (li == NULL || lista_vazia(li)) return 0;

    int anterior = -1;
    int atual = li->inicio;

    while (atual != -1 && li->dados[atual].proximo != -1) {
        anterior = atual;
        atual = li->dados[atual].proximo;
    }

    if (anterior == -1) {
        li->inicio = li->dados[atual].proximo;
    } else {
        li->dados[anterior].proximo = li->dados[atual].proximo;
    }

    li->dados[atual].proximo = li->disponivel;
    li->disponivel = atual;

    return 1;
}

int remove_lista_final(LISTA *li) {
    if (li == NULL || lista_vazia(li)) return 0;

    int anterior = -1;
    int atual = li->inicio;

    while (atual != -1 && li->dados[atual].proximo != -1) {
        anterior = atual;
        atual = li->dados[atual].proximo;
    }

    if (anterior == -1) {
        li->inicio = li->dados[atual].proximo;
    } else {
        li->dados[anterior].proximo = li->dados[atual].proximo;
    }

    li->dados[atual].proximo = li->disponivel;
    li->disponivel = atual;

    return 1;
}

int remove_lista(LISTA *li, int elemento) {
    if (li == NULL || lista_vazia(li)) return 0;

    int anterior = -1;
    int atual = li->inicio;

    while (atual != -1 && li->dados[atual].elemento != elemento) {
        anterior = atual;
        atual = li->dados[atual].proximo;
    }

    if (atual == -1) return 0;

    if (anterior == -1) {
        li->inicio = li->dados[atual].proximo;
    } else {
        li->dados[anterior].proximo = li->dados[atual].proximo;
    }

    li->dados[atual].proximo = li->disponivel;
    li->disponivel = atual;

    return 1;
}

int remove_lista_pos(LISTA *li, int pos) {
    if (li == NULL || lista_vazia(li) || pos < 1 || pos > tamanho_lista(li)) return 0;

    int contador = 1;
    int anterior = -1;
    int atual = li->inicio;

    while (atual != -1 && contador < pos) {
        anterior = atual;
        atual = li->dados[atual].proximo;
        contador++;
    }

    if (atual == -1) return 0;

    if (anterior == -1) {
        li->inicio = li->dados[atual].proximo;
    } else {
        li->dados[anterior].proximo = li->dados[atual].proximo;
    }

    li->dados[atual].proximo = li->disponivel;
    li->disponivel = atual;

    return 1;
}

int consulta_lista_pos(LISTA *li, int pos, int *elemento) {
    if (li == NULL || lista_vazia(li) || pos < 1 || pos > tamanho_lista(li)) return 0;

    int contador = 1;
    int atual = li->inicio;

    while (atual != -1 && contador < pos) {
        atual = li->dados[atual].proximo;
        contador++;
    }

    if (atual == -1) return 0;

    *elemento = li->dados[atual].elemento;

    return 1;
}

int consulta_lista_elem(LISTA *li, int elem, int *posicao) {
    if (li == NULL || lista_vazia(li)) return 0;

    int contador = 1;
    int atual = li->inicio;

    while (atual != -1 && li->dados[atual].elemento != elem) {
        atual = li->dados[atual].proximo;
        contador++;
    }

    if (atual == -1) return 0;

    *posicao = contador;

    return 1;
}

void imprimir_lista(LISTA *li) {
    if (li == NULL || lista_vazia(li)) {
        printf("Lista vazia.\n");
        return;
    }

    int atual = li->inicio;
    while (atual != -1) {
        printf("%d ", li->dados[atual].elemento);
        atual = li->dados[atual].proximo;
    }
    printf("\n");
}

int busca_sequencial(LISTA *li, int elemento) {
    if (li == NULL || lista_vazia(li)) return -1;

    int posicao = 1;
    int atual = li->inicio;

    while (atual != -1 && li->dados[atual].elemento != elemento) {
        atual = li->dados[atual].proximo;
        posicao++;
    }

    if (atual == -1) return -1;

    return posicao;
}

int remove_maior_elemento(LISTA *li, int *elemento) {
    if (li == NULL || lista_vazia(li)) return 0;

    int posicao_maior = -1;
    int atual = li->inicio;
    int maior = li->dados[atual].elemento;

    while (atual != -1) {
        if (li->dados[atual].elemento > maior) {
            maior = li->dados[atual].elemento;
            posicao_maior = atual;
        }
        atual = li->dados[atual].proximo;
    }

    if (posicao_maior == -1) return 0;

    if (posicao_maior == li->inicio) {
        li->inicio = li->dados[posicao_maior].proximo;
    } else {
        int anterior = -1;
        atual = li->inicio;
        while (atual != posicao_maior) {
            anterior = atual;
            atual = li->dados[atual].proximo;
        }
        li->dados[anterior].proximo = li->dados[atual].proximo;
    }

    *elemento = maior;
    li->dados[posicao_maior].proximo = li->disponivel;
    li->disponivel = posicao_maior;

    return 1;
}

