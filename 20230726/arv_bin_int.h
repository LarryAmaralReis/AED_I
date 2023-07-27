#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct aux{
    int chave;
    struct aux* esquerda;
    struct aux* direita;
} NO;

typedef struct {
    NO* raiz;
} ARVORE;

void inicializarArvore(ARVORE* a);
NO* inserir(NO* raiz, NO* no);
bool adiciona(ARVORE* a, NO* novo);
bool adiciona2(ARVORE* a, int valor);
void listarNOS(NO* raiz);
void listarArvore(ARVORE* a);
NO* contem(NO* raiz, int valor);
NO* buscar(ARVORE* a, int valor);
void per_pre_ordem(NO* raiz);
void per_in_ordem(NO* raiz);
void per_pos_ordem(NO* raiz);
int numeroNos(NO* raiz);

#endif