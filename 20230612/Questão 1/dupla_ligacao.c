#include <stdio.h>
#include "dupla_ligacao.h"
#include <stdlib.h>

void inicializarLista(LISTA* lista) {
    lista->inicio = NULL;
}

void inserirNaLista(LISTA* lista, int valor) {
    ELEMENTO* novoElemento = (ELEMENTO*)malloc(sizeof(ELEMENTO));
    novoElemento->valor = valor;
    novoElemento->anterior = NULL;
    novoElemento->proximo = lista->inicio;
    if (lista->inicio != NULL) {
        lista->inicio->anterior = novoElemento;
    }
    lista->inicio = novoElemento;
}

void removerDaLista(LISTA* lista, ELEMENTO* elemento) {
    if (elemento->anterior != NULL) {
        elemento->anterior->proximo = elemento->proximo;
    } else {
        lista->inicio = elemento->proximo;
    }
    if (elemento->proximo != NULL) {
        elemento->proximo->anterior = elemento->anterior;
    }
}

void exibirLista(LISTA* lista) {
    ELEMENTO* atual = lista->inicio;
    while (atual != NULL) {
        printf("\t%d", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

LISTA criarListaOrdenada(LISTA* L) {
    LISTA K;
    inicializarLista(&K);
    while (L->inicio != NULL) {
        ELEMENTO* atual = L->inicio;
        ELEMENTO* elementoMaximo = atual;
        while (atual != NULL) {
            if (atual->valor > elementoMaximo->valor) {
                elementoMaximo = atual;
            }
            atual = atual->proximo;
        }
        removerDaLista(L, elementoMaximo);

        elementoMaximo->anterior = NULL;
        elementoMaximo->proximo = K.inicio;

        if (K.inicio != NULL) {
            K.inicio->anterior = elementoMaximo;
        }

        K.inicio = elementoMaximo;
    }

    return K;
}