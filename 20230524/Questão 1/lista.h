#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int *vetor;
    int tam_vetor;
} LISTA;

void criarLista(LISTA *l, int tam_vetor);
void liberaLista(LISTA *l);
void inserirElementos(LISTA *l);
void inserirElementosOrdenados(LISTA *l);
void imprimirLista(LISTA *l);
int buscarElementoSequencial(LISTA *l, int elemento);
int buscarElementoSequencialOrdenado(LISTA *l, int elemento);
int buscarElementoBinarioIterativo(LISTA *l, int elemento);
int buscarElementoBinarioRecursivo(LISTA *l, int elemento, int primeiro, int ultimo);
void imprimirListaRecursiva(LISTA *l);
int buscarMaiorElementoIterativo(LISTA *l);
int buscarMaiorElementoRecursivo(LISTA *l, int indice);
int buscarMenorElementoIterativo(LISTA *l);
int buscarMenorElementoRecursivo(LISTA *l, int indice);
int somaIterativa(LISTA *l);
int somaRecursiva(LISTA *l, int indice);
long long int produtoIterativo(LISTA *l);
long long int produtoRecursivo(LISTA *l, int indice);

#endif //LISTA_H