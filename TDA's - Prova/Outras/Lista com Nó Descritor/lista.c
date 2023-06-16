#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

LISTA *cria_lista() {
    LISTA *li = (LISTA *) malloc(sizeof(LISTA));
    if (li != NULL) {
        li->inicio = NULL;
        li->final = NULL;
        li->qtd = 0;
    }
    return li;
}

void libera_lista(LISTA *li) {
    if (li != NULL) {
        ELEMENTO *no;
        while ((li->inicio) != NULL) {
            no = li->inicio;
            li->inicio = li->inicio->proximo;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(LISTA *li) {
    if (li == NULL)
        return 0;
    return li->qtd;
}

int lista_cheia(LISTA *li) {
    return 0;
}

int lista_vazia(LISTA *li) {
    if (li == NULL)
        return 1;
    if (li->inicio == NULL)
        return 1;
    return 0;
}

int insere_lista_inicio(LISTA *li, ALUNO student) {
    if (li == NULL)
        return 0;
    ELEMENTO *no;
    no = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (no == NULL)
        return 0;
    no->dados = student;
    no->proximo = li->inicio;
    if (li->inicio == NULL)
        li->final = no;
    li->inicio = no;
    li->qtd++;
    return 1;
}

int insere_lista_final(LISTA *li, ALUNO student) {
    if (li == NULL)
        return 0;
    ELEMENTO *no;
    no = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (no == NULL)
        return 0;
    no->dados = student;
    no->proximo = NULL;
    if (li->inicio == NULL)//lista vazia: insere início
        li->inicio = no;
    else
        li->final->proximo = no;

    li->final = no;
    li->qtd++;
    return 1;
}


int remove_lista_inicio(LISTA *li) {
    if (li == NULL)
        return 0;
    if (li->inicio == NULL)//lista vazia
        return 0;

    ELEMENTO *no = li->inicio;
    li->inicio = no->proximo;
    free(no);
    if (li->inicio == NULL)
        li->final = NULL;
    li->qtd--;
    return 1;
}

int remove_lista_final(LISTA *li) {
    if (li == NULL)
        return 0;
    if (li->inicio == NULL)//lista vazia
        return 0;

    ELEMENTO *ant, *no = li->inicio;
    while (no->proximo != NULL) {
        ant = no;
        no = no->proximo;
    }
    if (no == li->inicio) {//remover o primeiro?
        li->inicio = NULL;
        li->final = NULL;
    } else {
        ant->proximo = no->proximo;
        li->final = ant;
    }
    free(no);
    li->qtd--;
    return 1;
}

//=================================================
int consulta_lista_pos(LISTA *li, int posicao, ALUNO *student) {
    if (li == NULL || li->inicio == NULL || posicao <= 0)
        return 0;
    ELEMENTO *no = li->inicio;//primeiro elemento
    int i = 1;
    while (no != NULL && i < posicao) {
        no = no->proximo;
        i++;
    }
    if (no == NULL)
        return 0;
    else {
        *student = no->dados;
        return 1;
    }
}

int consulta_lista_mat(LISTA *li, int matricula, ALUNO *student) {
    if (li == NULL || li->inicio == NULL)
        return 0;
    ELEMENTO *no = li->inicio;
    while (no != NULL && no->dados.matricula != matricula)
        no = no->proximo;
    if (no->dados.matricula != matricula)
        return 0;
    else {
        *student = no->dados;
        return 1;
    }
}

void imprime_lista(LISTA *li) {
    if (li == NULL || li->inicio == NULL)
        return;
    ELEMENTO *no = li->inicio;
    while (no != NULL) {
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %f %f %f\n", no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");
        no = no->proximo;
    }
}