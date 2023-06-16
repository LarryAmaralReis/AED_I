#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

LISTA *cria_lista() {
    LISTA *li = (LISTA *) malloc(sizeof(LISTA));
    if (li != NULL) *li = NULL;
    return li;
}

void libera_lista(LISTA *li) {
    if (li != NULL) {
        ELEMENTO *no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->proximo;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(LISTA *li) {
    if (li == NULL) return 0;
    int contador = 0;
    ELEMENTO *no = *li;
    while (no != NULL) {
        contador++;
        no = no->proximo;
    }
    return contador;
}

int lista_cheia(LISTA *li) {
    return 0;
}

int lista_vazia(LISTA *li) {
    if (li == NULL || *li == NULL) return 1;
    return 0;
}

int insere_lista_inicio(LISTA *li, int value) {
    if (li == NULL) return 0;
    ELEMENTO *no = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (no == NULL) return 0;
    no->dados = value;
    no->proximo = (*li);
    *li = no;
    return 1;
}

int insere_lista_final(LISTA *li, int value) {
    if (li == NULL) return 0;
    ELEMENTO *no = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (no == NULL) return 0;
    no->dados = value;
    no->proximo = NULL;
    if ((*li) == NULL) {
        *li = no;
    } else {
        ELEMENTO *aux = *li;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = no;
    }
    return 1;
}

int insere_lista_ordenada(LISTA *li, int value) {
    if (li == NULL) return 0;
    ELEMENTO *no = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (no == NULL) return 0;
    no->dados = value;
    if (lista_vazia(li) == 1) {
        no->proximo = (*li);
        *li = no;
        return 1;
    } else {
        ELEMENTO *anterior, *atual = *li;
        while (atual != NULL && atual->dados < value) {
            anterior = atual;
            atual = atual->proximo;
        }
        if (atual == *li) {
            no->proximo = (*li);
            *li = no;
        } else {
            no->proximo = anterior->proximo;
            anterior->proximo = no;
        }
        return 1;
    }
}

int remove_lista_inicio(LISTA *li) {
    if (li == NULL || (*li) == NULL) return 0;
    ELEMENTO *no = *li;
    *li = no->proximo;
    free(no);
    return 1;
}

int remove_lista_final(LISTA *li) {
    if (li == NULL || (*li) == NULL) return 0;
    ELEMENTO *anterior, *no = *li;
    while (no->proximo != NULL) {
        anterior = no;
        no = no->proximo;
    }
    if (no == (*li)) *li = no->proximo;
    else anterior->proximo = no->proximo;
    free(no);
    return 1;
}

int remove_lista(LISTA *li, int value) {
    if (li == NULL) return 0;
    ELEMENTO *anterior, *no = *li;
    while (no != NULL && no->dados != value) {
        anterior = no;
        no = no->proximo;
    }
    if (no == NULL) return 0;
    if (no == (*li)) *li = no->proximo;
    else anterior->proximo = no->proximo;
    free(no);
    return 1;
}

int consulta_lista_pos(LISTA *li, int pos, int *value) {
    if (li == NULL || pos <= 0) return 0;
    ELEMENTO *no = *li;
    int i = 1;
    while (no != NULL && i < pos) {
        no = no->proximo;
        i++;
    }
    if (no == NULL) return 0;
    else {
        *value = no->dados;
        return 1;
    }
}

int consulta_lista_valor(LISTA *li, int value, int *pos) {
    if (li == NULL) return 0;
    ELEMENTO *no = *li;
    int i = 1;
    while (no != NULL && no->dados != value) {
        no = no->proximo;
        i++;
    }
    if (no == NULL) return 0;
    else {
        *pos = i;
        return 1;
    }
}

void imprime_lista(LISTA *li){
    if(li == NULL)
        return;
    ELEMENTO * no = *li;
    while(no != NULL){
        printf("%d\n", no->dados);
        no = no->proximo;
    }
}

int elemento_duplicado(LISTA *li, int value) {
    if (li == NULL || *li == NULL) return 0;

    ELEMENTO *no = *li;
    int contador = 0;

    while (no != NULL) {
        if (no->dados == value) {
            contador++;
            if (contador > 1) {
                return 1;  // Element is duplicated
            }
        }
        no = no->proximo;
    }

    return 0;  // Element is not duplicated
}

int busca_sequencial(LISTA *li, int value) {
    if (li == NULL || *li == NULL) return -1;  // Element not found

    ELEMENTO *no = *li;
    int pos = 1;

    while (no != NULL) {
        if (no->dados == value) {
            return pos;  // Element found at position pos
        }
        no = no->proximo;
        pos++;
    }

    return -1;  // Element not found
}
