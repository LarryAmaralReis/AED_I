#ifndef DEQUE_LIGADO_H
#define DEQUE_LIGADO_H

typedef struct aux {
    int valor;
    struct aux *anterior;
    struct aux *proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO *cabeca;
} DEQUE;

void inicilizarDeque (DEQUE *d);
void reinicializarDeque (DEQUE *d);
void mostrarDeque (DEQUE *d);
int inserirValorFim (DEQUE *d, int novo_valor);
int inserirValorInicio (DEQUE *d, int novo_valor);
int excluirValorInicio (DEQUE *d);
int excluirValorFim (DEQUE *d);
int getValorInicio(DEQUE *d);
int getValorFim(DEQUE *d);

int getValorMaior(DEQUE *d);
int getValorMenor(DEQUE *d);
void calcularMediaInserirInicio(DEQUE *d);
int posicaoPorValor(DEQUE *d, int valor);
int contarValores(DEQUE *d);
int excluirValorPorCodigo(DEQUE *d, int codigo);
void removerAteValor(DEQUE *d, int valor);


#endif