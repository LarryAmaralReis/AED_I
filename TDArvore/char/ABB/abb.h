#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct aux {
    char chave;
    struct aux *esquerda;
    struct aux *direita;
} NO;

typedef struct {
    NO *raiz;
} ARVORE;

void header(int exercicio);
void inicializarArvore (ARVORE *a);
NO *inserir (NO* raiz, NO* no);
int adicionarAux (ARVORE *a, NO* novo);
int adicionar (ARVORE *a, char codigo);
void listarNos (NO* raiz);
void listarArvore (ARVORE *a);
NO* contem (NO* raiz, char codigo);
NO* buscar (ARVORE* a, char codigo);
int numeroNos (NO* raiz);
NO* buscarNo (NO* raiz, char codigo, NO** pai);
int excluirNo (ARVORE* a, char codigo);
void pre_ordem (NO* raiz);
void in_ordem (NO* raiz);
void pos_ordem (NO* raiz);
void printArvore(NO *raiz, int nivel);
void visualizarArvore(ARVORE *a);

int numeroFolhas(NO* raiz);
int numeroNosInternos(NO* raiz);
int alturaArvore(NO* raiz);
NO* buscarMinimo(NO* raiz);
NO* buscarMaximo(NO* raiz);
NO* buscarSucessor(NO* raiz, char codigo);
NO* buscarAntecessor(NO* raiz, char codigo);
int verificarBalanceamento(NO* raiz);
void exibirNivel(NO* raiz, int nivelAtual, int nivelDesejado);
int verificarArvoreBinaria(NO* raiz, int min, int max);
NO* encontrarPai(NO* raiz, char chave);
NO* encontrarNo(NO* raiz, char chave);
NO* encontrarFilhoMaior(NO* raiz, char chave);
NO* encontrarFilhoMenor(NO* raiz, char chave);

#endif