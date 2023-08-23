#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_ligada.h"

void inicializarFila (FILA *f){
    f->inicio = NULL;
    f->fim = NULL;
}

void reinicializarFila (FILA *f){
    ELEMENTO *apagar;
    ELEMENTO *elemento = f->inicio;
    while (elemento != NULL){
        apagar = elemento;
        elemento = elemento->proximo;
        free(apagar);
    }
    f->inicio = NULL;
}

int inserirValor (FILA *f, int novo_valor){
    ELEMENTO *i;
    i = malloc(sizeof(ELEMENTO));
    if (i==NULL) return 0;
    i->valor = novo_valor;
    i->proximo = NULL;
    if (f->inicio == NULL) f->inicio = i;
    else f->fim->proximo = i;
    f->fim = i;
    return 1;
}

int inserirValorFlutuante (FILA *f, float novo_valor){
    ELEMENTO *i;
    i = malloc(sizeof(ELEMENTO));
    if (i==NULL) return 0;
    i->valor = novo_valor;
    i->proximo = NULL;
    if (f->inicio == NULL) f->inicio = i;
    else f->fim->proximo = i;
    f->fim = i;
    return 1;
}

int excluirValor (FILA *f){
    if (f->inicio == NULL) return 0;
    ELEMENTO *i = f->inicio;
    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL) f->fim = NULL;
    free (i);
    return 1;
}

ELEMENTO firstELEMENTO (FILA *f){
    return *(f->inicio);
}

int firstValor (FILA *f){
    return f->inicio->valor;
}

int lastValor (FILA *f){
    return f->fim->valor;
}

int imprimirFila (FILA f){
    if (f.inicio == NULL) return 0;
    ELEMENTO *i = f.inicio;
    printf("\n-------------FILA-------------");
    while (i != NULL){
        printf("\nMemoria: %d", i);
        printf("\nValor: %.0f", (float)i->valor);
        printf("\n------------------------------");
        i = i->proximo;
    }
    return 1;
}

int maiorValor(FILA *f) {
    FILA filaAuxiliar;
    inicializarFila(&filaAuxiliar);

    int valorMaior;

    int maiorValor = 0;

    // Verificar se a fila está vazia
    if (f->inicio == NULL) {
        printf("A fila está vazia.\n");
        return valorMaior;
    }

    // Percorrer a fila original para encontrar o paciente de maior idade
    while (f->inicio != NULL) {
        int valor = firstValor(f);
        excluirValor(f);

        if (valor > maiorValor) {
            valorMaior = valor;
            maiorValor = valor;
        }

        inserirValor(&filaAuxiliar, valor);
    }

    // Restaurar a fila original
    while (filaAuxiliar.inicio != NULL) {
        int valor = firstValor(&filaAuxiliar);
        excluirValor(&filaAuxiliar);
        inserirValor(f, valor);
    }

    return valorMaior;
}

int menorValor(FILA *f) {
    FILA filaAuxiliar;
    inicializarFila(&filaAuxiliar);

    int valorMenor;
    int menorValor = INT_MAX;  // Inicializar com um valor máximo

    // Verificar se a fila está vazia
    if (f->inicio == NULL) {
        printf("A fila está vazia.\n");
        // Retorna um paciente com código -1 para indicar que não há paciente válido
        int valorInvalido = -1;
        return valorInvalido;
    }

    // Percorrer a fila original para encontrar o paciente de menor código
    while (f->inicio != NULL) {
        int valor = firstValor(f);
        excluirValor(f);

        if (valor < menorValor) {
            valorMenor = valor;
            menorValor = valor;
        }

        inserirValor(&filaAuxiliar, valor);
    }

    // Restaurar a fila original
    while (filaAuxiliar.inicio != NULL) {
        int valor = firstValor(&filaAuxiliar);
        excluirValor(&filaAuxiliar);
        inserirValor(f, valor);
    }

    return valorMenor;
}

