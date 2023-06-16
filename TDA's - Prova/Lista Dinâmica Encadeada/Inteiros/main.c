#include <stdio.h>
#include "lista.c"
#include "lista.h"

int main() {
    printf("Lista Dinamica Encadeada\n");

    LISTA *li = cria_lista();
    printf("Tamanho: %d\n\n\n\n", tamanho_lista(li));

    int i;
    for (i = 0; i < 4; i++)
        insere_lista_ordenada(li, i);
    printf("Elemento duplicado:%d\n", elemento_duplicado(li, 2));
    printf("Posicao:%d\n", busca_sequencial(li, 2));

    imprime_lista(li);
    printf("\n\n\n Tamanho: %d\n\n\n\n", tamanho_lista(li));

    for (i = 0; i < 4; i++) {
        remove_lista_final(li);
        imprime_lista(li);
        printf("\n Tamanho: %d\n\n\n", tamanho_lista(li));
    }

    for (i = 0; i < 4; i++)
        insere_lista_inicio(li, i*2);
    imprime_lista(li);

    libera_lista(li);
    return 0;
}


