#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct NO{
    char chave;
    struct NO* esquerda;
    struct NO* direita;
} NO;

typedef struct {
    NO* raiz;
} ARVORE;

typedef struct NoPilha {
    NO *chave;
    struct NoPilha *proximo;
} NoPilha;

typedef struct {
    NoPilha *topo;
} PILHA;

//Arvore
void inicializarArvore (ARVORE* a);
NO* inserir (NO* raiz, NO* no);
bool adiciona_aux(ARVORE* a, NO* novo);
bool adiciona (ARVORE* a, char valor);
void pre_ordem (NO* raiz);
void prefixa (ARVORE *a);
void in_ordem (NO* raiz);
void infixa(ARVORE *a);
void pos_ordem (NO* raiz);
void posfixa (ARVORE *a);
//Pilha
void inicializarPilha (PILHA *p);
int pilhaVazia (PILHA *p);
int push (PILHA *p, NO *nova_chave);
int pop (PILHA *p);
NO *peek (PILHA *p);
bool ehOperador (char ch);
bool ehOperando (char ch);
bool precedencia (char ch);
NO* criarNo (char valor);
ARVORE construirArvore (char *expressao);
int resultadoArvore (ARVORE *a);
int resultadoArvoreAux (NO* raiz);

#endif