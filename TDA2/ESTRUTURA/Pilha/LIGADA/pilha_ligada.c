#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_ligada.h"

void inicializarPilha (PILHA *p){
    p->topo = NULL;
}

void reinicializarPilha (PILHA *p){
    ELEMENTO *apagar;
    ELEMENTO *elemento = p->topo;
    while (elemento != NULL){
        apagar = elemento;
        elemento = elemento->proximo;
        free(apagar);
    }
    p->topo = NULL;
}

int inserirLivro (PILHA *p, LIVRO novo_livro){
    ELEMENTO *i;
    i = malloc (sizeof(ELEMENTO));
    if (i == NULL) return 0;
    i->liv = novo_livro;
    i->proximo = p->topo;
    p->topo = i;
    return 1;
}

int excluirLivro (PILHA *p){
    if (p->topo == NULL) return 0;
    ELEMENTO *i = p->topo;
    p->topo = p->topo->proximo;
    free(i);
    return 1;
}

ELEMENTO firstELEMENTO (PILHA *p){
    return *(p->topo);
}

ELEMENTO *primeiroELEMENTO(PILHA *p) {
    //if (p->topo == NULL) return NULL;
    return p->topo;
}

LIVRO firstLIVRO (PILHA *p){
    return p->topo->liv;
}

LIVRO *primeiroLIVRO(PILHA *p) {
    //if (p->topo == NULL) return NULL;
    return &(p->topo->liv);
}

int imprimirPilha (PILHA p){
    if (p.topo == NULL) return 0;
    ELEMENTO *i = p.topo;
    printf("\n-------------PILHA-------------");
    while (i != NULL){
        printf("\nISBN: %d", i->liv.isbn);
        printf("\nTitulo: %s", i->liv.titulo);
        printf("\nAutor: %s", i->liv.autor);
        printf("\nQuantidade de paginas: %d", i->liv.qtd_paginas);
        printf("\nPreco do livro: %f", i->liv.preco);
        printf("\n-------------------------------");
        i = i->proximo;
    }
    return 1;
}

LIVRO encontrarLivroMaiorPaginas(PILHA *p) {
    if (p->topo == NULL) {
        // Lidar com o caso em que a pilha está vazia
        LIVRO livroVazio;
        livroVazio.qtd_paginas = 0;
        return livroVazio;
    }

    PILHA pilhaAuxiliar;
    inicializarPilha(&pilhaAuxiliar);

    LIVRO livroMaiorPaginas = p->topo->liv;

    while (p->topo != NULL) {
        if (p->topo->liv.qtd_paginas > livroMaiorPaginas.qtd_paginas) {
            livroMaiorPaginas = p->topo->liv;
        }
        inserirLivro(&pilhaAuxiliar, p->topo->liv);
        excluirLivro(p);
    }

    while (pilhaAuxiliar.topo != NULL) {
        inserirLivro(p, pilhaAuxiliar.topo->liv);
        excluirLivro(&pilhaAuxiliar);
    }

    return livroMaiorPaginas;
}

LIVRO encontrarLivroMenorPreco(PILHA *p) {
    if (p->topo == NULL) {
        // Lidar com o caso em que a pilha está vazia
        LIVRO livroVazio;
        livroVazio.preco = 0.0;
        return livroVazio;
    }

    PILHA pilhaAuxiliar;
    inicializarPilha(&pilhaAuxiliar);

    LIVRO livroMenorPreco = p->topo->liv;

    while (p->topo != NULL) {
        if (p->topo->liv.preco < livroMenorPreco.preco) {
            livroMenorPreco = p->topo->liv;
        }
        inserirLivro(&pilhaAuxiliar, p->topo->liv);
        excluirLivro(p);
    }

    while (pilhaAuxiliar.topo != NULL) {
        inserirLivro(p, pilhaAuxiliar.topo->liv);
        excluirLivro(&pilhaAuxiliar);
    }

    return livroMenorPreco;
}

void calcularMediaPrecos(PILHA *p) {
    if (p->topo == NULL) {
        return;
    }

    float somaPrecos = 0.0;
    int totalLivros = 0;

    PILHA pilhaAuxiliar;
    inicializarPilha(&pilhaAuxiliar);

    while (p->topo != NULL) {
        somaPrecos += p->topo->liv.preco;
        totalLivros++;
        inserirLivro(&pilhaAuxiliar, p->topo->liv);
        excluirLivro(p);
    }

    float mediaPrecos = somaPrecos / totalLivros;

    LIVRO livroMedia;
    livroMedia.isbn = -1;  // Utilizamos um ISBN inválido para representar a média
    livroMedia.titulo = "Média de Preços";
    livroMedia.autor = "Sistema";
    livroMedia.qtd_paginas = -1;
    livroMedia.preco = mediaPrecos;

    //inserirLivro(p, livroMedia);

    // Restaurar a pilha original
    while (pilhaAuxiliar.topo != NULL) {
        inserirLivro(p, pilhaAuxiliar.topo->liv);
        excluirLivro(&pilhaAuxiliar);
    }

    inserirLivro(p, livroMedia);
}

