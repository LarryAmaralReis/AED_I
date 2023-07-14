#include <stdio.h>
#include <stdlib.h>
#include "deque_ligado.c"

int main() {
    DEQUE deque;
    inicializarDeque(&deque);

    // Testar inserção de valores no início
    inserirValorInicio(&deque, 10);
    inserirValorInicio(&deque, 20);
    inserirValorInicio(&deque, 30);

    printf("Deque depois da inserção no início:\n");
    mostrarDeque(&deque);
    printf("\n");

    // Testar inserção de valores no fim
    inserirValorFim(&deque, 40);
    inserirValorFim(&deque, 50);

    printf("Deque depois da inserção no fim:\n");
    mostrarDeque(&deque);
    printf("\n");

    // Testar obtenção do valor no início
    int valorInicio = getValorInicio(&deque);
    printf("Valor no início do deque: %d\n", valorInicio);
    printf("\n");

    // Testar obtenção do valor no fim
    int valorFim = getValorFim(&deque);
    printf("Valor no fim do deque: %d\n", valorFim);
    printf("\n");

    // Testar obtenção do valor maior
    int valorMaior = getValorMaior(&deque);
    printf("Maior valor do deque: %d\n", valorMaior);
    printf("\n");

    // Testar obtenção do valor menor
    int valorMenor = getValorMenor(&deque);
    printf("Menor valor do deque: %d\n", valorMenor);
    printf("\n");

    // Testar cálculo da média e inserção no início
    calcularMediaInserirInicio(&deque);

    printf("Deque após cálculo da média e inserção no início:\n");
    mostrarDeque(&deque);
    printf("\n");

    // Testar remoção de valor por código
    int removido = excluirValorPorCodigo(&deque, 30);
    printf("Valor 30 removido do deque: %s\n", removido ? "Sim" : "Não");
    printf("\n");

    printf("Deque após remoção do valor 30:\n");
    mostrarDeque(&deque);
    printf("\n");

    // Testar busca de posição por valor
    int posicao = posicaoPorValor(&deque, 40);
    printf("Posição do valor 40 no deque: %d\n", posicao);
    printf("\n");

    // Testar contagem de valores
    int count = contarValores(&deque);
    printf("Quantidade de valores no deque: %d\n", count);
    printf("\n");

    // Testar remoção de valores até um determinado valor
    removerAteValor(&deque, 20);

    printf("Deque após remoção até o valor 20:\n");
    mostrarDeque(&deque);
    printf("\n");

    reinicializarDeque(&deque);

    return 0;
}
