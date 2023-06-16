#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int matricula;
    char nome[30];
    float n1, n2, n3;
} ALUNO;

typedef struct elemento {
    ALUNO dados;
    struct elemento *proximo;
} ELEMENTO;

struct descritor{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

typedef struct descritor LISTA;

LISTA *cria_lista();
void libera_lista(LISTA *li);
int insere_lista_final(LISTA *li, ALUNO student);
int insere_lista_inicio(LISTA *li, ALUNO student);
int remove_lista_inicio(LISTA *li);
int remove_lista_final(LISTA *li);
int tamanho_lista(LISTA *li);
int lista_vazia(LISTA *li);
int lista_cheia(LISTA *li);
int consulta_lista_mat(LISTA *li, int matricula, ALUNO *student);
int consulta_lista_pos(LISTA *li, int posicao, ALUNO *student);
void imprime_lista(LISTA * li);

#endif // LISTA_H