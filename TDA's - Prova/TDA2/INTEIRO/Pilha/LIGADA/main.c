#include "pilha_ligada.c"

int main(){
    PILHA pilha;

    inicializarPilha(&pilha);

    inserirValor(&pilha, 300);

    inserirValor(&pilha, 500);

    inserirValor(&pilha, 56);

    imprimirPilha(pilha);

    int valor = firstValor(&pilha);
    printf("\nValor do Topo: %d", valor);

    valor = maiorValor(&pilha);
    if (valor == 0) {
        printf("\nA pilha está vazia.");
    } else {
        printf("\nMaior Valor: %d", valor);
    }

    valor = menorValor(&pilha);
    if (valor == 0) {
        printf("\nA pilha está vazia.");
    } else {
        printf("\nMenor Valor: %d", valor);
    }

    float media = calcularMediaValores(&pilha);
    printf("\nMedia dos valores: %f", media);
    imprimirPilha(pilha);

    // Testar as funções
    int posicao = posicaoPorValor(&pilha, 285);
    if (posicao != -1) {
        printf("\nValor 285 encontrado na posicao %d.\n", posicao);
    } else {
        printf("\nValor 285 nao encontrado na pilha.\n");
    }

    int quantidade = contarValores(&pilha);
    printf("\nQuantidade de valores na pilha: %d\n", quantidade);

    int removido = removerPorValor(&pilha, 285);
    if (removido) {
        printf("\nValor 285 removido da pilha.\n");
    } else {
        printf("\nValor 285 nao encontrado na pilha.\n");
    }
    imprimirPilha(pilha);

    removerAteValor(&pilha, 500);
    printf("\nPilha apos remover ate valor:\n");
    imprimirPilha(pilha);

}