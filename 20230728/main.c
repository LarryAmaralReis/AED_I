#include "arv_binaria.c"

int main() {
    ARVORE minhaArvore;
    inicializarArvore(&minhaArvore);

    char expression[] = "(a*((b-c)/d))";

    minhaArvore = construirArvore(expression);

    printf("Expressão infixa: ");
    infixa(&minhaArvore);

    printf("Expressão prefixa: ");
    prefixa(&minhaArvore);

    printf("Expressão posfixa: ");
    posfixa(&minhaArvore);

    printf("Resultado da expressão: %d\n", resultadoArvore(&minhaArvore));

    return 0;
}
