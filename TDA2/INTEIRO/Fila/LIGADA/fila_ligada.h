#ifndef FILA_LIGADA_H
#define FILA_LIGADA_H

typedef struct aux {
    int valor;
    struct aux *proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO *inicio;
    ELEMENTO *fim;
} FILA;

void inicializarFila(FILA *f);
void reinicializarFila(FILA *f);
int inserirValor(FILA *f, int novo_valor);
int inserirValorFlutuante(FILA *f, float novo_valor);
int excluirValor(FILA *f);
int firstValor(FILA *f);
ELEMENTO firstELEMENTO (FILA *f);
int imprimirFila(FILA f);

int maiorValor(FILA *f);
int menorValor(FILA *f);
void inserirMediaValores(FILA *f);
int posicaoPorValor(FILA *f, int valor);
int contarValores(FILA *f);
int removerPorValor(FILA *f, int valor);

#endif
