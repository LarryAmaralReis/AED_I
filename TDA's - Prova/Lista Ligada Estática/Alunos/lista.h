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
    ALUNO student;
    int proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO dados[MAX];
    int inicio;
    int disponivel;
} LISTA;

LISTA *cria_lista();
void libera_lista(LISTA *li);
int tamanho_lista(LISTA *li);
int lista_cheia(LISTA *li);
int lista_vazia(LISTA *li);
int insere_lista_inicio(LISTA *li, ALUNO aluno);
int insere_lista_meio(LISTA *li, ALUNO aluno);
int insere_lista_final(LISTA *li, ALUNO aluno);
int insere_lista_ordenada(LISTA *li, ALUNO aluno);
int remove_lista_inicio(LISTA *li);
int remove_lista_meio(LISTA *li);
int remove_lista_final(LISTA *li);
int remove_lista(LISTA *li, int codigo);
int remove_lista_pos(LISTA *li, int pos);
int consulta_lista_pos(LISTA *li, int pos, ALUNO *aluno);
int consulta_lista_codigo(LISTA *li, int codigo, int *posicao);
void imprimir_lista(LISTA *li);
int busca_sequencial(LISTA *li, int codigo);
int aluno_existe(LISTA *li, int codigo);
int verifica_aluno_duplicado(LISTA *li, int codigo);
LISTA* alunos_maior_idade(LISTA* li);

#endif
