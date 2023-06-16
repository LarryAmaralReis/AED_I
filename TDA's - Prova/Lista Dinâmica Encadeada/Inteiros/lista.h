#ifndef LISTA_H
#define LISTA_H

typedef struct elemento {
    int dados;
    struct elemento *proximo;
} ELEMENTO;

typedef struct elemento *LISTA;

LISTA *cria_lista();
void libera_lista(LISTA *li);
int tamanho_lista(LISTA *li);
int lista_cheia(LISTA *li);
int lista_vazia(LISTA *li);
int insere_lista_inicio(LISTA *li, int value);
int insere_lista_final(LISTA *li, int value);
int insere_lista_ordenada(LISTA *li, int value);
int remove_lista_inicio(LISTA *li);
int remove_lista_final(LISTA *li);
int remove_lista(LISTA *li, int value);
int consulta_lista_pos(LISTA *li, int pos, int *value);
int consulta_lista_valor(LISTA *li, int value, int *pos);
void imprime_lista(LISTA *li);
int elemento_duplicado(LISTA *li, int value);
int busca_sequencial(LISTA *li, int value);

#endif // LISTA_H
