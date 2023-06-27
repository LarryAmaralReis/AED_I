#ifndef AVIAO_H
#define AVIAO_H

#define MAX 100

typedef struct {
    int identificador;
    char nome[50];
    // Adicione outras características do avião aqui, se necessário
} AVIAO;

typedef struct {
    int inicio, final;
    AVIAO dados[MAX];
} FILA;

FILA* cria_Fila();
void libera_Fila(FILA* fi);
int consulta_Fila(FILA* fi, AVIAO *av);
int insere_Fila(FILA* fi, AVIAO av);
int remove_Fila(FILA* fi);
int tamanho_Fila(FILA* fi);
int Fila_cheia(FILA* fi);
int Fila_vazia(FILA* fi);
void imprime_Fila(FILA* fi);

#endif
