#ifndef TURMA_H
#define TURMA_H

typedef struct {
    int codigo_aluno;
    char nome_aluno[50];
    int idade_aluno;
    float coeficiente_aluno;
} ALUNO;

typedef struct {
    ALUNO *lista_alunos;
    int quantidade_alunos;
} TURMA;

void criarTurma(TURMA *t, int quantidade_alunos);
void liberarTurma(TURMA *t);
void inserirAluno(TURMA *t, int codigo_aluno, const char *nome_aluno, int idade_aluno, float coeficiente_aluno);
void imprimirTurma(TURMA *t);
void buscarAlunoSequencial(TURMA *t, int codigo_aluno);
void buscarAlunoBinarioRecursivo(TURMA *t, int codigo_aluno, int primeiro, int ultimo);
void imprimirDadosAluno(ALUNO *aluno);

#endif //TURMA_H