#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

typedef struct {
    int cod_pac;
    char* nome;
    char* cpf;
    int idade;
} PACIENTE;

typedef struct aux {
    PACIENTE pac;
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
int adicionarAVL (ARVORE *a, PACIENTE p);
int maximo (int v1, int v2);
int altura (NO *raiz);
NO* rot_direita (NO* no_desb);
NO* rot_esquerda (NO* no_desb);
NO* rot_esq_direita (NO* no_desb);
NO* rot_dir_esquerda (NO* no_desb);
void listarNOS(NO *raiz);
void listarArvore (ARVORE *a);
NO *encontrarNo(NO *raiz, int valor);
NO *encontrarMinimo(NO *raiz);
NO *removerNoAVL(NO *raiz, int valor);
int removerAVL(ARVORE *a, int valor);

#endif