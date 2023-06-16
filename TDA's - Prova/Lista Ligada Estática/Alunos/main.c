#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "lista.c"

int main() {
    LISTA *li = cria_lista();

    ALUNO aluno1 = {1, "Joao", 20, 0};
    ALUNO aluno2 = {2, "Maria", 22, 1};
    ALUNO aluno3 = {3, "Pedro", 19, 2};

    insere_lista_final(li, aluno1);
    insere_lista_final(li, aluno2);
    insere_lista_final(li, aluno3);

    LISTA* alunos_maior = alunos_maior_idade(li);

    if (lista_vazia(alunos_maior)) {
        printf("Nenhum aluno encontrado.\n");
    } else {
        printf("Alunos com maior idade:\n");
        imprimir_lista(alunos_maior);
    }

    libera_lista(alunos_maior);

    printf("Aluno existe: %d\n", aluno_existe(li, 2));
    printf("Aluno duplicado: %d\n", verifica_aluno_duplicado(li, 1));
    printf("Lista de Alunos:\n");
    imprimir_lista(li);

    printf("Tamanho da lista: %d\n", tamanho_lista(li));

    int posicao;
    int codigo = 2;

    if (consulta_lista_codigo(li, codigo, &posicao)) {
        printf("Aluno de codigo %d encontrado na posicao %d.\n", codigo, posicao);
    } else {
        printf("Aluno de codigo %d não encontrado.\n", codigo);
    }

    remove_lista(li, 2);

    printf("Lista de Alunos apos remocao:\n");
    imprimir_lista(li);

    libera_lista(li);

    return 0;
}
