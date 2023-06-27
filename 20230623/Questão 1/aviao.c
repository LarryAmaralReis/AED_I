#include <stdio.h>
#include <stdlib.h>
#include "aviao.h"

FILA* cria_Fila(){
    FILA *fi = (FILA*) malloc(sizeof(FILA));
    if (fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
    }
    return fi;
}

void libera_Fila(FILA* fi){
    free(fi);
}

int consulta_Fila(FILA* fi, AVIAO* av){
    if (fi == NULL || Fila_vazia(fi))
        return 0;
    *av = fi->dados[(fi->inicio + 1) % MAX];
    return 1;
}

int insere_Fila(FILA* fi, AVIAO av){
    if (fi == NULL || Fila_cheia(fi))
        return 0;
    fi->final = (fi->final + 1) % MAX;
    fi->dados[fi->final] = av;
    return 1;
}

int remove_Fila(FILA* fi){
    if (fi == NULL || Fila_vazia(fi))
        return 0;
    fi->inicio = (fi->inicio + 1) % MAX;
    return 1;
}

int tamanho_Fila(FILA* fi){
    if (fi == NULL)
        return -1;
    int qtd;
    if (fi->final >= fi->inicio)
        qtd = fi->final - fi->inicio;
    else
        qtd = MAX - (fi->inicio - fi->final);
    return qtd;
}

int Fila_cheia(FILA* fi){
    if (fi == NULL)
        return -1;
    return (fi->inicio == (fi->final + 1) % MAX);
}

int Fila_vazia(FILA* fi){
    if (fi == NULL)
        return -1;
    return (fi->inicio == fi->final);
}

void imprime_Fila(FILA* fi){
    if (fi == NULL)
        return;
    int i = fi->inicio;
    if (Fila_vazia(fi)){
        printf("A fila de decolagem está vazia.\n");
        return;
    }
    printf("Aviões na fila de decolagem:\n");
    do {
        i = (i + 1) % MAX;
        printf("Identificador: %d\n", fi->dados[i].identificador);
        printf("Nome: %s\n", fi->dados[i].nome);
        printf("---------------------------\n");
    } while (i != fi->final);
}
