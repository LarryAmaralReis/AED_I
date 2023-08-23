#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque_ligado.h"

void inicializarDeque(DEQUE *d) {
    d->cabeca = malloc(sizeof(ELEMENTO));
    d->cabeca->anterior = d->cabeca;
    d->cabeca->proximo = d->cabeca;
}

void reinicializarDeque(DEQUE *d) {
    ELEMENTO *apagar;
    ELEMENTO *elemento = d->cabeca->proximo;
    while (elemento != d->cabeca) {
        apagar = elemento;
        elemento = elemento->proximo;
        free(apagar);
    }
    d->cabeca->anterior = d->cabeca;
    d->cabeca->proximo = d->cabeca;
}

void mostrarDeque(DEQUE *d) {
    printf("\n--------------------------");
    ELEMENTO *i = d->cabeca->proximo;
    while (i != d->cabeca) {
        printf("\n--------------------------");
        printf("\nValor: %d", i->valor);
        i = i->proximo;
    }
}

int inserirValorInicio(DEQUE *d, int novo_valor) {
    ELEMENTO *i = malloc(sizeof(ELEMENTO));
    if (i == NULL) {
        return 0; // Failed to allocate memory
    }
    i->valor = novo_valor;
    i->proximo = d->cabeca->proximo;
    i->anterior = d->cabeca;
    d->cabeca->proximo = i;
    i->proximo->anterior = i;
    return 1; // Successfully inserted
}

int inserirValorFim(DEQUE *d, int novo_valor) {
    ELEMENTO *i = malloc(sizeof(ELEMENTO));
    if (i == NULL) {
        return 0; // Failed to allocate memory
    }
    i->valor = novo_valor;
    i->proximo = d->cabeca;
    i->anterior = d->cabeca->anterior;
    d->cabeca->anterior = i;
    i->anterior->proximo = i;
    return 1; // Successfully inserted
}

int excluirValorInicio(DEQUE *d) {
    if (d->cabeca->proximo == d->cabeca) {
        return 0; // Deque is empty
    }
    ELEMENTO *i = d->cabeca->proximo;
    d->cabeca->proximo = i->proximo;
    i->proximo->anterior = d->cabeca;
    free(i);
    return 1; // Successfully deleted
}

int excluirValorFim(DEQUE *d) {
    if (d->cabeca->anterior == d->cabeca) {
        return 0; // Deque is empty
    }
    ELEMENTO *i = d->cabeca->anterior;
    d->cabeca->anterior = i->anterior;
    i->anterior->proximo = d->cabeca;
    free(i);
    return 1; // Successfully deleted
}

int getValorInicio(DEQUE *d) {
    if (d->cabeca->proximo == d->cabeca) {
        exit(EXIT_FAILURE); // or handle the error in a different way
    }
    return d->cabeca->proximo->valor;
}

int getValorFim(DEQUE *d) {
    if (d->cabeca->anterior == d->cabeca) {
        exit(EXIT_FAILURE); // or handle the error in a different way
    }
    return d->cabeca->anterior->valor;
}

int getValorMaior(DEQUE *d) {
    if (d->cabeca->proximo == d->cabeca)
        exit(EXIT_FAILURE); // ou trate o erro de outra forma

    DEQUE auxiliar;
    inicializarDeque(&auxiliar);

    int dequeVazio = (d->cabeca->proximo == d->cabeca); // Verifica se o deque principal está vazio

    while (!dequeVazio) {
        int valorAtual = getValorInicio(d);
        excluirValorInicio(d);
        inserirValorInicio(&auxiliar, valorAtual);

        dequeVazio = (d->cabeca->proximo == d->cabeca); // Atualiza a variável dequeVazio
    }

    int valorMaior = auxiliar.cabeca->proximo->valor;

    while (auxiliar.cabeca->proximo != auxiliar.cabeca) {
        int valorAtual = getValorInicio(&auxiliar);
        excluirValorInicio(&auxiliar);
        if (valorAtual > valorMaior)
            valorMaior = valorAtual;
        inserirValorInicio(d, valorAtual);
    }

    reinicializarDeque(&auxiliar);

    return valorMaior;
}

int getValorMenor(DEQUE *d) {
    if (d->cabeca->proximo == d->cabeca)
        exit(EXIT_FAILURE); // ou trate o erro de outra forma

    DEQUE auxiliar;
    inicializarDeque(&auxiliar);

    int dequeVazio = (d->cabeca->proximo == d->cabeca); // Verifica se o deque principal está vazio

    while (!dequeVazio) {
        int valorAtual = getValorInicio(d);
        excluirValorInicio(d);
        inserirValorInicio(&auxiliar, valorAtual);

        dequeVazio = (d->cabeca->proximo == d->cabeca); // Atualiza a variável dequeVazio
    }

    int valorMenor = auxiliar.cabeca->proximo->valor;

    while (auxiliar.cabeca->proximo != auxiliar.cabeca) {
        int valorAtual = getValorInicio(&auxiliar);
        excluirValorInicio(&auxiliar);
        if (valorAtual < valorMenor)
            valorMenor = valorAtual;
        inserirValorInicio(d, valorAtual);
    }

    reinicializarDeque(&auxiliar);

    return valorMenor;
}

