#ifndef POLINOMIO_H
#define POLINOMIO_H

typedef struct aux {
    int coeficiente;
    int expoente;
    struct aux* proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO* inicio;
} LISTA;

void inicializarLista(LISTA* lista);
void inserirNaLista(LISTA* lista, int coeficiente, int expoente);
void exibirLista(LISTA* lista);
LISTA somaPolinomio(LISTA* P1, LISTA* P2);

#endif // POLINOMIO_H