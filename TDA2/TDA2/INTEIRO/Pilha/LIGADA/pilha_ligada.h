#ifndef PILHA_LIGADA_H
#define PILHA_LIGADA_H

typedef struct aux {
    int valor;
    struct aux *proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO *topo;
} PILHA;

void inicializarPilha (PILHA *p);
void reinicializarPilha (PILHA *p);
int inserirValor (PILHA *p, int novo_valor);
int excluirValor (PILHA *p);
int firstELEMENTO (PILHA *p);
int firstValor (PILHA *p);
int imprimirPilha (PILHA p);

int maiorValor(PILHA *p);
int menorValor(PILHA *p);
float calcularMediaValores(PILHA *p);
int posicaoPorValor(PILHA *p, int valor);
int contarValores(PILHA *p);
int removerPorValor(PILHA *p, int valor);
void removerAteValor(PILHA *p, int valor);

#endif