#include "arv_binaria.c"

int main() {
    ARVORE minhaArvore;
    inicializarArvore(&minhaArvore);

    adiciona(&minhaArvore, 24);
    adiciona(&minhaArvore, 10);
    adiciona(&minhaArvore, 32);
    adiciona(&minhaArvore, 5);
    adiciona(&minhaArvore, 12);
    adiciona(&minhaArvore, 29);
    adiciona(&minhaArvore, 35);

    printf("Pre ordem: ");
    pre_ordem(minhaArvore.raiz);
    printf("\n");

    printf("In ordem: ");
    in_ordem(minhaArvore.raiz);
    printf("\n");

    printf("Pos ordem: ");
    pos_ordem(minhaArvore.raiz);
    printf("\n");

    reinicializarArvore(&minhaArvore);

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