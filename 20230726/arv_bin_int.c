#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arv_bin_int.h"

void inicializarArvore (ARVORE *a){
    a->raiz = NULL;
}

NO *inserir (NO *raiz, NO *no){
    if (raiz == NULL) return (no);
    if (raiz->chave > no->chave) raiz->esquerda = inserir(raiz->esquerda, no);
    else raiz->direita = inserir(raiz->direita, no);
    return (raiz);
}

bool adiciona (ARVORE *a, NO *novo){
    a->raiz = inserir (a->raiz, novo);
    return true;
}

bool adiciona2 (ARVORE *a, int valor){
    NO *novoNo = malloc(sizeof(NO));
    novoNo->chave = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    adiciona(a, novoNo);
    return true;
}

void listarNOS (NO *raiz){
    if (raiz!=NULL){
        printf("-----------------------\n");
        printf("Endereco: %d\n", raiz);
        printf("No esquerda: %d\n", raiz->esquerda);
        printf("No direita: %d\n", raiz->direita);
        printf("Codigo: %d\n", raiz->chave);
        listarNOS(raiz->esquerda);
        listarNOS(raiz->direita);
    }
}

void listarArvore (ARVORE *a){
    listarNOS(a->raiz);
}

NO *contem (NO *raiz, int valor) {
    if (raiz == NULL) return (NULL);
    if (raiz->chave == valor) return (raiz);
    if (raiz->chave > valor) return (contem(raiz->esquerda, valor));
    else return (contem(raiz->direita, valor));
}

NO *buscar (ARVORE *a, int valor){
    return contem (a->raiz, valor);
}

void per_pre_ordem (NO *raiz){
    if (!raiz) return;
    printf("%d ", raiz->chave);
    per_pre_ordem(raiz->esquerda);
    per_pre_ordem(raiz->direita);
}

void per_in_ordem (NO *raiz){
    if (!raiz) return;
    per_in_ordem(raiz->esquerda);
    printf("%d ", raiz->chave);
    per_in_ordem(raiz->direita);
}

void per_pos_ordem (NO *raiz){
    if (!raiz) return;
    per_pos_ordem(raiz->esquerda);
    per_pos_ordem(raiz->direita);
    printf("%d ", raiz->chave);
}

int numeroNos (NO *raiz) {
    if (!raiz) return 0;
    return (
        numeroNos (raiz->esquerda)
        +1
        +numeroNos(raiz->direita)
    );
}