int removerLivroPorISBN(PILHA *p, int isbn) {
    if (p->topo == NULL) {
        // Pilha vazia
        return 0;
    }

    PILHA pilhaAuxiliar;
    inicializarPilha(&pilhaAuxiliar);

    // Desempilhar e armazenar os livros até encontrar o livro com o ISBN
    while (p->topo != NULL && p->topo->liv.isbn != isbn) {
        inserirLivro(&pilhaAuxiliar, p->topo->liv);
        excluirLivro(p);
    }

    if (p->topo == NULL) {
        // Livro com o ISBN não encontrado
        while (pilhaAuxiliar.topo != NULL) {
            inserirLivro(p, pilhaAuxiliar.topo->liv);
            excluirLivro(&pilhaAuxiliar);
        }
        return 0;
    }

    // Remover o livro com o ISBN desejado
    excluirLivro(p);

    // Restaurar os livros anteriores à remoção na pilha original
    while (pilhaAuxiliar.topo != NULL) {
        inserirLivro(p, pilhaAuxiliar.topo->liv);
        excluirLivro(&pilhaAuxiliar);
    }

    return 1;
}

int removerLivroPorTitulo(PILHA *p, const char *titulo) {
    if (p->topo == NULL) {
        // Pilha vazia
        return 0;
    }

    PILHA pilhaAuxiliar;
    inicializarPilha(&pilhaAuxiliar);

    // Desempilhar e armazenar os livros até encontrar o livro com o título
    while (p->topo != NULL && strcmp(p->topo->liv.titulo, titulo) != 0) {
        inserirLivro(&pilhaAuxiliar, p->topo->liv);
        excluirLivro(p);
    }

    if (p->topo == NULL) {
        // Livro com o título não encontrado
        while (pilhaAuxiliar.topo != NULL) {
            inserirLivro(p, pilhaAuxiliar.topo->liv);
            excluirLivro(&pilhaAuxiliar);
        }
        return 0;
    }

    // Remover o livro com o título desejado
    excluirLivro(p);

    // Restaurar os livros anteriores à remoção na pilha original
    while (pilhaAuxiliar.topo != NULL) {
        inserirLivro(p, pilhaAuxiliar.topo->liv);
        excluirLivro(&pilhaAuxiliar);
    }

    return 1;
}

int retornarPosicaoPorISBN(PILHA p, int isbn) {
    PILHA pilhaAuxiliar;
    inicializarPilha(&pilhaAuxiliar);

    int posicao = 1;
    int posicaoEncontrada = -1;

    while (p.topo != NULL) {
        if (p.topo->liv.isbn == isbn) {
            posicaoEncontrada = posicao;
        }

        inserirLivro(&pilhaAuxiliar, p.topo->liv);
        excluirLivro(&p);
        posicao++;
    }

    while (pilhaAuxiliar.topo != NULL) {
        inserirLivro(&p, pilhaAuxiliar.topo->liv);
        excluirLivro(&pilhaAuxiliar);
    }

    return posicaoEncontrada;
}

LIVRO* excluirTopoEPegarLivro(PILHA *p) {
    if (p->topo == NULL) return NULL;
    LIVRO* livroExcluido = (LIVRO*)malloc(sizeof(LIVRO));
    if (livroExcluido == NULL) return NULL;
    *livroExcluido = p->topo->liv;
    ELEMENTO *e = p->topo;
    p->topo = p->topo->proximo;
    free(e);
    return livroExcluido;
}

LIVRO excluirTopoEPegarLivro1(PILHA *p){
    if (p->topo == NULL) {
        LIVRO livroVazio;
        livroVazio.isbn = -1;
        livroVazio.titulo = "Pilha Vazia";
        livroVazio.autor = "";
        livroVazio.qtd_paginas = 0;
        livroVazio.preco = 0.0;
        return livroVazio;
    }
    LIVRO livroExcluido = p->topo->liv;
    ELEMENTO *temp = p->topo;
    p->topo = p->topo->proximo;
    free(temp);
    return livroExcluido;
}

