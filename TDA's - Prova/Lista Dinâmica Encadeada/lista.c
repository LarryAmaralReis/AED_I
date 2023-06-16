#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

LISTA *cria_lista() {
    LISTA *li = (LISTA *) malloc(sizeof(LISTA));
    if (li != NULL) *li = NULL;
    return li;
}

void libera_lista(LISTA *li) {
    if (li != NULL) {
        ELEMENTO *no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->proximo;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(LISTA *li) {
    if (li == NULL) return 0;
    int contador = 0;
    ELEMENTO *no = *li;
    while (no != NULL) {
        contador++;
        no = no->proximo;
    }
    return contador;
}

int lista_cheia(LISTA *li) {
    return 0;
}

int lista_vazia(LISTA *li) {
    if (li == NULL || *li == NULL) return 1;
    return 0;
}

int insere_lista_inicio(LISTA *li, ALUNO student) {
    if (li == NULL) return 0;
    ELEMENTO *no = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (no == NULL) return 0;
    no->dados = student;
    no->proximo = (*li);
    *li = no;
    return 1;
}

int insere_lista_final(LISTA *li, ALUNO student) {
    if (li == NULL) return 0;
    ELEMENTO *no = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (no == NULL) return 0;
    no->dados = student;
    no->proximo = NULL;
    if ((*li) == NULL) {
        *li = no;
    } else {
        ELEMENTO *aux = *li;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = no;
    }
    return 1;
}

int insere_lista_ordenada(LISTA *li, ALUNO student) {
    if (li == NULL) return 0;
    ELEMENTO *no = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (no == NULL) return 0;
    no->dados = student;
    if (lista_vazia(li) == 1) {
        no->proximo = (*li);
        *li = no;
        return 1;
    } else {
        ELEMENTO *anterior, *atual = *li;
        while (atual != NULL && atual->dados.matricula < student.matricula) {
            anterior = atual;
            atual = atual->proximo;
        }
        if (atual == *li) {
            no->proximo = (*li);
            *li = no;
        } else {
            no->proximo = anterior->proximo;
            anterior->proximo = no;
        }
        return 1;
    }
}

int remove_lista_inicio(LISTA *li) {
    if (li == NULL || (*li) == NULL) return 0;
    ELEMENTO *no = *li;
    *li = no->proximo;
    free(no);
    return 1;
}

int remove_lista_final(LISTA *li) {
    if (li == NULL || (*li) == NULL) return 0;
    ELEMENTO *anterior, *no = *li;
    while (no->proximo != NULL) {
        anterior = no;
        no = no->proximo;
    }
    if (no == (*li)) *li = no->proximo;
    else anterior->proximo = no->proximo;
    free(no);
    return 1;
}

int remove_lista(LISTA *li, int matricula) {
    if (li == NULL) return 0;
    ELEMENTO *anterior, *no = *li;
    while (no != NULL && no->dados.matricula != matricula) {
        anterior = no;
        no = no->proximo;
    }
    if (no == NULL) return 0;
    if (no == (*li)) *li = no->proximo;
    else anterior->proximo = no->proximo;
    free(no);
    return 1;
}

int consulta_lista_pos(LISTA *li, int pos, ALUNO *student) {
    if (li == NULL || pos <= 0) return 0;
    ELEMENTO *no = *li;
    int i = 1;
    while (no != NULL && i < pos) {
        no = no->proximo;
        i++;
    }
    if (no == NULL) return 0;
    else {
        *student = no->dados;
        return 1;
    }
}

int consulta_lista_matricula(LISTA *li, int matricula, ALUNO *student) {
    if (li == NULL) return 0;
    ELEMENTO *no = *li;
    while (no != NULL && no->dados.matricula != matricula) {
        no = no->proximo;
    }
    if (no == NULL) return 0;
    else {
        *student = no->dados;
        return 1;
    }
}


void imprime_lista(LISTA* li){
    if(li == NULL)
        return;
    ELEMENTO * no = *li;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");

        no = no->proximo;
    }
}