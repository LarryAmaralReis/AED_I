#include "abb.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void header(int exercicio){
    time_t now;
    time(&now);
    printf("\nAluno: Larry Amaral Reis");
    printf("\nNumero do exercicio: %d", exercicio);
    printf("\nData e hora de entrega: %s", ctime(&now));
} 

void inicializarArvore (ARVORE *a) {
    a->raiz = NULL;
}

NO *inserir (NO* raiz, NO* no) {
    if (raiz == NULL) return (no);
    if (raiz->chave > no->chave) raiz->esquerda = inserir(raiz->esquerda, no);
    else raiz->direita = inserir(raiz->direita, no);
    return (raiz);
}

int adicionarAux (ARVORE *a, NO* novo) {
    a->raiz = inserir (a->raiz, novo);
    return 1;
}

int adicionar (ARVORE *a, int codigo) {
    NO* novoNo = malloc(sizeof(NO));
    if (novoNo == NULL) return 0;
    novoNo->chave = codigo;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    adicionarAux (a, novoNo);
    return 1;
}

void listarNos (NO* raiz) {
    if (raiz != NULL) {
        printf("----------------------\n");
        printf("Endereco: %d\n", raiz);
        printf("No esquerdo: %d\n", raiz->esquerda);
        printf("No direito: %d\n", raiz->direita);
        printf("Codigo: %d\n", raiz->chave);
        listarNos(raiz->esquerda);
        listarNos(raiz->direita);
    }
}

void listarArvore (ARVORE *a) {
    listarNos (a->raiz);
}

NO* contem (NO* raiz, int codigo) {
    if (raiz == NULL) return NULL;
    if (raiz->chave == codigo) return raiz;
    if (raiz->chave > codigo) return contem(raiz->esquerda, codigo);
    else return contem(raiz->direita, codigo);
}

NO* buscar (ARVORE* a, int codigo) {
    return contem (a->raiz, codigo);
}

int numeroNos (NO* raiz) {
    if (!raiz) return 0;
    return (
        numeroNos (raiz->esquerda)
        +1
        +numeroNos (raiz->direita)
    );
}

NO* buscarNo (NO* raiz, int codigo, NO** pai) {
    NO* atual = raiz;
    *pai = NULL;
    //printf("Pai: %d", pai);
    while (atual) {
        if (atual->chave == codigo) return atual;
        *pai = atual;
        if (codigo < atual->chave) atual = atual->esquerda;
        else atual = atual->direita;
    }
    return NULL;
}

int excluirNo (ARVORE *a, int codigo) {
    NO* no;
    NO* pai;
    NO* no_subs;
    NO* pai_subs;
    no = buscarNo (a->raiz, codigo, &pai);
    if (no == NULL) return 0;
    if (!no->esquerda || !no->direita) {
        if (!no->esquerda) no_subs = no->direita;
        else no_subs = no->esquerda;
    } else {
        pai_subs = no;
        no_subs = no->esquerda;
        while (no_subs->direita) {
            pai_subs = no_subs;
            no_subs = no_subs->direita;
        }
        if (pai_subs != no) {
            pai_subs->direita = no_subs->esquerda;
            no_subs->esquerda = no->esquerda;
        }
        no_subs->direita = no->direita;
    }
    if (!pai) {
        a->raiz = no_subs;
        free(no);
        return 1;
    }
    if (codigo < pai->chave) pai->esquerda = no_subs;
    else pai->direita = no_subs;
    free(no);
    return 1;
}

void pre_ordem (NO* raiz) {
    if (!raiz) return;
    printf ("%d ", raiz->chave);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}

void in_ordem (NO* raiz) {
    if (!raiz) return;
    in_ordem(raiz->esquerda);
    printf ("%d ", raiz->chave);
    in_ordem(raiz->direita);
}

void pos_ordem (NO* raiz) {
    if (!raiz) return;
    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    printf ("%d ", raiz->chave);
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
    printf("\nArvore Binaria de Busca:\n");
    printArvore(a->raiz, 0);
}

// EXTRAS

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

NO* buscarSucessor(NO* raiz, int chave) {
    if (!raiz) {
        return NULL;
    }

    NO* sucessor = NULL;
    while (raiz) {
        if (chave < raiz->chave) {
            sucessor = raiz;
            raiz = raiz->esquerda;
        } else if (chave > raiz->chave) {
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

NO* buscarAntecessor(NO* raiz, int chave) {
    if (!raiz) {
        return NULL;
    }

    NO* antecessor = NULL;
    while (raiz) {
        if (chave > raiz->chave) {
            antecessor = raiz;
            raiz = raiz->direita;
        } else if (chave < raiz->chave) {
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
        printf("%d ", raiz->chave);
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


int verificarArvoreBinaria(NO* raiz, int min, int max) {
    if (!raiz) {
        return 1;
    }

    if (raiz->chave < min || raiz->chave > max) {
        return 0;
    }

    return (verificarArvoreBinaria(raiz->esquerda, min, raiz->chave - 1) &&
            verificarArvoreBinaria(raiz->direita, raiz->chave + 1, max));
}

int nivelNo(NO* raiz, int chave, int nivelAtual) {
    if (!raiz) {
        return -1;
    }

    if (raiz->chave == chave) {
        return nivelAtual;
    }

    if (chave < raiz->chave) {
        return nivelNo(raiz->esquerda, chave, nivelAtual + 1);
    } else {
        return nivelNo(raiz->direita, chave, nivelAtual + 1);
    }
}

int alturaNo(ARVORE* a, int chave) {
    NO* no = buscar(a, chave);
    if (!no) {
        return -1;
    }
    int alturaEsquerda = alturaArvore(no->esquerda);
    int alturaDireita = alturaArvore(no->direita);

    return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}

void buscarEImprimirInfo(ARVORE *a, int codigo) {
    NO* no = NULL;
    int comparisons = 0;

    NO* raiz = a->raiz;

    while (raiz) {
        comparisons++;
        if (raiz->chave == codigo) {
            no = raiz;
            break;
        } else if (raiz->chave > codigo) {
            raiz = raiz->esquerda;
        } else {
            raiz = raiz->direita;
        }
    }

    if (no) {
        printf("%d\n",no->chave);
        printf("Informações sobre o nó %d:\n", codigo);
        printf("Comparacoes: %d\n", comparisons);
        printf("Nivel: %d\n", nivelNo(a->raiz, codigo, 0));
        printf("Altura: %d\n", alturaNo(a, codigo));
        
        NO* sucessor = buscarSucessor(a->raiz, codigo);
        printf("Sucessor: %d\n", (sucessor ? sucessor->chave : -1));
        
        NO* antecessor = buscarAntecessor(a->raiz, codigo);
        printf("Predecessor: %d\n", (antecessor ? antecessor->chave : -1));
        
        NO* pai = NULL;
        buscarNo(a->raiz, codigo, &pai);
        printf("Pai: %d\n", (pai ? pai->chave : -1));
        
        printf("Possui filho: %s\n", (no->esquerda || no->direita ? "Sim" : "Nao"));
        printf("Eh raiz: %s\n", (a->raiz == no ? "Sim" : "Nao"));
        printf("Eh no interno: %s\n", ((a->raiz != no) && (no->esquerda || no->direita) ? "Sim" : "Nao"));
        printf("Eh folha: %s\n", (!no->esquerda && !no->direita ? "Sim" : "Nao"));
    } else {
        printf("No %d nao encontrado na arvore.\n", codigo);
    }
}
