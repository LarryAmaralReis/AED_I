#include "int_hash_array.c"

int main() {
    TB_HASH tabela;
    int chaves[] = {365, 112, 180, 213, 13, 27};
    int numChaves = sizeof(chaves) / sizeof(chaves[0]);

    printf("Sem resolução de colisão.");
    inicializaHash(tabela);
    for (int i = 0; i < numChaves; i++) {
        inserir(tabela, chaves[i]);
    }
    mostrarHash(tabela);

    printf("a) Sondagem linear, função hash:  h(k)= (k+i) % M");
    inicializaHash(tabela);
    for (int i = 0; i < numChaves; i++) {
        inserirLinear (tabela, chaves[i]);
    }
    mostrarHash(tabela);

    printf("b) Sondagem quadrática, função hash:  h(k)= (k+i²) % M");
    inicializaHash(tabela);
    for (int i = 0; i < numChaves; i++) {
        inserirQuadraticaB (tabela, chaves[i]);
    }
    mostrarHash(tabela);

    printf("c) Sondagem quadrática, função hash: h(k)= (k+2i+i²) % M");
    inicializaHash(tabela);
    for (int i = 0; i < numChaves; i++) {
        inserirQuadraticaC (tabela, chaves[i]);
    }
    mostrarHash(tabela);

    printf("d) Hash duplo, função hash: h1(k) = k%M, função hash 2:  h2(k) = 7 − (k % 7)");
    inicializaHash(tabela);
    for (int i = 0; i < numChaves; i++) {
        inserirDuplo (tabela, chaves[i]);
    }
    mostrarHash(tabela);
    
    return 0;
}