void inserirMediaValores(FILA *f) {
    FILA filaAuxiliar;
    inicializarFila(&filaAuxiliar);

    int somaValores = 0;
    int numValores = 0;

    // Verificar se a fila está vazia
    if (f->inicio == NULL) {
        printf("A fila está vazia.\n");
        return;
    }

    // Percorrer a fila original para somar os valores e contar o número de elementos
    while (f->inicio != NULL) {
        int valor = firstValor(f);
        excluirValor(f);
        somaValores += valor;
        numValores++;
        inserirValor(&filaAuxiliar, valor);
    }

    // Calcular a média dos valores
    float mediaValores = (float) somaValores / numValores;
    // Restaurar a fila original a partir da fila auxiliar
    while (filaAuxiliar.inicio != NULL) {
        int valor = firstValor(&filaAuxiliar);
        excluirValor(&filaAuxiliar);
        inserirValor(f, valor);
    }
    inserirValorFlutuante(f, mediaValores);
}

int posicaoPorValor(FILA *f, int codigo) {
    FILA filaAuxiliar;
    inicializarFila(&filaAuxiliar);

    // Verificar se a fila está vazia
    if (f->inicio == NULL) {
        printf("A fila está vazia.\n");
        return -1;  // Retorna -1 para indicar que o paciente não foi encontrado
    }

    int posicao = 0;
    int valorEncontrado = 0;  // Flag para indicar se o paciente foi encontrado

    // Percorrer a fila original para encontrar o paciente com o código
    while (f->inicio != NULL) {
        int valor = firstValor(f);
        excluirValor(f);
        if (valorEncontrado != 1) posicao++;;
        if (valor == codigo) valorEncontrado = 1;  // Marcar que o paciente foi encontrado
        inserirValor(&filaAuxiliar, valor);
    }

    // Restaurar a fila original a partir da fila auxiliar
    while (filaAuxiliar.inicio != NULL) {
        int valor = firstValor(&filaAuxiliar);
        excluirValor(&filaAuxiliar);
        inserirValor(f, valor); 
    }

    if (valorEncontrado) {
        printf("\nO valor com o código %d está na posição %d da fila.", codigo, posicao);
        return posicao;
    } else {
        printf("\nO valor com o código %d não foi encontrado na fila.", codigo);
        return -1;  // Retorna -1 para indicar que o paciente não foi encontrado
    }
}

int contarValores(FILA *f) {
    FILA filaAuxiliar;
    inicializarFila(&filaAuxiliar);

    int contador = 0;

    // Verificar se a fila está vazia
    if (f->inicio == NULL) {
        printf("A fila está vazia.\n");
        return contador;
    }

    // Percorrer a fila original para contar os elementos
    while (f->inicio != NULL) {
        int valor = firstValor(f);
        excluirValor(f);
        contador++;
        inserirValor(&filaAuxiliar, valor);
    }

    // Restaurar a fila original a partir da fila auxiliar
    while (filaAuxiliar.inicio != NULL) {
        int valor = firstValor(&filaAuxiliar);
        excluirValor(&filaAuxiliar);
        inserirValor(f, valor);
    }

    return contador;
}

int removerPorValor(FILA *f, int valor) {
    FILA filaAuxiliar;
    inicializarFila(&filaAuxiliar);

    int removido = 0;

    // Verificar se a fila está vazia
    if (f->inicio == NULL) {
        printf("A fila está vazia.\n");
        return removido;
    }

    // Percorrer a fila original para encontrar o valor e removê-lo
    while (f->inicio != NULL) {
        int valorAtual = firstValor(f);
        excluirValor(f);
        if (valorAtual == valor) {
            removido = 1;  // Indicar que o valor foi removido
        } else {
            inserirValor(&filaAuxiliar, valorAtual);
        }
    }

    // Restaurar a fila original a partir da fila auxiliar
    while (filaAuxiliar.inicio != NULL) {
        int valorAtual = firstValor(&filaAuxiliar);
        excluirValor(&filaAuxiliar);
        inserirValor(f, valorAtual);
    }

    return removido;
}



