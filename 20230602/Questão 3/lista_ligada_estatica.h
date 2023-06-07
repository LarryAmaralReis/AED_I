#ifndef LISTA_LIGADA_ESTATICA_H
#define LISTA_LIGADA_ESTATICA_H

#include <stdbool.h>

#define MAX 100

typedef struct {
    int valor;
    int proximo;
} Elemento;

typedef struct {
    Elemento lista[MAX];
    int inicio;
    int disponivel;
} LISTA_LIGADA_ESTATICA;

void iniciaLista(LISTA_LIGADA_ESTATICA *L);
bool listaCheia(LISTA_LIGADA_ESTATICA *L);
bool listaVazia(LISTA_LIGADA_ESTATICA *L);
void inserirElemento(LISTA_LIGADA_ESTATICA *L, int valor);
void imprimirLista(LISTA_LIGADA_ESTATICA *L);
LISTA_LIGADA_ESTATICA construirL1a(LISTA_LIGADA_ESTATICA *L);
LISTA_LIGADA_ESTATICA construirL1b(LISTA_LIGADA_ESTATICA *L);
void copiarLista(LISTA_LIGADA_ESTATICA *l1, LISTA_LIGADA_ESTATICA *l2);
void concatenarListas(LISTA_LIGADA_ESTATICA *l1, LISTA_LIGADA_ESTATICA *l2);
LISTA_LIGADA_ESTATICA intercalarListas(LISTA_LIGADA_ESTATICA *l1, LISTA_LIGADA_ESTATICA *l2);

#endif
