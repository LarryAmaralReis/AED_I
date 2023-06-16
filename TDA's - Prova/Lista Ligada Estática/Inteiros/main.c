#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "lista.c"

int main() {
    LISTA *li = cria_lista();

    insere_lista_inicio(li, 5);
    insere_lista_inicio(li, 3);
    insere_lista_final(li, 8);
    insere_lista_meio(li, 6);
    insere_lista_ordenada(li, 4);

    imprimir_lista(li);

    int elemento;
    int removido = remove_maior_elemento(li, &elemento);
    if (removido) {
        printf("Maior elemento removido: %d\n", elemento);
    } else {
        printf("Não foi possível remover o maior elemento.\n");
    }


    int posicao;
    if (consulta_lista_elem(li, 6, &posicao)) {
        printf("O elemento 6 esta na posicao %d.\n", posicao);
    } else {
        printf("O elemento 6 nao esta na lista.\n");
    }

    remove_lista(li, 6);

    imprimir_lista(li);

    libera_lista(li);

    return 0;
}
