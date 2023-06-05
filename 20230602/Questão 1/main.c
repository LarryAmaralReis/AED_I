#include <stdio.h>
#include "turma_estatica.h"

int main() {
    LISTA_MATRICULA m;
    iniciaLista_M(&m);
    printf("%d\n", tamanho(&m));
    ALUNO a;
    a.matricula = 22;
    a.nome = "Karla";
    a.idade = 23;
    inserirAluno(&m,a);

    a.matricula = 20;
    a.nome = "Luis";
    a.idade = 23;
    inserirAluno(&m,a);

    a.matricula = 18;
    a.nome = "Pedro";
    a.idade = 23;
    inserirAluno(&m,a);

    a.matricula = 33;
    a.nome = "Israel";
    a.idade = 23;
    inserirAluno(&m,a);

    a.matricula = 30;
    a.nome = "Diana";
    a.idade = 23;
    inserirAluno(&m,a);

    a.matricula = 12;
    a.nome = "Esteban";
    a.idade = 23;
    inserirAluno(&m,a);

    printf("%d\n", tamanho(&m));
    mostrarLista_M(&m);
    excluirAluno(&m, 30);
    printf("%d\n", tamanho(&m));
    mostrarLista_M(&m);

    return 0;
}