void calcularMediaInserirInicio(DEQUE *d) {
    if (d->cabeca->proximo == d->cabeca)
        exit(EXIT_FAILURE); // ou trate o erro de outra forma

    DEQUE auxiliar;
    inicializarDeque(&auxiliar);

    int totalValores = 0;
    int numValores = 0;

    while (d->cabeca->proximo != d->cabeca) {
        int valorAtual = getValorInicio(d);
        excluirValorInicio(d);
        inserirValorInicio(&auxiliar, valorAtual);

        totalValores += valorAtual;
        numValores++;
    }

    float media = totalValores / numValores;

    //inserir no final
    inserirValorInicio(d, media);

    while (auxiliar.cabeca->proximo != auxiliar.cabeca) {
        int valorAtual = getValorInicio(&auxiliar);
        excluirValorInicio(&auxiliar);
        inserirValorInicio(d, valorAtual);
    }

    //inserir no inicio
    inserirValorInicio(d, media);
}

int excluirValorPorCodigo(DEQUE *d, int codigo) {
    if (d->cabeca->proximo == d->cabeca) {
        return 0; // Deque is empty
    }

    DEQUE auxiliar;
    inicializarDeque(&auxiliar);

    int valorRemovido = 0;

    while (d->cabeca->proximo != d->cabeca) {
        int valorAtual = getValorInicio(d);
        excluirValorInicio(d);

        if (valorAtual != codigo) {
            inserirValorInicio(&auxiliar, valorAtual);
        } else {
            valorRemovido = 1;
        }
    }

    while (auxiliar.cabeca->proximo != auxiliar.cabeca) {
        int valorAtual = getValorInicio(&auxiliar);
        excluirValorInicio(&auxiliar);
        inserirValorInicio(d, valorAtual);
    }

    reinicializarDeque(&auxiliar);

    return valorRemovido;
}

int posicaoPorValor(DEQUE *d, int valor) {
    if (d->cabeca->proximo == d->cabeca) {
        return -1; // Deque is empty, no elements to search
    }

    DEQUE auxiliar;
    inicializarDeque(&auxiliar);

    int posicao = 1;
    int posicaoEncontrada = -1;

    while (d->cabeca->proximo != d->cabeca) {
        int valorAtual = getValorInicio(d);
        excluirValorInicio(d);

        if (valorAtual == valor) {
            posicaoEncontrada = posicao;
        }

        inserirValorFim(&auxiliar, valorAtual);
        posicao++;
    }

    while (auxiliar.cabeca->proximo != auxiliar.cabeca) {
        int valorAtual = getValorInicio(&auxiliar);
        excluirValorInicio(&auxiliar);
        inserirValorFim(d, valorAtual);
    }

    reinicializarDeque(&auxiliar);

    return posicaoEncontrada;
}

int contarValores(DEQUE *d) {
    if (d->cabeca->proximo == d->cabeca) {
        return 0; // Deque is empty
    }

    DEQUE auxiliar;
    inicializarDeque(&auxiliar);

    int count = 0;

    while (d->cabeca->proximo != d->cabeca) {
        int valorAtual = getValorInicio(d);
        excluirValorInicio(d);
        inserirValorFim(&auxiliar, valorAtual);
        count++;
    }

    while (auxiliar.cabeca->proximo != auxiliar.cabeca) {
        int valorAtual = getValorInicio(&auxiliar);
        excluirValorInicio(&auxiliar);
        inserirValorFim(d, valorAtual);
    }

    reinicializarDeque(&auxiliar);

    return count;
}

void removerAteValor(DEQUE *d, int valor) {
    if (d->cabeca->proximo == d->cabeca) {
        return; // Deque is empty
    }

    DEQUE auxiliar;
    inicializarDeque(&auxiliar);

    while (d->cabeca->proximo != d->cabeca) {
        int valorAtual = getValorInicio(d);
        excluirValorInicio(d);

        if (valorAtual == valor) {
            break; // Stop removing values when the specified value is found
        }

        inserirValorFim(&auxiliar, valorAtual);
    }

    while (auxiliar.cabeca->proximo != auxiliar.cabeca) {
        int valorAtual = getValorInicio(&auxiliar);
        excluirValorInicio(&auxiliar);
        inserirValorFim(d, valorAtual);
    }

    reinicializarDeque(&auxiliar);
}

