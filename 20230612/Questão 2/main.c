#include <stdio.h>
#include "polinomio.h"

int main() {
    LISTA P1, P2;
    inicializarLista(&P1);
    inicializarLista(&P2);

    inserirNaLista(&P1, 4, 2);
    inserirNaLista(&P1, -10, 1);
    inserirNaLista(&P1, -5, 0);

    inserirNaLista(&P2, 6, 1);
    inserirNaLista(&P2, 12, 0);

    printf("Polinomio P1: ");
    exibirLista(&P1);

    printf("Polinomio P2: ");
    exibirLista(&P2);

    LISTA S = somaPolinomio(&P1, &P2);
    printf("Soma: ");
    exibirLista(&S);

    return 0;
}

