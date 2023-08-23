#include "avl.c"

int main() {
    header(1);

    ARVORE a;

    inicializarArvore(&a);

    adicionarAVL(&a, 'g');
    adicionarAVL(&a, 'e');
    adicionarAVL(&a, 'c');
    adicionarAVL(&a, 'y');
    adicionarAVL(&a, 'j');
    adicionarAVL(&a, 'h');
    adicionarAVL(&a, 't');
    adicionarAVL(&a, '2');
    adicionarAVL(&a, 'q');

    printf("Adicionando 'a'\n");
    adicionarAVL(&a, 'a');
    printf("Adicionando 'z'\n");
    adicionarAVL(&a, 'z');
    printf("Adicionando 'l'\n");
    adicionarAVL(&a, 'l');
    printf("Adicionando 'r'\n");
    adicionarAVL(&a, 'r');
    printf("Adicionando '1'\n");
    adicionarAVL(&a, '1');
    printf("Adicionando '4'\n");
    adicionarAVL(&a, '4');
    printf("Adicionando '7'\n");
    adicionarAVL(&a, '7');
    printf("Adicionando '6'\n");
    adicionarAVL(&a, '6');
    printf("Adicionando '8'\n");
    adicionarAVL(&a, '8');
    printf("Adicionando '9'\n");
    adicionarAVL(&a, '9');
    printf("Adicionando '0'\n");
    adicionarAVL(&a, '0');
    printf("Adicionando 'b'\n");
    adicionarAVL(&a, 'b');

    removerAVL(&a, 't');
    removerAVL(&a, '7');
    removerAVL(&a, '6');

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

    NO* sucessor = buscarSucessor(a.raiz, 'g');
    printf("\nSucessor de 'g': %c", sucessor->chave);

    NO* antecessor = buscarAntecessor(a.raiz, 'g');
    printf("\nAntecessor de 'g': %c", antecessor->chave);

    int balanceamento = verificarBalanceamento(a.raiz);

    printf("\nO balanceamento tem valor de: %d\n", balanceamento);

    exibirNiveis(a.raiz);

    return 0;
}
