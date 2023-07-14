#include "int_hash_array.c"

int main() {
    TB_HASH tabela;
    int chaves[] = {365, 112, 180, 213, 13, 27};
    int numChaves = sizeof(chaves) / sizeof(chaves[0]);

    //printf("Sem resolução de colisão.");
    //inicializaHash(tabela);
    //for (int i = 0; i < numChaves; i++) {
    //    inserir(tabela, chaves[i]);
    //}
    //mostrarHash(tabela);

    printf("Sondagem linear");
    inicializaHash(tabela);
    for (int i = 0; i < numChaves; i++) {
        inserirLinear (tabela, chaves[i]);
    }
    mostrarHash(tabela);
    
    //excluir(tabela, 365);
    removerPorPosicao(tabela, 2);

    mostrarHash(tabela);

    printf("\n Maior numero: %d", encontrarMaior(tabela));
    printf("\n Menor numero: %d", encontrarMenor(tabela));
    printf("\n Media numero: %f", calcularMedia(tabela));
    printf("\n Este numero esta na posicao: %d", buscarPosicaoPorNumero(tabela, 27));
    return 0;
}