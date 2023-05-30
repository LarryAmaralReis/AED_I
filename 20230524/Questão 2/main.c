#include <stdio.h>
#include "turma.h"

int main() {
    TURMA turma;

    criarTurma(&turma, 3);
    inserirAluno(&turma, 0, "Joao", 20, 7.5);
    inserirAluno(&turma, 1, "Maria", 22, 8.2);
    inserirAluno(&turma, 2, "Pedro", 21, 6.9);

    imprimirTurma(&turma);
    buscarAlunoSequencial(&turma, 41);
    liberarTurma(&turma);
    return 0;
}
