#include "abb.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if (raiz->pac.cod_pac > no->pac.cod_pac) raiz->esquerda = inserir(raiz->esquerda, no);
    else raiz->direita = inserir(raiz->direita, no);
    return (raiz);
}

int adicionarAux (ARVORE *a, NO* novo) {
    a->raiz = inserir (a->raiz, novo);
    return 1;
}

int adicionar (ARVORE *a, PACIENTE p) {
    NO* novoNo = malloc(sizeof(NO));
    if (novoNo == NULL) return 0;
    novoNo->pac = p;
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
        printf("Codigo: %d\n", raiz->pac.cod_pac);
        printf("Nome: %s\n", raiz->pac.nome);
        listarNos(raiz->esquerda);
        listarNos(raiz->direita);
    }
}

void listarArvore (ARVORE *a) {
    listarNos (a->raiz);
}

NO* contem (NO* raiz, int codpc) {
    if (raiz == NULL) return NULL;
    if (raiz->pac.cod_pac == codpc) return raiz;
    if (raiz->pac.cod_pac > codpc) return contem(raiz->esquerda, codpc);
    else return contem(raiz->esquerda, codpc);
}

NO* buscar (ARVORE* a, int codpc) {
    return contem (a->raiz, codpc);
}

int numeroNos (NO* raiz) {
    if (!raiz) return 0;
    return (
        numeroNos (raiz->esquerda)
        +1
        +numeroNos (raiz->direita)
    );
}

NO* buscarNo (NO* raiz, int codpc, NO** pai) {
    NO* atual = raiz;
    *pai = NULL;
    printf("Pai: %d", pai);
    while (atual) {
        if (atual->pac.cod_pac == codpc) return atual;
        *pai = atual;
        if (codpc < atual->pac.cod_pac) atual = atual->esquerda;
        else atual = atual->direita;
    }
    return NULL;
}

int excluirNo (NO* raiz, int codpc) {
    NO* no;
    NO* pai;
    NO* no_subs;
    NO* pai_subs;
    no = buscarNo (raiz, codpc, &pai);
    if (no == NULL) return 0;
    if (!no->esquerda || !no->direita) {
        if (!no->esquerda) no_subs = no->direita;
        else no_subs = no->esquerda;
    } else {
        pai_subs = no;
        no_subs = no->esquerda;
        while (no_subs->direita)
        {
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
        free(no);
        return 1;
    }
    if (codpc < pai->pac.cod_pac) pai->esquerda = no_subs;
    else pai->direita = no_subs;
    free (no);
    return 1;
}

void pre_ordem (NO* raiz) {
    if (!raiz) return;
    printf ("%d ", raiz->pac.cod_pac);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}

void in_ordem (NO* raiz) {
    if (!raiz) return;
    in_ordem(raiz->esquerda);
    printf ("%d ", raiz->pac.cod_pac);
    in_ordem(raiz->direita);
}

void pos_ordem (NO* raiz) {
    if (!raiz) return;
    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    printf ("%d ", raiz->pac.cod_pac);
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
        if (chave < raiz->pac.cod_pac) {
            sucessor = raiz;
            raiz = raiz->esquerda;
        } else if (chave > raiz->pac.cod_pac) {
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
        if (chave > raiz->pac.cod_pac) {
            antecessor = raiz;
            raiz = raiz->direita;
        } else if (chave < raiz->pac.cod_pac) {
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
        printf("%d ", raiz->pac.cod_pac);
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

    if (raiz->pac.cod_pac < min || raiz->pac.cod_pac > max) {
        return 0;
    }

    return (verificarArvoreBinaria(raiz->esquerda, min, raiz->pac.cod_pac - 1) &&
            verificarArvoreBinaria(raiz->direita, raiz->pac.cod_pac + 1, max));
}

// Função para encontrar o paciente de menor idade na árvore
NO* encontrarMenorIdade(NO* raiz) {
    if (!raiz) {
        return NULL;
    }
    
    NO* pacienteMenorIdade = NULL;
    int menorIdade = INT_MAX;
    
    encontrarMenorIdadeAux(raiz, &pacienteMenorIdade, &menorIdade);
    
    return pacienteMenorIdade;
}

// Função auxiliar para encontrar o paciente de menor idade na árvore
void encontrarMenorIdadeAux(NO* raiz, NO** pacienteMenorIdade, int* menorIdade) {
    if (!raiz) {
        return;
    }
    
    encontrarMenorIdadeAux(raiz->esquerda, pacienteMenorIdade, menorIdade);
    
    if (raiz->pac.idade < *menorIdade) {
        *menorIdade = raiz->pac.idade;
        *pacienteMenorIdade = raiz;
    }
    
    encontrarMenorIdadeAux(raiz->direita, pacienteMenorIdade, menorIdade);
}

// Função para encontrar o paciente de maior idade na árvore
NO* encontrarMaiorIdade(NO* raiz) {
    if (!raiz) {
        return NULL;
    }
    
    NO* pacienteMaiorIdade = NULL;
    int maiorIdade = INT_MIN;
    
    encontrarMaiorIdadeAux(raiz, &pacienteMaiorIdade, &maiorIdade);
    
    return pacienteMaiorIdade;
}

// Função auxiliar para encontrar o paciente de maior idade na árvore
void encontrarMaiorIdadeAux(NO* raiz, NO** pacienteMaiorIdade, int* maiorIdade) {
    if (!raiz) {
        return;
    }
    
    encontrarMaiorIdadeAux(raiz->esquerda, pacienteMaiorIdade, maiorIdade);
    
    if (raiz->pac.idade > *maiorIdade) {
        *maiorIdade = raiz->pac.idade;
        *pacienteMaiorIdade = raiz;
    }
    
    encontrarMaiorIdadeAux(raiz->direita, pacienteMaiorIdade, maiorIdade);
}

NO* encontrarPorNomeAux(NO* raiz, const char* nome, int* comparacoes) {
    if (!raiz) {
        return NULL;
    }

    int resultado = strcmp(nome, raiz->pac.nome);
    (*comparacoes)++;
    
    if (resultado == 0) {
        return raiz;
    } else if (resultado > 0) {
        return encontrarPorNomeAux(raiz->esquerda, nome, comparacoes);
    } else {
        return encontrarPorNomeAux(raiz->direita, nome, comparacoes);
    }
}






