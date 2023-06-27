#include <stdio.h>
#include <stdlib.h>
#include "aviao.h"
#include "aviao.c"

int main() {
    FILA* filaDecolagem = cria_Fila();

    // Adicionar aviões à fila de decolagem
    AVIAO aviao1 = {1, "Aviao 1"};
    AVIAO aviao2 = {2, "Aviao 2"};
    AVIAO aviao3 = {3, "Aviao 3"};
    insere_Fila(filaDecolagem, aviao1);
    insere_Fila(filaDecolagem, aviao2);
    insere_Fila(filaDecolagem, aviao3);

    // Listar o número de aviões aguardando na fila de decolagem
    int tamanho = tamanho_Fila(filaDecolagem);
    if (tamanho >= 0)
        printf("Número de aviões aguardando na fila de decolagem: %d\n", tamanho);
    else
        printf("Erro ao obter o tamanho da fila.\n");

    // Autorizar a decolagem do primeiro avião da fila
    if (!Fila_vazia(filaDecolagem)) {
        AVIAO av;
        if (consulta_Fila(filaDecolagem, &av)) {
            printf("Autorizando a decolagem do avião com identificador %d\n", av.identificador);
            remove_Fila(filaDecolagem);
        } else {
            printf("Erro ao consultar o avião na fila de decolagem.\n");
        }
    } else {
        printf("Não há aviões na fila de decolagem.\n");
    }

    // Adicionar um avião à fila de espera
    AVIAO aviao4 = {4, "Aviao 4"};
    if (insere_Fila(filaDecolagem, aviao4)) {
        printf("Avião adicionado à fila de espera.\n");
    } else {
        printf("Erro ao adicionar o avião à fila de espera.\n");
    }

    // Listar todos os aviões na fila de espera
    imprime_Fila(filaDecolagem);

    // Listar as características do primeiro avião da fila
    if (!Fila_vazia(filaDecolagem)) {
        AVIAO av;
        if (consulta_Fila(filaDecolagem, &av)) {
            printf("Características do primeiro avião da fila de decolagem:\n");
            printf("Identificador: %d\n", av.identificador);
            printf("Nome: %s\n", av.nome);
        } else {
            printf("Erro ao consultar o avião na fila de decolagem.\n");
        }
    } else {
        printf("Não há aviões na fila de decolagem.\n");
    }

    libera_Fila(filaDecolagem);

    return 0;
}
