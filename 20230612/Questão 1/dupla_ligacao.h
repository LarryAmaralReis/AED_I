#ifndef DUPLA_LIGACAO_H
#define DUPLA_LIGACAO_H

typedef struct aux {
    int valor;
    struct aux* anterior;
    struct aux* proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO* inicio;
} LISTA;

void inicializarLista(LISTA* lista);
void inserirNaLista(LISTA* lista, int valor);
void removerDaLista(LISTA* lista, ELEMENTO* elemento);
void exibirLista(LISTA* lista);
LISTA criarListaOrdenada(LISTA* L);

#endif // DUPLA_LIGACAO_H