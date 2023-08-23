#include "avl.c"

int main() {
    header(1);

    ARVORE a;

    inicializarArvore(&a);

    adicionarAVL(&a, 7);
    adicionarAVL(&a, 5);
    adicionarAVL(&a, 3);
    adicionarAVL(&a, 25);
    adicionarAVL(&a, 10);
    adicionarAVL(&a, 8);
    adicionarAVL(&a, 20);
    adicionarAVL(&a, 50);
    adicionarAVL(&a, 30);

    printf("Adicionando 1\n");
    adicionarAVL(&a, 1);
    printf("Adicionando 64\n");
    adicionarAVL(&a, 64);
    printf("Adicionando 12\n");
    adicionarAVL(&a, 12);
    printf("Adicionando 18\n");
    adicionarAVL(&a, 18);
    printf("Adicionando 66\n");
    adicionarAVL(&a, 66);
    printf("Adicionando 38\n");
    adicionarAVL(&a, 38);
    printf("Adicionando 95\n");
    adicionarAVL(&a, 95);
    printf("Adicionando 58\n");
    adicionarAVL(&a, 58);
    printf("Adicionando 59\n");
    adicionarAVL(&a, 59);
    printf("Adicionando 70\n");
    adicionarAVL(&a, 70);
    printf("Adicionando 68\n");
    adicionarAVL(&a, 68);
    printf("Adicionando 39\n");
    adicionarAVL(&a, 39);
    printf("Adicionando 62\n");
    adicionarAVL(&a, 62);
    printf("Adicionando 60\n");
    adicionarAVL(&a, 60);

    removerAVL(&a, 50);
    removerAVL(&a, 39);
    removerAVL(&a, 38);

    visualizarArvore(&a);

    pre_ordem(a.raiz);
    printf("\n");
    in_ordem(a.raiz);
    printf("\n");
    pos_ordem(a.raiz);

    //listarArvore(&a);
    
    int nos = numeroNos(a.raiz);
    printf("\nA arvore tem %d nos", nos);

    int folhas = numeroFolhas(a.raiz);
    printf("\nNumero de folhas: %d", folhas);

    int internos = numeroNosInternos(a.raiz) - 1;
    printf("\nNumero de nos internos: %d", internos);

    visualizarArvore(&a);

    int altura = alturaArvore(a.raiz);

    printf("\nA altura da arvore e %d", altura);

    NO* minimo = buscarMinimo(a.raiz);
    printf("\nMinimo: %d", minimo->chave);

    NO* maximo = buscarMaximo(a.raiz);
    printf("\nMaximo: %d", maximo->chave);

    NO* sucessor = buscarSucessor(a.raiz, 7);
    printf("\nSucessor de 7: %d", sucessor->chave);

    NO* antecessor = buscarAntecessor(a.raiz, 7);
    printf("\nAntecessor de 7: %d", antecessor->chave);

    int balanceamento = verificarBalanceamento(a.raiz);

    printf("\nO balanceamento tem valor de: %d\n", balanceamento);

    exibirNiveis(a.raiz);

    return 0;
}
