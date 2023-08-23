#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

typedef struct aux {
    char chave;
    struct aux* esquerda;
    struct aux* direita;
    int h;
} NO;

typedef struct {
    NO* raiz;
} ARVORE;

void header(int exercicio);
void inicializarArvore (ARVORE *a);
NO *inserirAVL (NO *raiz, NO* no);
int adicionarAVL (ARVORE *a, char codigo);
int maximo (char v1, char v2);
int altura (NO *raiz);
NO* rot_direita (NO* no_desb);
NO* rot_esquerda (NO* no_desb);
NO* rot_esq_direita (NO* no_desb);
NO* rot_dir_esquerda (NO* no_desb);
void listarNOS(NO *raiz);
void listarArvore (ARVORE *a);
NO* encontrarNo(NO *raiz, char codigo);
NO* encontrarMinimo(NO *raiz);
NO* removerNoAVL(NO *raiz, char codigo);
int removerAVL(ARVORE *a, char codigo);
void pre_ordem (NO* raiz);
void in_ordem (NO* raiz);
void pos_ordem (NO* raiz);
void printArvore(NO *raiz, int nivel);
void visualizarArvore(ARVORE *a);
int numeroNos (NO* raiz);
int numeroFolhas(NO* raiz);
int numeroNosInternos(NO* raiz);
int alturaArvore(NO* raiz);
NO* buscarMinimo(NO* raiz);
NO* buscarMaximo(NO* raiz);
NO* buscarSucessor(NO* raiz, char codigo);
NO* buscarAntecessor(NO* raiz, char codigo);
int verificarBalanceamento(NO* raiz);
void exibirNivel(NO* raiz, int nivelAtual, int nivelDesejado);
void exibirNiveis(NO* raiz);

#endif