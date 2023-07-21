#ifndef PILHA_LIGADA_H
#define PILHA_LIGADA_H

typedef struct {
    int isbn;
    char *titulo;
    char *autor;
    int qtd_paginas;
    float preco;
} LIVRO;

typedef struct aux {
    LIVRO liv;
    struct aux *proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO *topo;
} PILHA;

void inicializarPilha (PILHA *p);
void reinicializarPilha (PILHA *p);
int inserirLivro (PILHA *p, LIVRO novo_livro);
int excluirLivro (PILHA *p);
ELEMENTO firstELEMENTO (PILHA *p);
LIVRO firstLIVRO (PILHA *p);
LIVRO* primeiroLIVRO(PILHA *p);
ELEMENTO* primeiroELEMENTO(PILHA *p);
int imprimirPilha (PILHA p);
LIVRO encontrarLivroMaiorPaginas(PILHA *p);
LIVRO encontrarLivroMenorPreco(PILHA *p);
void calcularMediaPrecos(PILHA *p);
int removerLivroPorISBN(PILHA *p, int isbn);
int retornarPosicaoPorISBN(PILHA p, int isbn);
LIVRO* excluirTopoEPegarLivro(PILHA *p);
LIVRO excluirTopoEPegarLivro1(PILHA *p);

#endif