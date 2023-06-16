#ifndef LISTA_H
#define LISTA_H

#define MAX 100

typedef struct {
    int elemento;
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
int insere_lista_inicio(LISTA *li, int elemento);
int insere_lista_meio(LISTA *li, int elemento);
int insere_lista_final(LISTA *li, int elemento);
int insere_lista_ordenada(LISTA *li, int elemento);
int remove_lista_inicio(LISTA *li);
int remove_lista_meio(LISTA *li);
int remove_lista_final(LISTA *li);
int remove_lista(LISTA *li, int elemento);
int remove_lista_pos(LISTA *li, int pos);
int consulta_lista_pos(LISTA *li, int pos, int *elemento);
int consulta_lista_elem(LISTA *li, int elem, int *posicao);
void imprimir_lista(LISTA *li);
int busca_sequencial(LISTA *li, int elemento);
int remove_maior_elemento(LISTA *li, int *elemento);

#endif
