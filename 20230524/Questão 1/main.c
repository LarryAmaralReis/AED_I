#include <stdio.h>
#include "lista.h"

int main() {
    LISTA lista;
    // 1. Perguntar ao usuário o tamanho de uma LISTA, criar a lista e preencher os valores da LISTA de forma não ordenada.
    int tam;
    printf("\nQual o tamanho da lista?\n");
    scanf("%d", &tam);
    criarLista(&lista, tam);
    inserirElementos(&lista);

    // 2. Imprimir todos os elementos da LISTA.
    imprimirLista(&lista);
    imprimirListaRecursiva(&lista);

    // 3. Perguntar para o usuário sobre um número que ele quer buscar na LISTA (inserir como teste um número que existe na LISTA e depois um que não esteja na LISTA) e mostrar o resultado da busca sequencial.
    //Buscar Elemento
    int i = 0;
    for (i = 0; i < 2; i++) {
        int elemento;
        printf("Numero %d deseja buscar:\n", i + 1);
        scanf("%d", &elemento);
        printf("Resultado da busca = %d\n", buscarElementoSequencial(&lista, elemento));
    }
    /*
        8. Imprimir o maior elemento da primeira LISTA.
        9. Imprimir o menor elemento da primeira LISTA.
        10. Imprimir a soma dos elementos da primeira LISTA.
        11. Imprimir o produto dos elementos da primeira LISTA.
    */
    printf("Maior elemento (iterativo): %d\n", buscarMaiorElementoIterativo(&lista));
    printf("Maior elemento (recursivo): %d\n", buscarMaiorElementoRecursivo(&lista, 0));
    printf("Menor elemento (iterativo): %d\n", buscarMenorElementoIterativo(&lista));
    printf("Menor elemento (recursivo): %d\n", buscarMenorElementoRecursivo(&lista, 0));
    printf("Soma (iterativa): %d\n", somaIterativa(&lista));
    printf("Soma (recursiva): %d\n", somaRecursiva(&lista, 0));
    printf("Produto (iterativo): %d\n", produtoIterativo(&lista));
    printf("Produto (recursivo): %d\n", produtoRecursivo(&lista, 0));

    liberaLista(&lista);
    // 4. Cria uma segunda LISTA de tamanho 30 e preencher seus elementos de forma ordenada.
    criarLista(&lista, 30);
    inserirElementosOrdenados(&lista);

    // 5. Imprimir todos os elementos da segunda LISTA.
    imprimirLista(&lista);
    imprimirListaRecursiva(&lista);

    // 6. Perguntar para o usuário sobre um número que ele quer buscar na segunda LISTA (inserir como teste um número que existe na LISTA e depois um que não exista) e mostrar o resultado da busca sequencial, busca sequencial ordenada e busca binaria interativa e recursiva.
    for (i = 0; i < 2; i++) {
        int elemento;
        printf("Numero %d deseja buscar:\n", i + 1);
        scanf("%d", &elemento);
        printf("Resultado da busca sequencial = %d\n", buscarElementoSequencial(&lista, elemento));
        printf("Resultado da busca sequencial ordenada = %d\n", buscarElementoSequencialOrdenado(&lista, elemento));
        printf("Resultado da busca binaria iterativa = %d\n", buscarElementoBinarioIterativo(&lista, elemento));
        printf("Resultado da busca binaria recursiva = %d\n",
               buscarElementoBinarioRecursivo(&lista, elemento, 0, lista.tam_vetor - 1,0));
    }

    // Liberar o espaço na memória da lista
    liberaLista(&lista);

    return 0;
}