#include <stdio.h>
#include "int_hash_ligado.c"

int main() {
    TB_HASH tabela;
    inicializahash(tabela);

    inserir(tabela, 12);
    inserir(tabela, 44);
    inserir(tabela, 13);
    inserir(tabela, 88);
    inserir(tabela, 23);
    inserir(tabela, 94);
    inserir(tabela, 11);
    inserir(tabela, 39);
    inserir(tabela, 20);
    inserir(tabela, 16);
    inserir(tabela, 5);
    mostrarHash(tabela);

    int totalNumeros = contarNumeros(tabela);
    printf("\nTotal de numeros na tabela: %d", totalNumeros);

    printf("\n Maior numero: %d", encontrarMaior(tabela));
    printf("\n Menor numero: %d", encontrarMenor(tabela));
    printf("\n Media dos numeros: %.2f", calcularMedia(tabela));

    int posicao = buscarPosicaoPeloNumero(tabela, 5);
    if (posicao != -1) {
        printf("\nO numero 5 esta na posicao %d", posicao);
    } else {
        printf("\nO numero 5 nao foi encontrado.");
    }

    printf("\nTabela antes da remocao:");
    mostrarHash(tabela);

    int posicaoRemover = 0;
    if (removerPelaPosicao(tabela, posicaoRemover)) {
        printf("\nRemocao do numero na posicao %d realizada com sucesso.", posicaoRemover);
    } else {
        printf("\nRemocao do numero na posicao %d falhou.", posicaoRemover);
    }

    printf("\nTabela apos a remocao:");
    mostrarHash(tabela);

    return 0;
}