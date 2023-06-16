#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

LISTA *cria_lista() {
    LISTA *li = (LISTA *)malloc(sizeof(LISTA));
    if (li != NULL) {
        li->inicio = -1;
        li->disponivel = 0;
    }
    return li;
}

void libera_lista(LISTA *li) {
    free(li);
}

int tamanho_lista(LISTA *li) {
    if (li == NULL) return -1;
    int tamanho = 0;
    int prox = li->inicio;
    while (prox != -1) {
        tamanho++;
        prox = li->dados[prox].proximo;
    }
    return tamanho;
}

int lista_cheia(LISTA *li) {
    if (li == NULL) return -1;
    return li->disponivel == MAX;
}

int lista_vazia(LISTA *li) {
    if (li == NULL) return -1;
    return li->inicio == -1;
}

int insere_lista_inicio(LISTA *li, ALUNO aluno) {
    if (li == NULL || lista_cheia(li)) return 0;

    int posicao = li->disponivel;
    li->dados[posicao].student = aluno;
    li->disponivel++;

    li->dados[posicao].proximo = li->inicio;
    li->inicio = posicao;

    return 1;
}

int insere_lista_meio(LISTA *li, ALUNO aluno) {
    if (li == NULL || lista_cheia(li)) return 0;

    int posicao = li->disponivel;
    li->dados[posicao].student = aluno;
    li->disponivel++;

    int anterior = -1;
    int atual = li->inicio;

    while (atual != -1 && li->dados[atual].student.codigo < aluno.codigo) {
        anterior = atual;
        atual = li->dados[atual].proximo;
    }

    if (anterior == -1) {
        li->dados[posicao].proximo = li->inicio;
        li->inicio = posicao;
    } else {
        li->dados[posicao].proximo = li->dados[anterior].proximo;
        li->dados[anterior].proximo = posicao;
    }

    return 1;
}

int insere_lista_final(LISTA *li, ALUNO aluno) {
    if (li == NULL || lista_cheia(li)) return 0;

    int posicao = li->disponivel;
    li->dados[posicao].student = aluno;
    li->disponivel++;

    li->dados[posicao].proximo = -1;

    if (li->inicio == -1) {
        li->inicio = posicao;
    } else {
        int atual = li->inicio;
        while (li->dados[atual].proximo != -1) {
            atual = li->dados[atual].proximo;
        }
        li->dados[atual].proximo = posicao;
    }

    return 1;
}

int insere_lista_ordenada(LISTA *li, ALUNO aluno) {
    if (li == NULL || lista_cheia(li)) return 0;

    int posicao = li->disponivel;
    li->dados[posicao].student = aluno;
    li->disponivel++;

    int anterior = -1;
    int atual = li->inicio;

    while (atual != -1 && li->dados[atual].student.codigo < aluno.codigo) {
        anterior = atual;
        atual = li->dados[atual].proximo;
    }

    if (anterior == -1) {
        li->dados[posicao].proximo = li->inicio;
        li->inicio = posicao;
    } else {
        li->dados[posicao].proximo = li->dados[anterior].proximo;
        li->dados[anterior].proximo = posicao;
    }

    return 1;
}

int remove_lista_inicio(LISTA *li) {
    if (li == NULL || lista_vazia(li)) return 0;

    int posicao = li->inicio;
    li->inicio = li->dados[posicao].proximo;
    li->dados[posicao].proximo = li->disponivel;
    li->disponivel--;

    return 1;
}

int remove_lista_meio(LISTA *li) {
    if (li == NULL || lista_vazia(li)) return 0;

    int codigo;
    printf("Digite o codigo do aluno a ser removido: ");
    scanf("%d", &codigo);

    int anterior = -1;
    int atual = li->inicio;

    while (atual != -1 && li->dados[atual].student.codigo != codigo) {
        anterior = atual;
        atual = li->dados[atual].proximo;
    }

    if (atual == -1) {
        printf("Aluno nao encontrado.\n");
        return 0;
    }

    if (anterior == -1) {
        li->inicio = li->dados[atual].proximo;
    } else {
        li->dados[anterior].proximo = li->dados[atual].proximo;
    }

    li->dados[atual].proximo = li->disponivel;
    li->disponivel--;

    return 1;
}

int remove_lista_final(LISTA *li) {
    if (li == NULL || lista_vazia(li)) return 0;

    int anterior = -1;
    int atual = li->inicio;

    while (atual != -1 && li->dados[atual].proximo != -1) {
        anterior = atual;
        atual = li->dados[atual].proximo;
    }

    if (anterior == -1) {
        li->inicio = -1;
    } else {
        li->dados[anterior].proximo = -1;
    }

    li->dados[atual].proximo = li->disponivel;
    li->disponivel--;

    return 1;
}

