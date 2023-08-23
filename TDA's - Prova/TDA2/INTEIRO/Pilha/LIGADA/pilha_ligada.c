#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_ligada.h"

void inicializarPilha (PILHA *p){
    p->topo = NULL;
}

void reinicializarPilha (PILHA *p){
    ELEMENTO *apagar;
    ELEMENTO *elemento = p->topo;
    while (elemento != NULL){
        apagar = elemento;
        elemento = elemento->proximo;
        free(apagar);
    }
    p->topo = NULL;
}

int inserirValor (PILHA *p, int novo_valor){
    ELEMENTO *i;
    i = malloc (sizeof(ELEMENTO));
    if (i == NULL) return 0;
    i->valor = novo_valor;
    i->proximo = p->topo;
    p->topo = i;
    return 1;
}

int excluirValor (PILHA *p){
    if (p->topo == NULL) return 0;
    ELEMENTO *i = p->topo;
    p->topo = p->topo->proximo;
    free(i);
    return 1;
}

//ELEMENTO firstELEMENTO (PILHA *p){
//    return *(p->topo);
//}

int firstValor (PILHA *p){
    return p->topo->valor;
}

int imprimirPilha (PILHA p){
    if (p.topo == NULL) return 0;
    ELEMENTO *i = p.topo;
    printf("\n-------------PILHA-------------");
    while (i != NULL){
        printf("\nMemoria: %d", i);
        printf("\nValor: %d", i->valor);
        printf("\n-------------------------------");
        i = i->proximo;
    }
    return 1;
}

int maiorValor(PILHA *p) {
    if (p->topo == NULL) {
        // Lidar com o caso em que a pilha está vazia
        int valorVazio = 0;
        return valorVazio;
    }
    PILHA pilhaAuxiliar;
    inicializarPilha(&pilhaAuxiliar);

    int valorMaior = p->topo->valor;

    while (p->topo != NULL) {
        if (p->topo->valor > valorMaior) {
            valorMaior = p->topo->valor;
        }
        inserirValor(&pilhaAuxiliar, p->topo->valor);
        excluirValor(p);
    }

    while (pilhaAuxiliar.topo != NULL) {
        inserirValor(p, pilhaAuxiliar.topo->valor);
        excluirValor(&pilhaAuxiliar);
    }

    return valorMaior;
}

int menorValor(PILHA *p) {
    if (p->topo == NULL) {
        // Lidar com o caso em que a pilha está vazia
        int valorVazio = 0;
        return valorVazio;
    }
    PILHA pilhaAuxiliar;
    inicializarPilha(&pilhaAuxiliar);

    int valorMenor = p->topo->valor;

    while (p->topo != NULL) {
        if (p->topo->valor < valorMenor) {
            valorMenor = p->topo->valor;
        }
        inserirValor(&pilhaAuxiliar, p->topo->valor);
        excluirValor(p);
    }

    while (pilhaAuxiliar.topo != NULL) {
        inserirValor(p, pilhaAuxiliar.topo->valor);
        excluirValor(&pilhaAuxiliar);
    }

    return valorMenor;
}

float calcularMediaValores(PILHA *p) {
    if (p->topo == NULL) return -1;

    float somaValores = 0.0;
    int totalValores = 0;

    PILHA pilhaAuxiliar;
    inicializarPilha(&pilhaAuxiliar);

    while (p->topo != NULL) {
        somaValores += p->topo->valor;
        totalValores++;
        inserirValor(&pilhaAuxiliar, p->topo->valor);
        excluirValor(p);
    }

    float mediaValores = somaValores / totalValores;

    //inserirLivro(p, mediaPrecos);

    // Restaurar a pilha original
    while (pilhaAuxiliar.topo != NULL) {
        inserirValor(p, pilhaAuxiliar.topo->valor);
        excluirValor(&pilhaAuxiliar);
    }
    inserirValor(p, mediaValores);
    return mediaValores;
}

int posicaoPorValor(PILHA *p, int valor) {
    if (p->topo == NULL) {
        // Lidar com o caso em que a pilha está vazia
        return -1;
    }

    PILHA pilhaAuxiliar;
    inicializarPilha(&pilhaAuxiliar);

    int posicao = 0;
    int encontrou = 0;

    while (p->topo != NULL) {
        posicao++;
        if (p->topo->valor == valor) {
            encontrou = 1;
            break;
        }
        inserirValor(&pilhaAuxiliar, p->topo->valor);
        excluirValor(p);
    }

    while (pilhaAuxiliar.topo != NULL) {
        inserirValor(p, pilhaAuxiliar.topo->valor);
        excluirValor(&pilhaAuxiliar);
    }

    if (encontrou) {
        return posicao;
    } else {
        return -1;  // Valor não encontrado na pilha
    }
}

int contarValores(PILHA *p) {
    PILHA pilhaAuxiliar;
    inicializarPilha(&pilhaAuxiliar);

    int quantidade = 0;

    while (p->topo != NULL) {
        quantidade++;
        inserirValor(&pilhaAuxiliar, p->topo->valor);
        excluirValor(p);
    }

    while (pilhaAuxiliar.topo != NULL) {
        inserirValor(p, pilhaAuxiliar.topo->valor);
        excluirValor(&pilhaAuxiliar);
    }

    return quantidade;
}

int removerPorValor(PILHA *p, int valor) {
    if (p->topo == NULL) {
        // Lidar com o caso em que a pilha está vazia
        return 0;
    }

    PILHA pilhaAuxiliar;
    inicializarPilha(&pilhaAuxiliar);

    int removido = 0;

    while (p->topo != NULL) {
        if (p->topo->valor == valor) {
            excluirValor(p);
            removido = 1;
            break;
        }
        inserirValor(&pilhaAuxiliar, p->topo->valor);
        excluirValor(p);
    }

    while (pilhaAuxiliar.topo != NULL) {
        inserirValor(p, pilhaAuxiliar.topo->valor);
        excluirValor(&pilhaAuxiliar);
    }

    return removido;
}

void removerAteValor(PILHA *p, int valor) {
    if (p->topo == NULL) {
        // Lidar com o caso em que a pilha está vazia
        return;
    }

    PILHA pilhaAuxiliar;
    inicializarPilha(&pilhaAuxiliar);

    int encontrou = 0;

    while (p->topo != NULL) {
        if (p->topo->valor == valor) {
            excluirValor(p);
            encontrou = 1;
            break;
        }
        inserirValor(&pilhaAuxiliar, p->topo->valor);
        excluirValor(p);
    }

    if (!encontrou) {
        // Valor não encontrado na pilha, restaurar a pilha original
        while (pilhaAuxiliar.topo != NULL) {
            inserirValor(p, pilhaAuxiliar.topo->valor);
            excluirValor(&pilhaAuxiliar);
        }
        return;
    }

    // Remover os valores restantes
    while (pilhaAuxiliar.topo != NULL) {
        excluirValor(&pilhaAuxiliar);
    }
}
