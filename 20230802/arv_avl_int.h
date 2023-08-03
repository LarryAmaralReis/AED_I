#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

typedef struct aux{
    int chave;
    struct aux* esquerda;
    struct aux* direita;
    int h;
} NO;

typedef struct {
    NO* raiz;
} ARVORE;

void inicializarArvore(ARVORE* a);
NO *inserirAVL (NO *raiz, NO* no);
bool adicionaAVL (ARVORE *a, int valor);
int maximo (int v1, int v2);
int altura (NO *raiz);
NO *rot_direita (NO * no_desb);
NO *rot_esquerda (NO * no_desb);
NO *rot_esq_direita (NO *no_desb);
NO *rot_dir_esquerda (NO *no_desb);
void listarNOS(NO* raiz);
void listarArvore(ARVORE* a);
void printArvore(NO *raiz, int nivel);
void visualizarArvore(ARVORE *a);

#endif