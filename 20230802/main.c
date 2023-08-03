#include "arv_avl_int.c"

int main() {
    ARVORE minhaArvore;
    inicializarArvore(&minhaArvore);

    adicionaAVL(&minhaArvore, 1);
    adicionaAVL(&minhaArvore, 2);
    adicionaAVL(&minhaArvore, 3);
    adicionaAVL(&minhaArvore, 4);
    adicionaAVL(&minhaArvore, 5);
    adicionaAVL(&minhaArvore, 6);
    adicionaAVL(&minhaArvore, 7);
    adicionaAVL(&minhaArvore, 15);
    adicionaAVL(&minhaArvore, 14);
    adicionaAVL(&minhaArvore, 13);
    adicionaAVL(&minhaArvore, 12);
    adicionaAVL(&minhaArvore, 11);
    adicionaAVL(&minhaArvore, 10);
    adicionaAVL(&minhaArvore, 9);
    adicionaAVL(&minhaArvore, 8);

    visualizarArvore(&minhaArvore);

    //listarArvore(&minhaArvore);

    return 0;
}
