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
                else raiz = rot_dir_esquerda(raiz);
            }
        }
    }
    raiz->h = maximo(altura(raiz->esquerda), altura(raiz->direita))+1;
    return (raiz);
}

int adicionarAVL (ARVORE *a, char codigo){
    NO *novoNo = malloc(sizeof(NO));
    if (novoNo == NULL) return 0;
    novoNo->chave = codigo;
    novoNo->h = 0;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    a->raiz = inserirAVL(a->raiz, novoNo);
    return 1;
}

int maximo (char v1, char v2){
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
            printf("No esquerda: %c\n", raiz->esquerda->chave);
        } else {
            printf("No esquerda: NULL\n");
        }
        if (raiz->direita != NULL) {
            printf("No direita:  %c\n", raiz->direita->chave);
        } else {
            printf("No direita: NULL\n");
        }
        printf("Codigo: %c\n", raiz->chave);
        listarNOS(raiz->esquerda);
        listarNOS(raiz->direita);
    }
}

void listarArvore (ARVORE *a){
    listarNOS(a->raiz);
}

NO *encontrarNo(NO *raiz, char codigo) {
    if (raiz == NULL || raiz->chave == codigo)
        return raiz;

    if (codigo < raiz->chave)
        return encontrarNo(raiz->esquerda, codigo);
    else
        return encontrarNo(raiz->direita, codigo);
}

NO *encontrarMinimo(NO *raiz) {
    NO *atual = raiz;
    while (atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}
// corrigindo
NO *removerNoAVL(NO *raiz, char codigo) {
    if (raiz == NULL)
        return raiz;

    if (codigo < raiz->chave)
        raiz->esquerda = removerNoAVL(raiz->esquerda, codigo);
    else if (codigo > raiz->chave)
        raiz->direita = removerNoAVL(raiz->direita, codigo);
    else {
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            // NO *filhoSubstituto = raiz->esquerda ? raiz->esquerda : raiz->direita;
            NO* filhoSubstituto;
            if (raiz->esquerda != NULL){
                filhoSubstituto = raiz->esquerda;
                if (filhoSubstituto->direita != NULL) {
                    filhoSubstituto = filhoSubstituto->direita;
                }
            } else {
                filhoSubstituto = raiz->direita;
            }
            free(raiz);
            return filhoSubstituto;
        } else {
            NO *filhoSubstituto = raiz->esquerda;
            while (filhoSubstituto->direita != NULL) {
                filhoSubstituto = filhoSubstituto->direita;
            }
            raiz->chave = filhoSubstituto->chave;
            raiz->esquerda = removerNoAVL(raiz->esquerda, filhoSubstituto->chave);
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

int removerAVL(ARVORE *a, char codigo) {
    if (a->raiz == NULL)
        return 0;

    NO *noParaRemover = encontrarNo(a->raiz, codigo);
    if (noParaRemover == NULL)
        return 0;

    a->raiz = removerNoAVL(a->raiz, codigo);
    return 1;
}

void pre_ordem (NO* raiz) {
    if (!raiz) return;
    printf ("%c ", raiz->chave);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}

void in_ordem (NO* raiz) {
    if (!raiz) return;
    in_ordem(raiz->esquerda);
    printf ("%c ", raiz->chave);
    in_ordem(raiz->direita);
}

void pos_ordem (NO* raiz) {
    if (!raiz) return;
    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    printf ("%c ", raiz->chave);
}

void printArvore(NO *raiz, int nivel) {
    if (raiz != NULL) {
        printf("Nivel %d: ", nivel);
        for (int i = 0; i < nivel; i++) {
            printf("    ");
        }
        printf("%c\n", raiz->chave);

        if (raiz->esquerda != NULL || raiz->direita != NULL) {
            printf("%*sL:", nivel * 4, "");
            printArvore(raiz->esquerda, nivel + 1);

            printf("%*sR:", nivel * 4, "");
            printArvore(raiz->direita, nivel + 1);
        }
    }
}

void visualizarArvore(ARVORE *a) {
    printf("\nAVL:\n");
    printArvore(a->raiz, 0);
}

int numeroNos (NO* raiz) {
    if (!raiz) return 0;
    return (
        numeroNos (raiz->esquerda)
        +1
        +numeroNos (raiz->direita)
    );
}

int numeroFolhas(NO* raiz) {
    if (!raiz) {
        return 0;
    }
    
    if (!raiz->esquerda && !raiz->direita) {
        return 1;  // O nó atual é uma folha
    }
    
    return numeroFolhas(raiz->esquerda) + numeroFolhas(raiz->direita);
}

int numeroNosInternos(NO* raiz) {
    if (!raiz || (!raiz->esquerda && !raiz->direita)) {
        return 0;  // Nó vazio ou folha
    }
    
    return 1 + numeroNosInternos(raiz->esquerda) + numeroNosInternos(raiz->direita);
}

int alturaArvore(NO* raiz) {
    if (!raiz) {
        return -1; // Altura de árvore vazia é -1
    }

    int alturaEsquerda = alturaArvore(raiz->esquerda);
    int alturaDireita = alturaArvore(raiz->direita);

    return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}

NO* buscarMinimo(NO* raiz) {
    while (raiz->esquerda) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

NO* buscarMaximo(NO* raiz) {
    while (raiz->direita) {
        raiz = raiz->direita;
    }
    return raiz;
}

NO* buscarSucessor(NO* raiz, char codigo) {
    if (!raiz) {
        return NULL;
    }

    NO* sucessor = NULL;
    while (raiz) {
        if (codigo < raiz->chave) {
            sucessor = raiz;
            raiz = raiz->esquerda;
        } else if (codigo > raiz->chave) {
            raiz = raiz->direita;
        } else {
            if (raiz->direita) {
                sucessor = buscarMinimo(raiz->direita);
            }
            break;
        }
    }
    return sucessor;
}

NO* buscarAntecessor(NO* raiz, char codigo) {
    if (!raiz) {
        return NULL;
    }

    NO* antecessor = NULL;
    while (raiz) {
        if (codigo > raiz->chave) {
            antecessor = raiz;
            raiz = raiz->direita;
        } else if (codigo < raiz->chave) {
            raiz = raiz->esquerda;
        } else {
            if (raiz->esquerda) {
                antecessor = buscarMaximo(raiz->esquerda);
            }
            break;
        }
    }
    return antecessor;
}

int verificarBalanceamento(NO* raiz) {
    if (!raiz) {
        return 1;
    }

    int alturaEsquerda = alturaArvore(raiz->esquerda);
    int alturaDireita = alturaArvore(raiz->direita);

    if (abs(alturaEsquerda - alturaDireita) <= 1 &&
        verificarBalanceamento(raiz->esquerda) &&
        verificarBalanceamento(raiz->direita)) {
        return 1;
    }

    return 0;
}

void exibirNivel(NO* raiz, int nivelAtual, int nivelDesejado) {
    if (!raiz || nivelAtual > nivelDesejado) {
        return;
    }
    if (nivelAtual == nivelDesejado) {
        printf("%c ", raiz->chave);
    } else {
        exibirNivel(raiz->esquerda, nivelAtual + 1, nivelDesejado);
        exibirNivel(raiz->direita, nivelAtual + 1, nivelDesejado);
    }
}

void exibirNiveis(NO* raiz) {
    int altura = alturaArvore(raiz);
    for (int nivel = 0; nivel <= altura; nivel++) {
        printf("Nivel %d: ", nivel);
        exibirNivel(raiz, 0, nivel);
        printf("\n");
    }
}