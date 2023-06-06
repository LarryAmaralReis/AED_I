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

    return 0;
}
