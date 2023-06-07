#include "lista_ligada_estatica.h"
#include <stdio.h>

void iniciaLista(LISTA_LIGADA_ESTATICA *L) {
    int i;
    for (i = 0; i < MAX - 1; i++) {
        L->lista[i].proximo = i + 1;
    }
    L->lista[MAX - 1].proximo = -1;
    L->inicio = -1;
    L->disponivel = 0; // Corrigido para 0
}


bool listaCheia(LISTA_LIGADA_ESTATICA *L) {
    return (L->disponivel == -1);
}

bool listaVazia(LISTA_LIGADA_ESTATICA *L) {
    return (L->inicio == -1);
}

void inserirElemento(LISTA_LIGADA_ESTATICA *L, int valor) {
    if (listaCheia(L)) {
        printf("Erro: a lista está cheia.\n");
        return;
    }

    int i = L->disponivel;
    L->disponivel = L->lista[i].proximo;
    L->lista[i].valor = valor;
    L->lista[i].proximo = -1; // Define o próximo do novo elemento como -1

    if (listaVazia(L) || valor < L->lista[L->inicio].valor) {
        L->lista[i].proximo = L->inicio;
        L->inicio = i;
    } else {
        int atual = L->inicio;
        int anterior = -1;
        while (atual != -1 && L->lista[atual].valor < valor) {
            anterior = atual;
            atual = L->lista[atual].proximo;
        }
        L->lista[i].proximo = atual;
        if (anterior != -1) {
            L->lista[anterior].proximo = i;
        } else {
            L->inicio = i; // O novo elemento deve ser inserido no início da lista
        }
    }
}


void imprimirLista(LISTA_LIGADA_ESTATICA *L) {
    int i = L->inicio;
    while (i != -1) {
        printf("%d ", L->lista[i].valor);
        i = L->lista[i].proximo;
    }
    printf("\n");
}

LISTA_LIGADA_ESTATICA construirL1a(LISTA_LIGADA_ESTATICA *L) {
    LISTA_LIGADA_ESTATICA L1;
    iniciaLista(&L1);

    int i = L->lista[L->inicio].proximo; // pula o primeiro elemento
    while (i != -1 && i != L->inicio) { // adiciona a verificação i != -1
        inserirElemento(&L1, L->lista[i].valor);
        i = L->lista[i].proximo;
    }
    inserirElemento(&L1, L->lista[L->inicio].valor); // insere o primeiro elemento no final

    return L1;
}

LISTA_LIGADA_ESTATICA construirL1b(LISTA_LIGADA_ESTATICA *L) {
    LISTA_LIGADA_ESTATICA L1;
    iniciaLista(&L1);

    int i = L->inicio;
    while (i != -1) {
        inserirElemento(&L1, L->lista[i].valor);
        i = L->lista[i].proximo;
    }

    int atual = L1.inicio;
    int anterior = -1;
    int proximo;
    while (atual != -1) {
        proximo = L1.lista[atual].proximo;
        L1.lista[atual].proximo = anterior;
        anterior = atual;
        atual = proximo;
    }
    L1.inicio = anterior;

    return L1;
}

