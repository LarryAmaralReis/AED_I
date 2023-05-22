#include <stdio.h>
#include <stdlib.h>
#include "cubo.h"

int main() {
    Cubo c;
    double lado;
    char input[100];

    printf("Digite o tamanho do lado do cubo: ");
    fgets(input, sizeof(input), stdin);
    lado = strtod(input, NULL);

    inicializaCubo(&c, lado);

    printf("Tamanho do lado: %.2lf\n", tamanhoLado(&c));
    printf("Área: %.2lf\n", area(&c));
    printf("Volume: %.2lf\n", volume(&c));

    return 0;
}
