#ifndef AVIAO_H
#define AVIAO_H

typedef struct {
    int identificador;
    char nome[50];
} AVIAO;

typedef struct {
    AVIAO *dados;
    int tamanho;
    int capacidade;
} PILHA;

PILHA* cria_Pilha(int capacidade);
void libera_Pilha(PILHA *pilha);
int tamanho_Pilha(PILHA *pilha);
int Pilha_vazia(PILHA *pilha);
int Pilha_cheia(PILHA *pilha);
int insere_Pilha(PILHA *pilha, AVIAO aviao);
int remove_Pilha(PILHA *pilha);
void listaAvioes(PILHA *pilha);
void listaCaracteristicasPrimeiroAviao(PILHA *pilha);
void removeAviaoPorPosicao(PILHA *pilha, int posicao);

#endif
