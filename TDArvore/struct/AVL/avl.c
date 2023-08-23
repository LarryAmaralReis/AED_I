#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl.h"

void header(int exercicio){
    time_t now;
    time(&now);
    printf("\nAluno: Larry Amaral Reis");
    printf("\nNumero do exercicio: %d", exercicio);
    printf("\nData e hora de entrega: %s", ctime(&now));
} 

void inicializarArvore (ARVORE *a){
    a->raiz = NULL;
}

NO *inserirAVL (NO *raiz, NO* no){
    if (raiz == NULL) return (no);
    if (raiz->pac.cod_pac > no->pac.cod_pac) {
        raiz->esquerda = inserirAVL(raiz->esquerda, no);
        if ((altura(raiz->esquerda) - altura(raiz->direita)) == 2) {
            if (no->pac.cod_pac < raiz->esquerda->pac.cod_pac) raiz = rot_direita(raiz);
            else raiz = rot_esq_direita(raiz);
        }
    }
    else {
        if (raiz->pac.cod_pac < no->pac.cod_pac) {
            raiz->direita = inserirAVL(raiz->direita, no);
            if ((altura(raiz->direita) - altura(raiz->esquerda)) == 2) {
                if (no->pac.cod_pac > raiz->direita->pac.cod_pac) raiz = rot_esquerda(raiz);
                else raiz = rot_dir_esquerda(raiz);
            }
        }
    }
    raiz->h = maximo(altura(raiz->esquerda), altura(raiz->direita))+1;
    return (raiz);
}

int adicionarAVL (ARVORE *a, PACIENTE p){
    NO *novoNo = malloc(sizeof(NO));
    if (novoNo == NULL) return 0;
    novoNo->pac = p;
    novoNo->h = 0;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    a->raiz = inserirAVL(a->raiz, novoNo);
    return 1;
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

NO* rot_direita (NO* no_desb){
    NO* aux = no_desb->esquerda;
    no_desb->esquerda = aux->direita;
    aux->direita = no_desb;
    no_desb->h = maximo(altura(no_desb->direita), altura(no_desb->esquerda))+1;
    aux->h = maximo(altura(aux->direita), altura(no_desb))+1;
    printf("Rotação direita\n");
    return (aux);
}

NO* rot_esquerda (NO* no_desb) {
    NO* aux = no_desb->direita;
    no_desb->direita = aux->esquerda;
    aux->esquerda = no_desb;
    no_desb->h = maximo(altura(no_desb->direita), altura(no_desb->esquerda))+1;
    aux->h = maximo(altura(aux->direita), altura(no_desb))+1;
    printf("Rotação esquerda\n");
    return (aux);
}

NO* rot_esq_direita (NO* no_desb) {
    no_desb->esquerda = rot_esquerda(no_desb->esquerda);
    printf("Rotação esquerda direita\n");
    return (rot_direita(no_desb));
}

NO* rot_dir_esquerda (NO* no_desb) {
    no_desb->direita = rot_direita(no_desb->direita);
    printf("Rotação direita esquerda\n");
    return (rot_esquerda(no_desb));
}

void listarNOS(NO *raiz) {
    if (raiz != NULL) {
        printf("-----------------------\n");
        if (raiz->esquerda != NULL) {
            printf("No esquerda: %d\n", raiz->esquerda->pac.cod_pac);
        } else {
            printf("No esquerda: NULL\n");
        }
        if (raiz->direita != NULL) {
            printf("No direita:  %d\n", raiz->direita->pac.cod_pac);
        } else {
            printf("No direita: NULL\n");
        }
        printf("Codigo: %d\n", raiz->pac.cod_pac);
        listarNOS(raiz->esquerda);
        listarNOS(raiz->direita);
    }
}

void listarArvore (ARVORE *a){
    listarNOS(a->raiz);
}

NO *encontrarNo(NO *raiz, int valor) {
    if (raiz == NULL || raiz->pac.cod_pac == valor)
        return raiz;

    if (valor < raiz->pac.cod_pac)
        return encontrarNo(raiz->esquerda, valor);
    else
        return encontrarNo(raiz->direita, valor);
}

NO *encontrarMinimo(NO *raiz) {
    NO *atual = raiz;
    while (atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}

NO *removerNoAVL(NO *raiz, int valor) {
    if (raiz == NULL)
        return raiz;

    if (valor < raiz->pac.cod_pac)
        raiz->esquerda = removerNoAVL(raiz->esquerda, valor);
    else if (valor > raiz->pac.cod_pac)
        raiz->direita = removerNoAVL(raiz->direita, valor);
    else {
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            NO *temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
            free(raiz);
            return temp;
        } else {
            NO *temp = encontrarMinimo(raiz->direita);
            raiz->pac.cod_pac = temp->pac.cod_pac;
            raiz->direita = removerNoAVL(raiz->direita, temp->pac.cod_pac);
        }
    }

    raiz->h = maximo(altura(raiz->esquerda), altura(raiz->direita)) + 1;

    int balance = altura(raiz->esquerda) - altura(raiz->direita);

    if (balance > 1 && altura(raiz->esquerda->esquerda) >= altura(raiz->esquerda->direita))
        return rot_direita(raiz);

    if (balance > 1 && altura(raiz->esquerda->esquerda) < altura(raiz->esquerda->direita)) {
        raiz->esquerda = rot_esquerda(raiz->esquerda);
        return rot_direita(raiz);
    }

    if (balance < -1 && altura(raiz->direita->direita) >= altura(raiz->direita->esquerda))
        return rot_esquerda(raiz);

    if (balance < -1 && altura(raiz->direita->direita) < altura(raiz->direita->esquerda)) {
        raiz->direita = rot_direita(raiz->direita);
        return rot_esquerda(raiz);
    }

    return raiz;
}

int removerAVL(ARVORE *a, int valor) {
    if (a->raiz == NULL)
        return 0;

    NO *noParaRemover = encontrarNo(a->raiz, valor);
    if (noParaRemover == NULL)
        return 0;

    a->raiz = removerNoAVL(a->raiz, valor);
    return 1;
}

void printArvore(NO *raiz, int nivel) {
    if (raiz != NULL) {
        printf("Nivel %d: ", nivel);
        for (int i = 0; i < nivel; i++) {
            printf("    ");
        }
        printf("%d\n", raiz->pac.cod_pac);

        if (raiz->esquerda != NULL || raiz->direita != NULL) {
            printf("%*sL:", nivel * 4, "");
            printArvore(raiz->esquerda, nivel + 1);

            printf("%*sR:", nivel * 4, "");
            printArvore(raiz->direita, nivel + 1);
        }
    }
}

void visualizarArvore(ARVORE *a) {
    printf("\nArvore Binaria de Busca:\n");
    printArvore(a->raiz, 0);
}
