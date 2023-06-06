#include <stdio.h>
#include <stdbool.h>
#include "turma_estatica.h"

/*
void iniciaLista_M(LISTA_MATRICULA *m) {
    for (int i = 0; i < MAX - 1; i++) {
        m->turma[i].proximo = i + 1;
        m->turma[MAX - 1].proximo = -1;
        m->inicio = -1;
        m->disponivel = 0;
    }
}
*/
void iniciaLista_M(LISTA_MATRICULA *m) {
    for (int i = 0; i < MAX - 1; i++) {
        m->turma[i].proximo = i + 1;
    }
    m->turma[MAX - 1].proximo = -1;
    m->inicio = -1;
    m->disponivel = 0;
}

int tamanho(LISTA_MATRICULA *m) {
    int tam = 0;
    int i = m->inicio;
    while (i != -1) {
        tam++;
        i = m->turma[i].proximo;
    }
    if(tam == 0) printf("Lista vazia");
    if(tam == 100) printf("Lista cheia");
    return tam;
}

void mostrarLista_M(LISTA_MATRICULA *m) {
    printf("----------------------------------------\n");
    int i = m->inicio;
    while (i != -1) {
        printf("Aluno: %d\n", i);
        printf("Codigo: %d\n", m->turma[i].alun.matricula);
        printf("Nome: %s\n", m->turma[i].alun.nome);
        printf("Idade: %d\n", m->turma[i].alun.idade);
        printf("----------------------------------------\n");
        i = m->turma[i].proximo;
    }
}

int buscaMatricula(LISTA_MATRICULA *m, int matricula_aluno) {
    int i = m->inicio;
    while (i != -1 && m->turma[i].alun.matricula < matricula_aluno) {
        i = m->turma[i].proximo;
        if (i != -1 && m->turma[i].alun.matricula == matricula_aluno) {
            return i;
        } else {
            return -1;
        }
    }
}

int obterNo(LISTA_MATRICULA *m) {
    int disp = m->disponivel;
    if (m->disponivel != -1) {
        m->disponivel = m->turma[disp].proximo;
    } else {
        m->disponivel++;
    }
    return disp;
}

bool inserirAluno(LISTA_MATRICULA *m, ALUNO novo_aluno) {
    if (m->disponivel == -1) {
        return false;
    }
    int i = m->inicio;
    int pos_inserir = -1;
    while ((i != -1) && (novo_aluno.matricula > m->turma[i].alun.matricula)) {
        pos_inserir = i;
        i = m->turma[i].proximo;
    }
    if ((i != -1) && (novo_aluno.matricula == m->turma[i].alun.matricula)) {//m->turma[pos_inserir]
        return false;
    }
    i = obterNo(m);
    m->turma[i].alun = novo_aluno;
    if (pos_inserir == -1) {
        m->turma[i].proximo = m->inicio;
        m->inicio = i;
    } else {
        m->turma[i].proximo = m->turma[pos_inserir].proximo;
        m->turma[pos_inserir].proximo = i;
    }
    return true;
}

void alocarNo(LISTA_MATRICULA *m, int i) {
    m->turma[i].proximo = m->disponivel;
    m->disponivel = i;
}

bool excluirAluno(LISTA_MATRICULA *m, int matricula_aluno) {
    int i = m->inicio;
    int anterior = -1;

    while (i != -1 && m->turma[i].alun.matricula != matricula_aluno) {
        anterior = i;
        i = m->turma[i].proximo;
    }

    if (i == -1) {
        return false; // Aluno não encontrado
    }

    if (anterior == -1) {
        m->inicio = m->turma[i].proximo;
    } else {
        m->turma[anterior].proximo = m->turma[i].proximo;
    }

    alocarNo(m, i); // Liberar o nó excluído para reutilização

    return true;
}

bool alterarMatricula(LISTA_MATRICULA *m, int matricula_aluno, int nova_matricula) {
    int i = m->inicio;
    while (i != -1 && m->turma[i].alun.matricula != matricula_aluno) {
        i = m->turma[i].proximo;
    }
    if (i == -1) {
        return false; // Aluno não encontrado
    }
    ALUNO aluno_antigo = m->turma[i].alun; // Salvar o aluno antigo

    excluirAluno(m, matricula_aluno);

    ALUNO novo_aluno = {
            .matricula = nova_matricula,
            .nome = aluno_antigo.nome,
            .idade = aluno_antigo.idade
    };

    inserirAluno(m, novo_aluno);

    return true;
}