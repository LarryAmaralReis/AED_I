#include "abb.c"

int main () {
    header(1);

    ARVORE a;

    inicializarArvore(&a);

    adicionar(&a, 9);
    adicionar(&a, 5);
    adicionar(&a, 14);
    adicionar(&a, 15);
    adicionar(&a, 7);
    adicionar(&a, 2);
    adicionar(&a, 8);
    adicionar(&a, 6);

    //listarArvore(&a);

    visualizarArvore(&a);

    excluirNo(&a, 9);
    excluirNo(&a, 8);

    visualizarArvore(&a);

    pre_ordem(a.raiz);
    printf("\n");
    in_ordem(a.raiz);
    printf("\n");
    pos_ordem(a.raiz);

    int nos = numeroNos(a.raiz);
    printf("\nA arvore tem %d nos", nos);

    int folhas = numeroFolhas(a.raiz);
    printf("\nNumero de folhas: %d", folhas);

    int internos = numeroNosInternos(a.raiz) - 1;
    printf("\nNumero de nos internos: %d", internos);

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

    int ehBinaria = verificarArvoreBinaria(a.raiz, INT_MIN, INT_MAX);

    if (ehBinaria) {
        printf("A estrutura atual e uma arvore binaria de busca.\n");
    } else {
        printf("A estrutura atual nao e uma arvore binaria de busca.\n");
    }

    buscarEImprimirInfo(&a, 15);

    return 0;
}