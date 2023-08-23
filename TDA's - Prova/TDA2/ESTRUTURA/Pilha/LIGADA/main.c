#include "pilha_ligada.c"

int main(){
    PILHA pilha;
    LIVRO lv;

    inicializarPilha(&pilha);

    lv = (LIVRO){1, "Titulo livro 1", "Autor livro 1", 340, 35.99};
    inserirLivro(&pilha, lv);

    lv = (LIVRO){2, "Titulo livro 2", "Autor livro 2", 445, 25.8};
    inserirLivro(&pilha, lv);

    lv = (LIVRO){3, "Titulo livro 3", "Autor livro 3", 1000, 100.75};
    inserirLivro(&pilha, lv);

    imprimirPilha(pilha);

    lv = firstLIVRO(&pilha);
    printf("\nTopo ISBN: %d", lv.isbn);

    ELEMENTO e;

    e = firstELEMENTO(&pilha);
    printf("\nTopo Autor: %s", e.liv.autor);

    imprimirPilha(pilha);

    LIVRO livroMaiorPaginas = encontrarLivroMaiorPaginas(&pilha);
    if (livroMaiorPaginas.qtd_paginas == 0) {
        printf("\nA pilha está vazia.");
    } else {
        printf("\nLivro com a maior quantidade de páginas:");
        printf("\nTítulo: %s", livroMaiorPaginas.titulo);
        printf("\nQuantidade de páginas: %d", livroMaiorPaginas.qtd_paginas);
    }

    imprimirPilha(pilha);

    LIVRO livroMenorPreco = encontrarLivroMenorPreco(&pilha);
    if (livroMenorPreco.preco == 0.0) {
        printf("\nA pilha está vazia.");
    } else {
        printf("\nLivro com o menor preço:");
        printf("\nTítulo: %s", livroMenorPreco.titulo);
        printf("\nPreço: %.2f", livroMenorPreco.preco);
    }

    calcularMediaPrecos(&pilha);

    imprimirPilha(pilha);

    int isbnRemover = 2;
    int removido = removerLivroPorISBN(&pilha, isbnRemover);
    if (removido) {
        printf("\nLivro com ISBN %d removido com sucesso.", isbnRemover);
    } else {
        printf("\nLivro com ISBN %d não encontrado na pilha.", isbnRemover);
    }

    imprimirPilha(pilha);

    const char *tituloRemover = "Livro A";
    removido = removerLivroPorTitulo(&pilha, tituloRemover);
    if (removido) {
        printf("\nLivro com título \"%s\" removido com sucesso.", tituloRemover);
    } else {
        printf("\nLivro com título \"%s\" não encontrado na pilha.", tituloRemover);
    }

    int pos = retornarPosicaoPorISBN(pilha, 3); 

    printf("\nO livro procurado esta na posicao: %d", pos);

    LIVRO* livroRemovidoPtr = excluirTopoEPegarLivro(&pilha);

    if (livroRemovidoPtr != NULL) {
        printf("\n-----------------------------------");
        printf("\n Livro removido:");
        printf("\n ISBN: %d", livroRemovidoPtr->isbn);
        printf("\n Titulo: %s", livroRemovidoPtr->titulo);
        printf("\n Autor: %s", livroRemovidoPtr->autor);
        printf("\n Quantidade de paginas: %d", livroRemovidoPtr->qtd_paginas);
        printf("\n Preco do livro: %f", livroRemovidoPtr->preco);

        free(livroRemovidoPtr);
    }
    
    LIVRO* primeiroLivroPtr = primeiroLIVRO(&pilha);

    if (primeiroLivroPtr != NULL) {
        printf("\n-----------------------------------\n");
        printf("Primeiro livro:\n");
        printf("ISBN: %d\n", primeiroLivroPtr->isbn);
        printf("Titulo: %s\n", primeiroLivroPtr->titulo);
        printf("Autor: %s\n", primeiroLivroPtr->autor);
        printf("Quantidade de paginas: %d\n", primeiroLivroPtr->qtd_paginas);
        printf("Preco do livro: %f\n", primeiroLivroPtr->preco);
    }

    LIVRO livroRemovido = excluirTopoEPegarLivro1(&pilha);
    printf("\n-----------------------------------\n");
    printf("Livro removido:\n");
    printf("ISBN: %d\n", livroRemovido.isbn);
    printf("Titulo: %s\n", livroRemovido.titulo);
    printf("Autor: %s\n", livroRemovido.autor);
    printf("Quantidade de paginas: %d\n", livroRemovido.qtd_paginas);
    printf("Preco do livro: %f\n", livroRemovido.preco);

    ELEMENTO* primeiroElementoPtr = primeiroELEMENTO(&pilha);

    if (primeiroElementoPtr != NULL) {

        LIVRO primeiroLivro = primeiroElementoPtr->liv;
        printf("Primeiro livro elemento:\n");
        printf("ISBN: %d\n", primeiroLivro.isbn);
        printf("Titulo: %s\n", primeiroLivro.titulo);
        printf("Autor: %s\n", primeiroLivro.autor);
        printf("Quantidade de paginas: %d\n", primeiroLivro.qtd_paginas);
        printf("Preco do livro: %f\n", primeiroLivro.preco);
    }

}