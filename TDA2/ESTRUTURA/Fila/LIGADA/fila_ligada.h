#ifndef FILA_LIGADA_H
#define FILA_LIGADA_H

typedef struct {
    int cod_pac;
    char *nome;
    char *cpf;
    int idade;
} PACIENTE;

typedef struct aux {
    PACIENTE pac;
    struct aux *proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO *inicio;
    ELEMENTO *fim;
} FILA;

void inicializarFila (FILA *f);
void reinicializarFila (FILA *f);
int inserirPaciente (FILA *f, PACIENTE novo_paciente);
int excluirPaciente (FILA *f);
ELEMENTO firstELEMENTO (FILA *f);
PACIENTE firstPACIENTE (FILA *f);
int imprimirFila (FILA f);
PACIENTE pacienteMaiorIdade(FILA *f);
PACIENTE pacienteMenorCodigo(FILA *f);
void inserirMediaIdades(FILA *f);
void removerPorCodigo(FILA *f, int codigo);
int posicaoPorCodigo(FILA *f, int codigo);
int posicaoPorCPF(FILA *f, const char *cpf);

#endif