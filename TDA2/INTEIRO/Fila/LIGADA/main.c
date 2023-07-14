#include "fila_ligada.c"

int main(){
    FILA fila;
    inicializarFila(&fila);

    int p;
    inserirValor(&fila, 1);

    inserirValor(&fila, 25);

    inserirValor(&fila, 111);

    imprimirFila(fila);

    p = firstValor(&fila);
    printf("\nPrimeiro Valor: %d", p);

    ELEMENTO e;
    e = firstELEMENTO(&fila);
    printf("\nPrimeiro Elemento: %d", e.valor);

    int valorMaior = maiorValor(&fila);

    printf("\nMaior valor: %d", valorMaior);

    int valorMenor = menorValor(&fila);

    printf("\nMenor valor: %d", valorMenor);

    inserirMediaValores(&fila);

    imprimirFila(fila);

    int pos = posicaoPorValor(&fila, 25);

    printf("\nPosicao do valor desejado: %d", pos);

    int qtd = contarValores(&fila);

    printf("\nA fila tem %d numeros", qtd);

    removerPorValor(&fila, 45);

    imprimirFila(fila);

}