#include <stdbool.h>
#ifndef TURMA_ESTATICA_H
#define TURMA_ESTATICA_H
#define MAX 100

typedef struct {
    int matricula;
    char *nome;
    int idade;
} ALUNO;

typedef struct {
    ALUNO alun;
    int proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO turma[MAX];
    int inicio;
    int disponivel;
} LISTA_MATRICULA;

void iniciaLista_M(LISTA_MATRICULA *m);
int tamanho(LISTA_MATRICULA *m);
void mostrarLista_M(LISTA_MATRICULA *m);
int buscaMatricula(LISTA_MATRICULA *m, int matricula_aluno);
int obterNo(LISTA_MATRICULA *m);
void alocarNo(LISTA_MATRICULA *m, int i);
bool inserirAluno(LISTA_MATRICULA *m, ALUNO novo_aluno);
bool excluirAluno(LISTA_MATRICULA *m, int matricula_aluno);

#endif //TURMA_ESTATICA_H