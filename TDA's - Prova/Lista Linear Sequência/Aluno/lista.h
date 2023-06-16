#ifndef LISTA_H
#define LISTA_H

#define MAX 100

typedef struct {
    int codigo;
    char *nome;
    int idade;
    int n_filhos;
} ALUNO;

typedef struct {
    int qtd;
    ALUNO dados[MAX];
} LISTA;

LISTA *cria_lista();

void libera_lista(LISTA *li);

int tamanho_lista(LISTA *li);

int lista_cheia(LISTA *li);

int lista_vazia(LISTA *li);

int insere_lista_inicio(LISTA *li, ALUNO student);

int insere_lista_meio(LISTA *li, ALUNO student);

int insere_lista_final(LISTA *li, ALUNO student);

int insere_lista_ordenada(LISTA *li, ALUNO student);

int remove_lista_inicio(LISTA *li);

int remove_lista_meio(LISTA *li);

int remove_lista_fim(LISTA *li);

int remove_lista(LISTA *li, int codigo);

int consulta_lista_pos(LISTA *li, int pos, ALUNO *student);

int consulta_lista_mat(LISTA *li, int mat, ALUNO *student);

int imprimir_elementos(LISTA *li);

int consulta_lista_mat_binaria(LISTA *li, int codigo, ALUNO *student);

int busca_sequencial(LISTA *li, int codigo);

int busca_binaria(LISTA *li, int codigo);

int remove_lista_pos(LISTA *li, int pos);

#endif // LISTA_H
