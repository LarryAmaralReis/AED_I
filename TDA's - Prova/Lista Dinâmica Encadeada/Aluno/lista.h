#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int codigo;
    char *nome;
    int idade;
    int n_filhos;
} ALUNO;

typedef struct elemento {
    ALUNO dados;
    struct elemento *proximo;
} ELEMENTO;

typedef struct elemento *LISTA;

LISTA *cria_lista();
void libera_lista(LISTA *li);
int tamanho_lista(LISTA *li);
int lista_cheia(LISTA *li);
int lista_vazia(LISTA *li);
int insere_lista_inicio(LISTA *li, ALUNO student);
int insere_lista_final(LISTA *li, ALUNO student);
int insere_lista_ordenada(LISTA *li, ALUNO student);
int remove_lista_inicio(LISTA *li);
int remove_lista_final(LISTA *li);
int remove_lista(LISTA *li, int codigo);
int consulta_lista_pos(LISTA *li, int pos, ALUNO *student);
int consulta_lista_codigo(LISTA *li, int codigo, ALUNO *student);
void imprime_lista(LISTA *li);
int busca_sequencial(LISTA *li, int codigo);

#endif // LISTA_H
