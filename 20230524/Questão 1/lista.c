#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

void criarLista(LISTA *l, int tam_vetor) {
    l->vetor = (int *) malloc(sizeof(int) * tam_vetor);
    l->tam_vetor = tam_vetor;
}

void liberaLista(LISTA *l) {
    free(l->vetor);
    l->tam_vetor = 0;
}

void inserirElementos(LISTA *l) {
    if (l->tam_vetor == 0) {
        printf("Lista nao criada.\n");
        return;
    }
    srand(time(NULL));
    for (int i = 0; i < l->tam_vetor; i++) {
        l->vetor[i] = rand();
    }
}

void inserirElementosOrdenados(LISTA *l) {
    if (l->tam_vetor == 0) {
        printf("Lista nao criada.\n");
        return;
    }
    srand(time(NULL));
    int i;
    for (i = 0; i < l->tam_vetor; i++) {
        int elemento = rand();
        int j;

        for (j = i; j > 0 && l->vetor[j - 1] > elemento; j--) {
            l->vetor[j] = l->vetor[j - 1];
        }

        l->vetor[j] = elemento;
    }
}

void imprimirLista(LISTA *l) {
    printf("[");
    for (int i = 0; i < l->tam_vetor; i++) {
        printf("%d: %d", i, l->vetor[i]);
        if (i < l->tam_vetor - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int buscarElementoSequencial(LISTA *l, int elemento) {
    if (l->tam_vetor == 0) {
        printf("Lista nao criada.\n");
        return -1;
    }
    int i, comp = 0;
    for (i = 0; i < l->tam_vetor; i++) {
        comp++;
        if (l->vetor[i] == elemento) {
            printf("Elemento encontrado ao fazer %d comparacoes.\n", comp);
            return i;
        }
    }
    printf("Elemento nao encontrado, %d comparacoes executadas.\n", comp);
    return -1;
}

int buscarElementoSequencialOrdenado(LISTA *l, int elemento) {
    if (l->tam_vetor == 0) {
        printf("Lista nao criada.\n");
        return -1;
    }
    int i, comp = 0;
    for (i = 0; i < l->tam_vetor; i++) {
        comp++;
        if (l->vetor[i] == elemento) {
            printf("Elemento encontrado ao fazer %d comparacoes.\n", comp);
            return i;
        } else if (l->vetor[i] > elemento) {
            printf("Elemento nao encontrado, %d comparacoes executadas.\n", comp);
            return -1;
        }
    }
    printf("Elemento nao encontrado, %d comparacoes executadas.\n", comp);
    return -1;
}

int buscarElementoBinarioIterativo(LISTA *l, int elemento) {
    if (l->tam_vetor == 0) {
        printf("Lista nao criada.\n");
        return -1;
    }
    int comp = 0;
    int primeiro = 0;
    int ultimo = l->tam_vetor - 1;
    while (primeiro <= ultimo) {
        comp++;
        int meio = (primeiro + ultimo) / 2;
        if (l->vetor[meio] == elemento) {
            printf("Elemento encontrado ao fazer %d comparacoes.\n", comp);
            return meio;
        } else if (l->vetor[meio] < elemento) {
            primeiro = meio + 1;
        } else {
            ultimo = meio - 1;
        }
    }
    printf("Elemento nao encontrado, %d comparacoes executadas.\n", comp);
    return -1;
}

int buscarElementoBinarioRecursivo(LISTA *l, int elemento, int primeiro, int ultimo, int comp) {
    if (l->tam_vetor == 0) {
        printf("Lista não criada.\n");
        return -1;
    }
    if (primeiro > ultimo) {
        printf("Elemento nao encontrado, %d comparacoes executadas.\n", comp);
        return -1;
    }
    int meio = (primeiro + ultimo) / 2;
    if (elemento == l->vetor[meio]) {
        printf("Elemento encontrado ao fazer %d comparacoes.\n", comp);
        return meio;
    } else if (elemento < l->vetor[meio]) {
        return buscarElementoBinarioRecursivo(l, elemento, primeiro, meio - 1, comp + 1);
    } else {
        return buscarElementoBinarioRecursivo(l, elemento, meio + 1, ultimo, comp + 1);
    }
}

void imprimirListaRecursiva(LISTA *l) {
    static int indice = 0;
    if (indice >= l->tam_vetor) {
        printf("]\n");
        indice = 0;
        return;
    }
    if (indice == 0) {
        printf("[");
    } else {
        printf(", ");
    }
    printf("%d: %d", indice, l->vetor[indice]);
    indice++;
    imprimirListaRecursiva(l);
}

int buscarMaiorElementoIterativo(LISTA *l) {
    if (l->tam_vetor == 0) {
        printf("Lista nao criadaaaaa.\n");
        return -1;  // Valor inválido como indicador de erro
    }
    int maior = l->vetor[0];
    for (int i = 1; i < l->tam_vetor; i++) {
        if (l->vetor[i] > maior) {
            maior = l->vetor[i];
        }
    }
    return maior;
}

int buscarMaiorElementoRecursivo(LISTA *l, int indice) {
    if (l->tam_vetor == 0) {
        printf("Lista nao criada.\n");
        return -1;  // Valor inválido como indicador de erro
    }
    if (indice == l->tam_vetor - 1) {
        return l->vetor[indice];
    }
    int submaior = buscarMaiorElementoRecursivo(l, indice + 1);
    if (l->vetor[indice] > submaior) {
        return l->vetor[indice];
    } else {
        return submaior;
    }
}

int buscarMenorElementoIterativo(LISTA *l) {
    if (l->tam_vetor == 0) {
        printf("Lista nao criada.\n");
        return -1;
    }
    int menor = l->vetor[0];
    for (int i = 1; i < l->tam_vetor; i++) {
        if (l->vetor[i] < menor) {
            menor = l->vetor[i];
        }
    }
    return menor;
}

int buscarMenorElementoRecursivo(LISTA *l, int indice) {
    if (l->tam_vetor == 0) {
        printf("Lista nao criada.\n");
        return -1;  // Valor inválido como indicador de erro
    }
    if (indice == l->tam_vetor - 1) {
        return l->vetor[indice];
    }
    int submenor = buscarMenorElementoRecursivo(l, indice + 1);
    if (l->vetor[indice] < submenor) {
        return l->vetor[indice];
    } else {
        return submenor;
    }
}

int somaIterativa(LISTA *l) {
    if (l->tam_vetor == 0) {
        printf("Lista nao criada.\n");
        return 0;  // Valor padrão para lista vazia
    }

    int soma = 0;
    for (int i = 0; i < l->tam_vetor; i++) {
        soma += l->vetor[i];
    }

    return soma;
}

int somaRecursiva(LISTA *l, int indice) {
    if (l->tam_vetor == 0) {
        printf("Lista nao criada.\n");
        return 0;  // Valor padrão para lista vazia
    }

    if (indice == l->tam_vetor - 1) {
        return l->vetor[indice];
    }

    int soma = l->vetor[indice] + somaRecursiva(l, indice + 1);
    return soma;
}

long long int produtoIterativo(LISTA *l) {
    if (l->tam_vetor == 0) {
        printf("Lista nao criada.\n");
        return 0;  // Valor padrão para lista vazia
    }

    long long int produto = 1;
    for (int i = 0; i < l->tam_vetor; i++) {
        produto *= l->vetor[i];
    }

    return produto;
}

long long int produtoRecursivo(LISTA *l, int indice) {
    if (l->tam_vetor == 0) {
        printf("Lista nao criada.\n");
        return 0;  // Valor padrão para lista vazia
    }

    if (indice == l->tam_vetor - 1) {
        return l->vetor[indice];
    }

    long long int produto = l->vetor[indice] * produtoRecursivo(l, indice + 1);
    return produto;
}









