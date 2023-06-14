#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"


void inicializarLista(LISTA *lista) {
    lista->inicio = NULL;
}

void inserirNaLista(LISTA *lista, int coeficiente, int expoente) {
    ELEMENTO *novoElemento = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    novoElemento->coeficiente = coeficiente;
    novoElemento->expoente = expoente;
    novoElemento->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novoElemento;
    } else {
        // Encontra
        ELEMENTO *atual = lista->inicio;
        ELEMENTO *anterior = NULL;

        while (atual != NULL && atual->expoente > expoente) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == NULL) {
            // Início
            novoElemento->proximo = lista->inicio;
            lista->inicio = novoElemento;
        } else {
            // Meio ou Final
            anterior->proximo = novoElemento;
            novoElemento->proximo = atual;
        }
    }
}

void exibirLista(LISTA *lista) {
    ELEMENTO *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->coeficiente < 0) {
            printf(" - ");
        } else {
            printf(" + ");
        }

        printf("%dx^%d", abs(atual->coeficiente), atual->expoente);
        atual = atual->proximo;
    }

    printf("\n");
}

LISTA somaPolinomio(LISTA *P1, LISTA *P2) {
    LISTA S;
    inicializarLista(&S);

    ELEMENTO *atualP1 = P1->inicio;
    ELEMENTO *atualP2 = P2->inicio;

    while (atualP1 != NULL || atualP2 != NULL) {
        if (atualP2 == NULL || (atualP1 != NULL && atualP1->expoente > atualP2->expoente)) {
            inserirNaLista(&S, atualP1->coeficiente, atualP1->expoente);
            atualP1 = atualP1->proximo;
        } else if (atualP1 == NULL || (atualP2 != NULL && atualP2->expoente > atualP1->expoente)) {
            inserirNaLista(&S, atualP2->coeficiente, atualP2->expoente);
            atualP2 = atualP2->proximo;
        } else {
            int coeficiente = atualP1->coeficiente + atualP2->coeficiente;
            inserirNaLista(&S, coeficiente, atualP1->expoente);
            atualP1 = atualP1->proximo;
            atualP2 = atualP2->proximo;
        }
    }
    return S;
}

