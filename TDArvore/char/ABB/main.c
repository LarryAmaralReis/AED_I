#include "abb.c"

int main () {
    header(1);

    ARVORE a;

    inicializarArvore(&a);

    adicionar(&a, 'g');
    adicionar(&a, 'e');
    adicionar(&a, 'c');
    adicionar(&a, 'y');
    adicionar(&a, 'j');
    adicionar(&a, 'h');
    adicionar(&a, 't');
    adicionar(&a, '2');
    adicionar(&a, 'q');

    printf("Adicionando 'a'\n");
    adicionar(&a, 'a');
    printf("Adicionando 'z'\n");
    adicionar(&a, 'z');
    printf("Adicionando 'l'\n");
    adicionar(&a, 'l');
    printf("Adicionando 'r'\n");
    adicionar(&a, 'r');
    printf("Adicionando '1'\n");
    adicionar(&a, '1');
    printf("Adicionando '4'\n");
    adicionar(&a, '4');
    printf("Adicionando '7'\n");
    adicionar(&a, '7');
    printf("Adicionando '6'\n");
    adicionar(&a, '6');
    printf("Adicionando '8'\n");
    adicionar(&a, '8');
    printf("Adicionando '9'\n");
    adicionar(&a, '9');
    printf("Adicionando '0'\n");
    adicionar(&a, '0');
    printf("Adicionando 'b'\n");
    adicionar(&a, 'b');

    visualizarArvore(&a);
    //"listarArvore(&a);
    excluirNo(&a, 'g');

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
    printf("\nMinimo: %c", minimo->chave);

    NO* maximo = buscarMaximo(a.raiz);
    printf("\nMaximo: %c", maximo->chave);

    NO* sucessor = buscarSucessor(a.raiz, '7');
    printf("\nSucessor de '7': %c", sucessor->chave);

    NO* antecessor = buscarAntecessor(a.raiz, '7');
    printf("\nAntecessor de '7': %c", antecessor->chave);

    int balanceamento = verificarBalanceamento(a.raiz);

    printf("\nO balanceamento tem valor de: %d\n", balanceamento);

    exibirNiveis(a.raiz);

    int ehBinaria = verificarArvoreBinaria(a.raiz, INT_MIN, INT_MAX);

    if (ehBinaria) {
        printf("A estrutura atual e uma arvore binaria de busca.\n");
    } else {
        printf("A estrutura atual nao e uma arvore binaria de busca.\n");
    }

    NO* pai = encontrarPai(a.raiz, 'j');
    if (pai != NULL) {
        printf("\nPai de 'j': %c", pai->chave);
    } else {
        printf("\nNao ha pai para 'j'");
    }

    NO* filhoMenor = encontrarFilhoMenor(a.raiz, 'h');
    if (filhoMenor != NULL) {
        printf("\nFilho menor de 'h': %c", filhoMenor->chave);
    } else {
        printf("\nNao ha filho menor para 'h'");
    }

    NO* filhoMaior = encontrarFilhoMaior(a.raiz, 'e');
    if (filhoMaior != NULL) {
        printf("\nFilho maior de 'e': %c", filhoMaior->chave);
    } else {
        printf("\nNao ha filho maior para 'e'");
    }

    return 0;
}