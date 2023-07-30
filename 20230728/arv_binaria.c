#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "arv_binaria.h"

void inicializarArvore (ARVORE *a){
    a->raiz = NULL;
}

NO *inserir (NO *raiz, NO *no){
    if (raiz == NULL) return no;
    if (raiz->esquerda == NULL) raiz->esquerda = inserir(raiz->esquerda, no);
    else raiz->direita = inserir(raiz->direita, no);
    return raiz;
}

bool adiciona_aux (ARVORE *a, NO *novo){
    a->raiz = inserir (a->raiz, novo);
    return true;
}

bool adiciona (ARVORE* a, char valor) {
    NO* novoNo = malloc(sizeof(NO));
    novoNo->chave = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    adiciona_aux(a, novoNo);
    return true;
}

void pre_ordem (NO *raiz){
    if (!raiz) return;
    printf("%c ", raiz->chave);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}

void prefixa (ARVORE *a){
    pre_ordem(a->raiz);
    printf("\n");
}

void in_ordem(NO *raiz) {
    if (raiz != NULL) {
        if (raiz->esquerda != NULL && raiz->direita != NULL && ehOperador(raiz->chave)) {
            printf("(");
            in_ordem(raiz->esquerda);
            printf("%c", raiz->chave);
            in_ordem(raiz->direita);
            printf(")");
        } else {
            printf("%c", raiz->chave);
        }
    }
}

void infixa(ARVORE *a) {
    in_ordem(a->raiz);
    printf("\n");
}

void pos_ordem (NO *raiz){
    if (!raiz) return;
    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    printf("%c ", raiz->chave);
}

void posfixa (ARVORE *a){
    pos_ordem (a->raiz);
    printf("\n");
}

void inicializarPilha (PILHA *p){
    p->topo = NULL;
}

int pilhaVazia (PILHA *p) {
    return p->topo == NULL;
}

int push (PILHA *p, NO *nova_chave){
    NoPilha *i = malloc (sizeof(NoPilha));
    if (i == NULL) return 0;
    i->chave = nova_chave;
    i->proximo = p->topo;
    p->topo = i;
    return 1;
}

int pop (PILHA *p){
    if (p->topo == NULL) return 0;
    NoPilha *i = p->topo;
    p->topo = p->topo->proximo;
    free(i);
    return 1;
}

NO *peek(PILHA *p){
    if(pilhaVazia(p)) return NULL;
    return p->topo->chave;
}

bool ehOperador(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

bool ehOperando(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

bool precedencia(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

NO* criarNo(char valor) {
    NO* novoNo = malloc(sizeof(NO));
    novoNo->chave = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

ARVORE construirArvore(char *expressao) {
    PILHA operadores;
    PILHA operandos;
    inicializarPilha(&operadores);
    inicializarPilha(&operandos);

    int tamanho = strlen(expressao);
    for (int i = 0; i < tamanho; i++) {
        char ch = expressao[i];
        if (ch == ' ')
            continue;
        else if (ehOperando(ch)) {
            NO* novoNo = criarNo(ch);
            push(&operandos, novoNo);
        } else if (ch == '(') {
            push(&operadores, criarNo(ch));
        } else if (ch == ')') {
            while (!pilhaVazia(&operadores) && peek(&operadores)->chave != '(') {
                NO* operador = peek(&operadores);
                pop(&operadores);

                NO* direita = peek(&operandos);
                pop(&operandos);

                NO* esquerda = peek(&operandos);
                pop(&operandos);

                operador->esquerda = esquerda;
                operador->direita = direita;

                push(&operandos, operador);
            }
            pop(&operadores);
        } else { // Operator
            while (!pilhaVazia(&operadores) && precedencia(ch) <= precedencia(peek(&operadores)->chave)) {
                NO* operador = peek(&operadores);
                pop(&operadores);

                NO* direita = peek(&operandos);
                pop(&operandos);

                NO* esquerda = peek(&operandos);
                pop(&operandos);

                operador->esquerda = esquerda;
                operador->direita = direita;

                push(&operandos, operador);
            }
            push(&operadores, criarNo(ch));
        }
    }

    while (!pilhaVazia(&operadores)) {
        NO* operador = peek(&operadores);
        pop(&operadores);

        NO* direita = peek(&operandos);
        pop(&operandos);

        NO* esquerda = peek(&operandos);
        pop(&operandos);

        operador->esquerda = esquerda;
        operador->direita = direita;

        push(&operandos, operador);
    }

    ARVORE minhaArvore;
    minhaArvore.raiz = peek(&operandos);
    return minhaArvore;
}

int resultadoArvore (ARVORE *a){ 
    return resultadoArvoreAux(a->raiz);
}

int resultadoArvoreAux (NO* raiz) {
    if (!raiz) return 0;
    
    if (ehOperando(raiz->chave)) return raiz->chave;

    int direita = resultadoArvoreAux (raiz->direita);
    int esquerda = resultadoArvoreAux (raiz->esquerda);

    switch (raiz->chave) {
        case '+':
            return esquerda + direita;
        case '-':
            return esquerda - direita;
        case '*':
            return esquerda * direita;
        case '/':
            return esquerda / direita;
        default:
            return 0;
    }
}

