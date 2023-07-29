#include "arv_binaria.c"

int main() {
    char expressao[] = "a*((b-c)/d)";
    NO* raiz = infixToExpressionTree(expressao);

    printf("Expressão infixa: ");
    Infixa(raiz);
    printf("\n");

    printf("Expressão posfixa: ");
    Posfixa(raiz);
    printf("\n");

    printf("Expressão prefixa: ");
    Prefixa(raiz);
    printf("\n");

    int resultado = evaluateExpression(raiz);
    printf("Resultado da expressão: %d\n", resultado);

    return 0;
}
