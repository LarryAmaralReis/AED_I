#include <stdio.h>
#include "lista_ligada_estatica.h"

int main() {
    LISTA_LIGADA_ESTATICA L;
    iniciaLista(&L);

    inserirElemento(&L, 10);
    inserirElemento(&L, 5);
    inserirElemento(&L, 7);
    inserirElemento(&L, 3);
    inserirElemento(&L, 9);

    printf("Lista: ");
    imprimirLista(&L);

    LISTA_LIGADA_ESTATICA L1a = construirL1a(&L);
    printf("L1a: ");
    imprimirLista(&L1a);

    LISTA_LIGADA_ESTATICA L1b = construirL1b(&L);
    printf("L1b: ");
    imprimirLista(&L1b);

    // Testando copiarLista
    LISTA_LIGADA_ESTATICA L2;
    copiarLista(&L, &L2);
    printf("Lista copiada (L2): ");
    imprimirLista(&L2);

    // Testando concatenarListas
    LISTA_LIGADA_ESTATICA L3;
    iniciaLista(&L3);
    inserirElemento(&L3, 20);
    inserirElemento(&L3, 1);
    printf("Lista original (L): ");
    imprimirLista(&L);
    printf("Lista a ser concatenada (L3): ");
    imprimirLista(&L3);
    concatenarListas(&L, &L3);
    printf("Lista concatenada (L): ");
    imprimirLista(&L);

    // Testando intercalarListas
    LISTA_LIGADA_ESTATICA L4;
    iniciaLista(&L4);
    inserirElemento(&L4, 40);
    inserirElemento(&L4, 50);
    inserirElemento(&L4, 60);
    printf("Lista original (L): ");
    imprimirLista(&L);
    printf("Lista a ser intercalada (L4): ");
    imprimirLista(&L4);
    LISTA_LIGADA_ESTATICA L5 = intercalarListas(&L, &L4);
    printf("Lista intercalada (L5): ");
    imprimirLista(&L5);

    return 0;
}
