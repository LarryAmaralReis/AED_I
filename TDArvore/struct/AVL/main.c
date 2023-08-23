#include "avl.c"

int main() {
    header(1);

    ARVORE a;
    PACIENTE np;

    np.nome = "Joao";
    np.cpf = "000.000.000-28";
    np.idade = 20;

    inicializarArvore(&a);

    np.cod_pac = 7;
    adicionarAVL(&a, np);
    np.cod_pac = 5;
    adicionarAVL(&a, np);
    np.cod_pac = 25;
    adicionarAVL(&a, np);
    np.cod_pac = 3;
    adicionarAVL(&a, np);
    np.cod_pac = 10;
    adicionarAVL(&a, np);
    np.cod_pac = 50;
    adicionarAVL(&a, np);
    np.cod_pac = 8;
    adicionarAVL(&a, np);
    np.cod_pac = 20;
    adicionarAVL(&a, np);
    np.cod_pac = 30;
    adicionarAVL(&a, np);

    visualizarArvore(&a);

    //listarArvore(&a);

    return 0;
}
