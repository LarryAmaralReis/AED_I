#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turma.h"


void criarTurma(TURMA *t, int quantidade_alunos) {
    t->lista_alunos = (ALUNO *) malloc(sizeof(ALUNO) * quantidade_alunos);
    t->quantidade_alunos = quantidade_alunos;
}

void liberarTurma(TURMA *t) {
    free(t->lista_alunos);
    free(t);
}

void inserirAluno(TURMA *t, int posicao, const char *nome, int idade, float coeficiente) {
    if (posicao < 0 || posicao >= t->quantidade_alunos) {
        printf("Posicao invalida.\n");
        return;
    }
    static int codigo_aluno = 0;
    ALUNO aluno;
    aluno.codigo_aluno = codigo_aluno++;
    strcpy(aluno.nome_aluno, nome);
    aluno.idade_aluno = idade;
    aluno.coeficiente_aluno = coeficiente;

    t->lista_alunos[posicao] = aluno;
}

void imprimirTurma(TURMA *t) {
    if (t->quantidade_alunos == 0) {
        printf("Turma vazia.\n");
        return;
    }
    printf("Turma:\n");
    for (int i = 0; i < t->quantidade_alunos; i++) {
        printf("Aluno %d:\n", i);
        printf("Codigo: %d\n", t->lista_alunos[i].codigo_aluno);
        printf("Nome: %s\n", t->lista_alunos[i].nome_aluno);
        printf("\n");
    }
}

void buscarAlunoSequencial(TURMA *t, int codigo_aluno) {
    for (int i = 0; i < t->quantidade_alunos; i++) {
        if (t->lista_alunos[i].codigo_aluno == codigo_aluno) {
            imprimirDadosAluno(&(t->lista_alunos[i]));
            return;
        }
    }
    printf("Aluno nao encontrado sequencialmente.\n");
}

void buscarAlunoBinarioRecursivo(TURMA *t, int codigo_aluno, int primeiro, int ultimo) {
    if (ultimo >= primeiro) {
        int meio = primeiro + (ultimo - primeiro) / 2;
        if (t->lista_alunos[meio].codigo_aluno == codigo_aluno) {
            imprimirDadosAluno(&(t->lista_alunos[meio]));
            return;
        }
        if (t->lista_alunos[meio].codigo_aluno > codigo_aluno) {
            buscarAlunoBinarioRecursivo(t, codigo_aluno, primeiro, meio - 1);
        } else {
            buscarAlunoBinarioRecursivo(t, codigo_aluno, meio + 1, ultimo);
        }
    } else {
        printf("Aluno nao encontrado recursivamente.\n");
    }
}

void imprimirDadosAluno(ALUNO *aluno) {
    if (aluno != NULL) {
        printf("Codigo do Aluno: %d\n", aluno->codigo_aluno);
        printf("Nome do Aluno: %s\n", aluno->nome_aluno);
        printf("Idade do Aluno: %d\n", aluno->idade_aluno);
        printf("Coeficiente do Aluno: %.2f\n\n", aluno->coeficiente_aluno);
    } else {
        printf("Aluno não encontrado.\n");
    }
}



