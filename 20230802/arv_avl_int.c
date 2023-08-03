#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arv_avl_int.h"

void inicializarArvore (ARVORE *a){
    a->raiz = NULL;
}

NO *inserirAVL (NO *raiz, NO* no){
    if (raiz == NULL) return (no);
    if (raiz->chave > no->chave) {
        raiz->esquerda = inserirAVL(raiz->esquerda, no);
        if ((altura(raiz->esquerda) - altura(raiz->direita)) == 2) {
            if (no->chave < raiz->esquerda->chave) raiz = rot_direita(raiz);
            else raiz = rot_esq_direita(raiz);
        }
    }
    else {
        if (raiz->chave < no->chave) {
            raiz->direita = inserirAVL(raiz->direita, no);
            if ((altura(raiz->direita) - altura(raiz->esquerda)) == 2) {
                if (no->chave > raiz->direita->chave) raiz = rot_esquerda(raiz);
                else raiz = rot_dir_esquerda(raiz); // rot_esq_direita(raiz);
            }
        }
    }
    raiz->h = maximo(altura(raiz->esquerda), altura(raiz->direita))+1;
    return (raiz);
}

bool adicionaAVL (ARVORE *a, int valor){
    NO *novoNo = malloc(sizeof(NO));
    if (novoNo == NULL) return false;
    novoNo->chave = valor;
    novoNo->h = 0;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    a->raiz = inserirAVL(a->raiz, novoNo);
    return true;
}

int maximo (int v1, int v2){
    // return (v1 > v2) ? v1 : v2;
    if (v1 > v2) return v1;
    else return v2;
}

int altura (NO *raiz){
    if (!raiz) return (-1);
    else return (raiz->h);
}

NO *rot_direita (NO *no_desb){
    NO* aux = no_desb->esquerda;
    no_desb->esquerda = aux->direita;
    aux->direita = no_desb;
    no_desb->h = maximo(altura(no_desb->direita), altura(no_desb->esquerda))+1;
    aux->h = maximo(altura(aux->direita), altura(no_desb))+1;
    return (aux);
}

NO *rot_esquerda (NO * no_desb) {
    NO* aux = no_desb->direita;
    no_desb->direita = aux->esquerda;
    aux->esquerda = no_desb;
    no_desb->h = maximo(altura(no_desb->direita), altura(no_desb->esquerda))+1;
    aux->h = maximo(altura(aux->direita), altura(no_desb))+1;
    return (aux);
}

NO *rot_esq_direita (NO *no_desb) {
    no_desb->esquerda = rot_esquerda(no_desb->esquerda);
    return (rot_direita(no_desb));
}

NO *rot_dir_esquerda (NO *no_desb) {
    no_desb->direita = rot_direita(no_desb->direita);
    return (rot_esquerda(no_desb));
}

void listarNOS(NO *raiz) {
    if (raiz != NULL) {
        printf("-----------------------\n");
        if (raiz->esquerda != NULL) {
            printf("No esquerda: %d\n", raiz->esquerda->chave);
        } else {
            printf("No esquerda: NULL\n");
        }
        if (raiz->direita != NULL) {
            printf("No direita:  %d\n", raiz->direita->chave);
        } else {
            printf("No direita: NULL\n");
        }
        printf("Codigo: %d\n", raiz->chave);
        listarNOS(raiz->esquerda);
        listarNOS(raiz->direita);
    }
}

void listarArvore (ARVORE *a){
    listarNOS(a->raiz);
}

void printArvore(NO *raiz, int nivel) {
    if (raiz != NULL) {
        printf("Nivel %d: ", nivel);
        for (int i = 0; i < nivel; i++) {
            printf("    ");
        }
        printf("%d\n", raiz->chave);

        if (raiz->esquerda != NULL || raiz->direita != NULL) {
            printf("%*sL:", nivel * 4, "");
            printArvore(raiz->esquerda, nivel + 1);

            printf("%*sR:", nivel * 4, "");
            printArvore(raiz->direita, nivel + 1);
        }
    }
}

void visualizarArvore(ARVORE *a) {
    printf("\nÁrvore AVL:\n");
    printArvore(a->raiz, 0);
}
