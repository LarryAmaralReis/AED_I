#include "abb.c"

int main () {
    header(1);

    ARVORE a;
    PACIENTE np;

    inicializarArvore(&a);

    np.nome = "Joao";
    np.idade = 2;

    np.cod_pac = 9;
    adicionar(&a, np);

    np.cod_pac = 5;
    adicionar(&a, np);

    np.cod_pac = 14;
    np.nome = "Antonio";
    adicionar(&a, np);

    np.cod_pac = 15;
    np.nome = "Sergio";
    np.idade = 5;
    adicionar(&a, np);

    np.cod_pac = 7;
    np.idade = 10;
    adicionar(&a, np);

    np.cod_pac = 2;
    adicionar(&a, np);
        
    np.cod_pac = 8;
    adicionar(&a, np);

    np.cod_pac = 6;
    adicionar(&a, np);

    //listarArvore(&a);

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

    visualizarArvore(&a);

    int altura = alturaArvore(a.raiz);

    printf("\nA altura da arvore e %d", altura);

    NO* minimo = buscarMinimo(a.raiz);
    printf("\nMinimo: %d", minimo->pac.cod_pac);

    NO* maximo = buscarMaximo(a.raiz);
    printf("\nMaximo: %d", maximo->pac.cod_pac);

    NO* sucessor = buscarSucessor(a.raiz, 7);
    printf("\nSucessor de 7: %d", sucessor->pac.cod_pac);

    NO* antecessor = buscarAntecessor(a.raiz, 7);
    printf("\nAntecessor de 7: %d", antecessor->pac.cod_pac);

    int balanceamento = verificarBalanceamento(a.raiz);

    printf("\nO balanceamento tem valor de: %d\n", balanceamento);

    exibirNiveis(a.raiz);

    int ehBinaria = verificarArvoreBinaria(a.raiz, INT_MIN, INT_MAX);

    if (ehBinaria) {
        printf("A estrutura atual e uma arvore binaria de busca.\n");
    } else {
        printf("A estrutura atual nao e uma arvore binaria de busca.\n");
    }

    NO* pacienteMenorIdade = encontrarMenorIdade(a.raiz);
    NO* pacienteMaiorIdade = encontrarMaiorIdade(a.raiz);

    if (pacienteMenorIdade) {
        printf("Paciente de menor idade: %s (%d anos)\n", pacienteMenorIdade->pac.nome, pacienteMenorIdade->pac.idade);
    } else {
        printf("Nenhum paciente encontrado.\n");
    }

    if (pacienteMaiorIdade) {
        printf("Paciente de maior idade: %s (%d anos)\n", pacienteMaiorIdade->pac.nome, pacienteMaiorIdade->pac.idade);
    } else {
        printf("Nenhum paciente encontrado.\n");
    }

    const char* nomeBusca = "Antonio";
    int comparacoes = 0;
    NO* pacienteEncontrado = encontrarPorNomeAux(a.raiz, nomeBusca, &comparacoes);

    if (pacienteEncontrado) {
        printf("Paciente encontrado: Código %d, Nome %s\n", pacienteEncontrado->pac.cod_pac, pacienteEncontrado->pac.nome);
        printf("Número de comparações feitas: %d\n", comparacoes);
    } else {
        printf("Paciente com nome '%s' não encontrado.\n", nomeBusca);
        printf("Número de comparações feitas: %d\n", comparacoes);
    }

    return 0;
}