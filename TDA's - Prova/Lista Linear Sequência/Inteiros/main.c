#include <stdio.h>
#include "lista.c"
#include "lista.h"

int main() {
    printf("Lista Sequencial Estatica p elementos inteiros.\n\n");
    LISTA *li = cria_lista();
    int elemento, posicao;

    insere_lista_inicio(li, 10);
    insere_lista_inicio(li, 20);
    insere_lista_final(li, 30);
    insere_lista_meio(li, 15);
    insere_lista_ordenada(li, 25);

    printf("Quantidade de repeticoes:%d\n", quantidade_repetidos(li, 10));

    imprimir_lista(li);

    printf("Tamanho da lista: %d\n", tamanho_lista(li));

    if (consulta_lista_pos(li, 3, &elemento))
        printf("Elemento na posicao 3: %d\n", elemento);

    if (consulta_lista_elem(li, 30, &posicao))
        printf("Posicao do elemento 30: %d\n", posicao);

    printf("Busca sequencial do elemento 25: %d\n", busca_sequencial(li, 25));
    printf("Busca binária do elemento 30: %d\n", busca_binaria(li, 30));

    remove_lista_pos(li, 2);

    imprimir_lista(li);

    libera_lista(li);

    return 0;
}


