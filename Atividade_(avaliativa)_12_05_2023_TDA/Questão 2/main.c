#include <stdio.h>
#include "complexo.h"

int main() {
    Complexo* z1 = criarComplexo(2.0, 3.0);
    Complexo* z2 = criarComplexo(4.0, 5.0);

    Complexo* soma = somarComplexos(z1, z2);
    printf("Soma: %.2lf + %.2lfi\n", soma->real, soma->imag);

    Complexo* subtracao = subtrairComplexos(z1, z2);
    printf("Subtracao: %.2lf + %.2lfi\n", subtracao->real, subtracao->imag);

    Complexo* multiplicacao = multiplicarComplexos(z1, z2);
    printf("Multiplicacao: %.2lf + %.2lfi\n", multiplicacao->real, multiplicacao->imag);

    Complexo* divisao = dividirComplexos(z1, z2);
    printf("Divisao: %.2lf + %.2lfi\n", divisao->real, divisao->imag);

    destruirComplexo(z1);
    destruirComplexo(z2);
    destruirComplexo(soma);
    destruirComplexo(subtracao);
    destruirComplexo(multiplicacao);
    destruirComplexo(divisao);

    return 0;
}
