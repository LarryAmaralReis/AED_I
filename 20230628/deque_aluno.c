#include <stdio.h>
#include <stdlib.h>
#include "deque_aluno.h"

void inicializaDeque (DEQUE *d){
    d->cabeca = malloc(sizeof(ELEMENTO));
    d->cabeca->anterior = d->cabeca;
    d->cabeca->proximo = d->cabeca;
}

void reinicializar (DEQUE *d){
    ELEMENTO *apagar;
    ELEMENTO *elem = d->cabeca->proximo;
    while (elem != d->cabeca){
        apagar = elem;
        elem = elem->proximo;
        free(apagar);
    }
    d->cabeca->anterior = d->cabeca;
    d->cabeca->proximo = d->cabeca;
}

void mostrarDeque (DEQUE *d){
    printf("-------------------------------\n");
    ELEMENTO *i = d->cabeca->proximo;
    while (i != d->cabeca){
        printf("---------------------------------------------\n");
        printf("Aluno: %d\n", i);
        printf("Matricula: %d\n", i->aluno.matricula);
        printf("Nome: %s\n", i->aluno.nome);

        i = i->proximo;
    }
}

int inserirAlunoInicio (DEQUE *d, ALUNO novo_aluno){
    ELEMENTO *i;
    i = malloc(sizeof(ELEMENTO));
    i->aluno = novo_aluno;
    i->proximo = d->cabeca->proximo;
    i->anterior = d->cabeca;
    d->cabeca->proximo = i;
    i->anterior->proximo = i;
    return 1;
}

int inserirAlunoFim (DEQUE *d, ALUNO novo_aluno){
    ELEMENTO *i;
    i = malloc (sizeof(ELEMENTO));
    i->aluno = novo_aluno;
    i->proximo = d->cabeca;
    i->anterior = d->cabeca->anterior;
    d->cabeca->anterior = i;
    i->anterior->proximo = i;
    return 1;
}

int excluirAlunoInicio(DEQUE *d){
    if (d->cabeca->proximo==d->cabeca) return 0;
    ELEMENTO *i = d->cabeca->proximo;
    d->cabeca->proximo = i->proximo;
    i->proximo->anterior = d->cabeca;
    free(i);
    return 1;
}

int excluirPacienteFim (DEQUE *d){
    if (d->cabeca->proximo==d->cabeca) return 0;
    ELEMENTO *i = d->cabeca->anterior;
    d->cabeca->anterior = i->anterior;
    i->anterior->proximo = d->cabeca;
    free(i);
    return 1;
}

void exibe(DEQUE *d, int pos, char ordem) {
    int count = 0;
    ELEMENTO *atual;

    if (ordem == 'd') {
        // Percorre o deque na ordem direta
        atual = d->cabeca->proximo;
        while (atual != d->cabeca && count < pos) {
            atual = atual->proximo;
            count++;
        }
    } else if (ordem == 'i') {
        // Percorre o deque na ordem inversa
        atual = d->cabeca->anterior;
        while (atual != d->cabeca && count < pos) {
            atual = atual->anterior;
            count++;
        }
    } else {
        printf("Ordem inválida!\n");
        return;
    }

    printf("Alunos a partir da posição %d na ordem %c:\n", pos, ordem);

    // Exibe os nomes dos alunos a partir da posição indicada
    while (atual != d->cabeca) {
        printf("%s\t", atual->aluno.nome);
        if (ordem == 'd') {
            atual = atual->proximo;
        } else if (ordem == 'i') {
            atual = atual->anterior;
        }
    }
}