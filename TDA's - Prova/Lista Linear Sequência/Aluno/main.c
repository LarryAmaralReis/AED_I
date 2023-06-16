#include <stdio.h>
#include "lista.c"
#include "lista.h"

int main() {
    printf("Lista Sequencial Estatica\n");
    LISTA *li = cria_lista();

    ALUNO aluno1 = {123, "Joao", 10, 8};
    ALUNO aluno2 = {456, "Maria", 11, 7};
    ALUNO aluno3 = {789, "Pedro", 8, 9};

    // Inserindo elementos na lista
    insere_lista_inicio(li, aluno1);
    insere_lista_final(li, aluno2);
    insere_lista_meio(li, aluno3);

    // Tamanho Lista

    int x = tamanho_lista(li);
    printf("%d\n", x);

    imprimir_elementos(li);

    int y = lista_cheia(li);
    printf("%d\n", y);

    // Removendo um elemento
    remove_lista_pos(li, 3);

    // Consultando um elemento por posição
    ALUNO aluno_consulta;
    consulta_lista_pos(li, 1, &aluno_consulta);
    printf("Aluno na posicao 1: Matricula %d, Nome: %s\n", aluno_consulta.codigo, aluno_consulta.nome);

    // Consultando um elemento por matrícula
    consulta_lista_mat(li, 123, &aluno_consulta);
    printf("Aluno com matricula 123: Nome: %s, Idade: %d, Numero de filhos: %d",
           aluno_consulta.nome, aluno_consulta.idade, aluno_consulta.n_filhos);
    printf("\n\nPosicao:%d",busca_sequencial(li, 789));
    libera_lista(li);

    return 0;
}


