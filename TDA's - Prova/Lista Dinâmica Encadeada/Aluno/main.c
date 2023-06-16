#include <stdio.h>
#include "lista.c"
#include "lista.h"

int main() {
    printf("Lista Dinamica Encadeada\n");
    ALUNO al, a[4] = {{2, "Andre",   9, 7},
                      {4, "Ricardo", 7, 8},
                      {1, "Bianca",  9, 6},
                      {3, "Ana",     5, 6}};
    LISTA *li = cria_lista();
    printf("Tamanho: %d\n\n\n\n", tamanho_lista(li));

    int i;
    for (i = 0; i < 4; i++)
        insere_lista_ordenada(li, a[i]);

    imprime_lista(li);

    int position = busca_sequencial(li, 4);
    if (position != -1) {
        printf("Student found at position: %d\n", position);
    } else {
        printf("Student not found\n");
    }

    printf("\n\n\n Tamanho: %d\n\n\n\n", tamanho_lista(li));

    for (i = 0; i < 4; i++) {
        remove_lista_final(li);
        imprime_lista(li);
        printf("\n Tamanho: %d\n\n\n", tamanho_lista(li));
    }

    for (i = 0; i < 4; i++)
        insere_lista_inicio(li, a[i]);
    imprime_lista(li);

    libera_lista(li);
    return 0;
}


