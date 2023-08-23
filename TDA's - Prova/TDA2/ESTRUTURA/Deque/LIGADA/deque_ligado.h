#ifndef DEQUE_LIGADO_H
#define DEQUE_LIGADO_H

typedef struct {
    int cod_pac;
    char *nome;
    char *cpf;
    int idade;
} PACIENTE;

typedef struct aux {
    PACIENTE pac;
    struct aux *anterior;
    struct aux *proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO *cabeca;
} DEQUE;

void inicilizarDeque (DEQUE *d);
void reinicializarDeque (DEQUE *d);
void mostrarDeque (DEQUE *d);
int inserirPacienteFim (DEQUE *d, PACIENTE novo_paciente);
int inserirPacienteInicio (DEQUE *d, PACIENTE novo_paciente);
int excluirPacienteInicio (DEQUE *d);
int excluirPacienteFim (DEQUE *d);
//int tamanho (DEQUE *d);
//int excluirPacienteInicioP (DEQUE *d, PACIENTE *p);
PACIENTE getPacienteInicio(DEQUE *d);
PACIENTE getPacienteFim(DEQUE *d);
PACIENTE getPacienteMaiorIdade(DEQUE *d);
PACIENTE getPacienteMenorCodigo(DEQUE *d);
void calcularMediaInserirInicio(DEQUE *d);
int excluirPacientePorCodigo(DEQUE *d, int codigo);
int buscarPosicaoPorCPF(DEQUE *d, const char *cpf);

#endif