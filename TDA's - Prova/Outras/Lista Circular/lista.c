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
    if (li != NULL && (*li) != NULL) {
        ELEMENTO *aux, *no = *li;
        while ((*li) != no->proximo) {
            aux = no;
            no = no->proximo;
            free(aux);
        }
        free(no);
        free(li);
    }
}

int consulta_lista_pos(LISTA *li, int posicao, ALUNO *student) {
    if (li == NULL || (*li) == NULL || posicao <= 0)
        return 0;
    ELEMENTO *no = *li;
    int i = 1;
    while (no->proximo != (*li) && i < posicao) {
        no = no->proximo;
        i++;
    }
    if (i != posicao)
        return 0;
    else {
        *student = no->dados;
        return 1;
    }
}

int consulta_lista_mat(LISTA *li, int matricula, ALUNO *student) {
    if (li == NULL || (*li) == NULL)
        return 0;
    ELEMENTO *no = *li;
    while (no->proximo != (*li) && no->dados.matricula != matricula)
        no = no->proximo;
    if (no->dados.matricula != matricula)
        return 0;
    else {
        *student = no->dados;
        return 1;
    }
}

int insere_lista_final(LISTA *li, ALUNO student) {
    if (li == NULL)
        return 0;
    ELEMENTO *no = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (no == NULL)
        return 0;
    no->dados = student;
    if ((*li) == NULL) {//lista vazia: insere início
        *li = no;
        no->proximo = no;
    } else {
        ELEMENTO *aux = *li;
        while (aux->proximo != (*li)) {
            aux = aux->proximo;
        }
        aux->proximo = no;
        no->proximo = *li;
    }
    return 1;
}

int insere_lista_inicio(LISTA *li, ALUNO student) {
    if (li == NULL)
        return 0;
    ELEMENTO *no = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (no == NULL)
        return 0;
    no->dados = student;
    if ((*li) == NULL) {//lista vazia: insere início
        *li = no;
        no->proximo = no;
    } else {
        ELEMENTO *aux = *li;
        while (aux->proximo != (*li)) {
            aux = aux->proximo;
        }
        aux->proximo = no;
        no->proximo = *li;
        *li = no;
    }
    return 1;
}

int insere_lista_ordenada(LISTA *li, ALUNO student) {//TERMINAR
    if (li == NULL)
        return 0;
    ELEMENTO *no = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    if (no == NULL)
        return 0;
    no->dados = student;
    if ((*li) == NULL) {//insere início
        *li = no;
        no->proximo = no;
        return 1;
    } else {
        if ((*li)->dados.matricula > student.matricula) {//insere início
            ELEMENTO *atual = *li;
            while (atual->proximo != (*li))//procura o último
                atual = atual->proximo;
            no->proximo = *li;
            atual->proximo = no;
            *li = no;
            return 1;
        }
        ELEMENTO *ant = *li, *atual = (*li)->proximo;
        while (atual != (*li) && atual->dados.matricula < student.matricula) {
            ant = atual;
            atual = atual->proximo;
        }
        ant->proximo = no;
        no->proximo = atual;
        return 1;
    }
}

int remove_lista_inicio(LISTA *li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)//lista vazia
        return 0;

    if ((*li) == (*li)->proximo) {//lista fica vaza
        free(*li);
        *li = NULL;
        return 1;
    }
    ELEMENTO *atual = *li;
    while (atual->proximo != (*li))//procura o último
        atual = atual->proximo;

    ELEMENTO *no = *li;
    atual->proximo = no->proximo;
    *li = no->proximo;
    free(no);
    return 1;
}

int remove_lista_final(LISTA *li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)//lista vazia
        return 0;

    if ((*li) == (*li)->proximo) {//lista fica vaza
        free(*li);
        *li = NULL;
        return 1;
    }
    ELEMENTO *ant, *no = *li;
    while (no->proximo != (*li)) {//procura o último
        ant = no;
        no = no->proximo;
    }
    ant->proximo = no->proximo;
    free(no);
    return 1;
}

int remove_lista(LISTA *li, int matricula) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)//lista vazia
        return 0;
    ELEMENTO *no = *li;
    if (no->dados.matricula == matricula) {//remover do início
        if (no == no->proximo) {//lista fica vaza
            free(no);
            *li = NULL;
            return 1;
        } else {
            ELEMENTO *ult = *li;
            while (ult->proximo != (*li))//procura o último
                ult = ult->proximo;
            ult->proximo = (*li)->proximo;
            *li = (*li)->proximo;
            free(no);
            return 1;
        }
    }
    ELEMENTO *ant = no;
    no = no->proximo;
    while (no != (*li) && no->dados.matricula != matricula) {
        ant = no;
        no = no->proximo;
    }
    if (no == *li)//não encontrado
        return 0;

    ant->proximo = no->proximo;
    free(no);
    return 1;
}

int tamanho_lista(LISTA *li) {
    if (li == NULL || (*li) == NULL)
        return 0;
    int cont = 0;
    ELEMENTO *no = *li;
    do {
        cont++;
        no = no->proximo;
    } while (no != (*li));
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
    if (li == NULL || (*li) == NULL)
        return;
    ELEMENTO *no = *li;
    do {
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %f %f %f\n", no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");
        no = no->proximo;
    } while (no != (*li));
}

