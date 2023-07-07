#ifndef DEQUE_ALUNO_H
#define DEQUE_ALUNO_H

typedef struct {
    int matricula;
    char *nome;
} ALUNO;

typedef struct aux {
    ALUNO aluno;
    struct aux* anterior;
    struct aux* proximo;
} ELEMENTO;

typedef struct{
    ELEMENTO *cabeca;
} DEQUE;

void inicializaDeque (DEQUE *d);
//int tamanho (DEQUE *d);
int inserirAlunoFim (DEQUE *d, ALUNO novo_aluno);
int inserirAlunoInicio (DEQUE *d, ALUNO novo_aluno);
int excluirAlunoInicio (DEQUE *d);
int excluirAlunoFim (DEQUE *d);
void reinicializar (DEQUE *d);
void mostrarDeque (DEQUE *d);

#endif