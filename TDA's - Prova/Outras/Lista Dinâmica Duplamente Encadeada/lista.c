#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

LISTA *cria_lista() {
    LISTA *li = (LISTA *) malloc(sizeof(LISTA));
    if (li != NULL)
        *li = NULL;
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

int consulta_lista_pos(LISTA *li, int pos, ALUNO *student) {
    if (li == NULL || pos <= 0)
        return 0;
    ELEMENTO *no = *li;
    int i = 1;
    while (no != NULL && i < pos) {
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

int consulta_lista_mat(LISTA *li, int mat, ALUNO *student) {
    if (li == NULL)
        return 0;
    ELEMENTO *no = *li;
    while (no != NULL && no->dados.matricula != mat) {
        no = no->proximo;
    }
    if (no == NULL)
        return 0;
    else {
        *student = no->dados;
        return 1;
    }
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
    if ((*li) == NULL) {//lista vazia: insere início
        no->anterior = NULL;
        *li = no;
    } else {
        ELEMENTO *aux;
        aux = *li;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = no;
        no->anterior = aux;
    }
    return 1;
}

int insere_lista_inicio(LISTA *li, ALUNO student) {
    if (li == NULL)
        return 0;
    ELEMENTO *no;
    no = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (no == NULL)
        return 0;
    no->dados = student;
    no->proximo = (*li);
    no->anterior = NULL;
    if (*li != NULL)//lista não vazia: apontar para o anterior!
        (*li)->anterior = no;
    *li = no;
    return 1;
}

int insere_lista_ordenada(LISTA *li, ALUNO student) {
    if (li == NULL)
        return 0;
    ELEMENTO *no = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (no == NULL)
        return 0;
    no->dados = student;
    if ((*li) == NULL) {//lista vazia: insere início
        no->proximo = NULL;
        no->anterior = NULL;
        *li = no;
        return 1;
    } else {
        ELEMENTO *ante, *atual = *li;
        while (atual != NULL && atual->dados.matricula < student.matricula) {
            ante = atual;
            atual = atual->proximo;
        }
        if (atual == *li) {//insere início
            no->anterior = NULL;
            (*li)->anterior = no;
            no->proximo = (*li);
            *li = no;
        } else {
            no->proximo = ante->proximo;
            no->anterior = ante;
            ante->proximo = no;
            if (atual != NULL)
                atual->anterior = no;
        }
        return 1;
    }
}

int remove_lista(LISTA *li, int mat) {//TERMINAR
    if (li == NULL)
        return 0;
    if ((*li) == NULL)//lista vazia
        return 0;
    ELEMENTO *no = *li;
    while (no != NULL && no->dados.matricula != mat) {
        no = no->proximo;
    }
    if (no == NULL)//não encontrado
        return 0;

    if (no->anterior == NULL)//remover o primeiro?
        *li = no->proximo;
    else
        no->anterior->proximo = no->proximo;

    if (no->proximo != NULL)//não é o último?
        no->proximo->anterior = no->anterior;

    free(no);
    return 1;
}


int remove_lista_inicio(LISTA *li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)//lista vazia
        return 0;

    ELEMENTO *no = *li;
    *li = no->proximo;
    if (no->proximo != NULL)
        no->proximo->anterior = NULL;

    free(no);
    return 1;
}

int remove_lista_final(LISTA *li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)//lista vazia
        return 0;

    ELEMENTO *no = *li;
    while (no->proximo != NULL)
        no = no->proximo;

    if (no->anterior == NULL)//remover o primeiro e único
        *li = no->proximo;
    else
        no->anterior->proximo = NULL;

    free(no);
    return 1;
}

int tamanho_lista(LISTA *li) {
    if (li == NULL)
        return 0;
    int cont = 0;
    ELEMENTO *no = *li;
    while (no != NULL) {
        cont++;
        no = no->proximo;
    }
    return cont;
}

int lista_cheia(LISTA *li) {
    return 0;
}

int lista_vazia(LISTA *li) {
    if (li == NULL)
        return 1;
    if (*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(LISTA *li) {
    if (li == NULL)
        return;
    ELEMENTO *no = *li;
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
