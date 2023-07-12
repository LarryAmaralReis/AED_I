#include <stdio.h>
#include "int_hash_ligado.c"

int main() {
    TB_HASH tabela;
    inicializahash(tabela);

    inserir(tabela, 12);
    inserir(tabela, 44);
    inserir(tabela, 13);
    inserir(tabela, 88);
    inserir(tabela, 23);
    inserir(tabela, 94);
    inserir(tabela, 11);
    inserir(tabela, 39);
    inserir(tabela, 20);
    inserir(tabela, 16);
    inserir(tabela, 5);
    
    mostrarHash(tabela);

    return 0;
}