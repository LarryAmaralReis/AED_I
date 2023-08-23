#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct {
    int cod_pac;
    char* nome;
    char* cpf;
    int idade;
} PACIENTE;

typedef struct aux {
    PACIENTE pac;
    struct aux *esquerda;
    struct aux *direita;
} NO;

typedef struct {
    NO *raiz;
} ARVORE;

void header(int exercicio);
void inicializarArvore (ARVORE *a);
NO *inserir (NO* raiz, NO* no);
int adicionarAux (ARVORE *a, NO* novo);
int adicionar (ARVORE *a, PACIENTE p);
void listarNos (NO* raiz);
void listarArvore (ARVORE *a);
NO* contem (NO* raiz, int codpc);
NO* buscar (ARVORE* a, int codpc);
int numeroNos (NO* raiz);
NO* buscarNo (NO* raiz, int codpc, NO** pai);
int excluirNo (NO* raiz, int codpc);
void pre_ordem (NO* raiz);
void in_ordem (NO* raiz);
void pos_ordem (NO* raiz);
void printArvore(NO *raiz, int nivel);
void visualizarArvore(ARVORE *a);

int numeroFolhas(NO* raiz);
int numeroNosInternos(NO* raiz);
int alturaArvore(NO* raiz);
NO* buscarMinimo(NO* raiz);
NO* buscarMaximo(NO* raiz);
NO* buscarSucessor(NO* raiz, int chave);
NO* buscarAntecessor(NO* raiz, int chave);
int verificarBalanceamento(NO* raiz);
void exibirNivel(NO* raiz, int nivelAtual, int nivelDesejado);
int verificarArvoreBinaria(NO* raiz, int min, int max);

void encontrarMenorIdadeAux(NO* raiz, NO** pacienteMenorIdade, int* menorIdade);
NO* encontrarMenorIdade(NO* raiz);
void encontrarMaiorIdadeAux(NO* raiz, NO** pacienteMaiorIdade, int* maiorIdade);
NO* encontrarMaiorIdade(NO* raiz);

#endif