int remove_lista(LISTA *li, int codigo) {
    if (li == NULL || lista_vazia(li)) return 0;

    int anterior = -1;
    int atual = li->inicio;

    while (atual != -1 && li->dados[atual].student.codigo != codigo) {
        anterior = atual;
        atual = li->dados[atual].proximo;
    }

    if (atual == -1) {
        printf("Aluno nao encontrado.\n");
        return 0;
    }

    if (anterior == -1) {
        li->inicio = li->dados[atual].proximo;
    } else {
        li->dados[anterior].proximo = li->dados[atual].proximo;
    }

    li->dados[atual].proximo = li->disponivel;
    li->disponivel--;

    return 1;
}

int remove_lista_pos(LISTA *li, int pos) {
    if (li == NULL || lista_vazia(li) || pos <= 0 || pos > tamanho_lista(li)) return 0;

    int anterior = -1;
    int atual = li->inicio;
    int cont = 1;

    while (atual != -1 && cont < pos) {
        anterior = atual;
        atual = li->dados[atual].proximo;
        cont++;
    }

    if (atual == -1) {
        printf("Posicao invalida.\n");
        return 0;
    }

    if (anterior == -1) {
        li->inicio = li->dados[atual].proximo;
    } else {
        li->dados[anterior].proximo = li->dados[atual].proximo;
    }

    li->dados[atual].proximo = li->disponivel;
    li->disponivel--;

    return 1;
}

int consulta_lista_pos(LISTA *li, int pos, ALUNO *aluno) {
    if (li == NULL || lista_vazia(li) || pos <= 0 || pos > tamanho_lista(li)) return 0;

    int atual = li->inicio;
    int cont = 1;

    while (atual != -1 && cont < pos) {
        atual = li->dados[atual].proximo;
        cont++;
    }

    if (atual == -1) {
        printf("Posição inválida.\n");
        return 0;
    }

    *aluno = li->dados[atual].student;

    return 1;
}

int consulta_lista_codigo(LISTA *li, int codigo, int *posicao) {
    if (li == NULL || lista_vazia(li)) return 0;

    int atual = li->inicio;
    int cont = 1;

    while (atual != -1 && li->dados[atual].student.codigo != codigo) {
        atual = li->dados[atual].proximo;
        cont++;
    }

    if (atual == -1) {
        printf("Aluno nao encontrado.\n");
        return 0;
    }

    *posicao = cont;

    return 1;
}

void imprimir_lista(LISTA *li) {
    if (li == NULL || lista_vazia(li)) {
        printf("Lista vazia.\n");
        return;
    }

    int atual = li->inicio;

    while (atual != -1) {
        printf("Codigo: %d\n", li->dados[atual].student.codigo);
        printf("Nome: %s\n", li->dados[atual].student.nome);
        printf("Idade: %d\n", li->dados[atual].student.idade);
        printf("Numero de filhos: %d\n\n", li->dados[atual].student.n_filhos);
        atual = li->dados[atual].proximo;
    }
}

int busca_sequencial(LISTA *li, int codigo) {
    if (li == NULL || lista_vazia(li)) return -1;

    int atual = li->inicio;
    int pos = 1;

    while (atual != -1 && li->dados[atual].student.codigo != codigo) {
        atual = li->dados[atual].proximo;
        pos++;
    }

    if (atual == -1) return -1;

    return pos;
}

int aluno_existe(LISTA *li, int codigo) {
    if (li == NULL || lista_vazia(li)) return 0;

    int atual = li->inicio;

    while (atual != -1) {
        if (li->dados[atual].student.codigo == codigo) {
            return 1; // Aluno encontrado
        }
        atual = li->dados[atual].proximo;
    }

    return 0; // Nenhum aluno encontrado
}

int verifica_aluno_duplicado(LISTA *li, int codigo) {
    if (li == NULL || lista_vazia(li)) return 0;

    int atual = li->inicio;
    int contador = 0;

    while (atual != -1) {
        if (li->dados[atual].student.codigo == codigo) {
            contador++;

            if (contador >= 2) {
                return 1; // Mais de um aluno com o mesmo código encontrado
            }
        }

        atual = li->dados[atual].proximo;
    }

    return 0; // Nenhum aluno duplicado encontrado
}

LISTA* alunos_maior_idade(LISTA* li) {
    LISTA* alunos_maior = cria_lista();
    ALUNO aluno_maior;
    int maior_idade = -1;

    if (li == NULL || lista_vazia(li)) {
        printf("Lista vazia.\n");
        return alunos_maior;
    }

    int atual = li->inicio;

    while (atual != -1) {
        if (li->dados[atual].student.idade > maior_idade) {
            maior_idade = li->dados[atual].student.idade;
            aluno_maior = li->dados[atual].student;
        } else if (li->dados[atual].student.idade == maior_idade) {
            insere_lista_final(alunos_maior, li->dados[atual].student);
        }

        atual = li->dados[atual].proximo;
    }

    if (maior_idade != -1) {
        insere_lista_final(alunos_maior, aluno_maior);
    }

    return alunos_maior;
}


