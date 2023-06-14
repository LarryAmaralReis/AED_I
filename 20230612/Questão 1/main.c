#include <stdio.h>
#include <stdlib.h>
#include "dupla_ligacao.h"

int main() {
    LISTA L;
    inicializarLista(&L);

    inserirNaLista(&L, 10);
    inserirNaLista(&L, 3);
    inserirNaLista(&L, 44);
    inserirNaLista(&L, 1000);
    inserirNaLista(&L, 5);

    printf("Lista L antes da ordenacao: ");
    exibirLista(&L);

    LISTA K = criarListaOrdenada(&L);

    printf("Lista L apos a ordenacao: ");
    exibirLista(&L);

    printf("Lista K: ");
    exibirLista(&K);

    return 0;
}

