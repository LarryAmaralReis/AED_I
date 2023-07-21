#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque_ligado.h"


void inicializarDeque (DEQUE *d){
    d->cabeca = malloc (sizeof(ELEMENTO));
    d->cabeca->anterior = d->cabeca;
    d->cabeca->proximo = d->cabeca;
}

void reinicializarDeque (DEQUE *d){
    ELEMENTO *apagar;
    ELEMENTO *elemento = d->cabeca->proximo;
    while (elemento != d->cabeca){
        apagar = elemento;
        elemento = elemento->proximo;
        free(apagar);
    }
    d->cabeca->anterior = d->cabeca;
    d->cabeca->proximo = d->cabeca;
}

void mostrarDeque (DEQUE *d){
    printf("\n--------------------------");
    ELEMENTO *i = d->cabeca->proximo;
    while (i != d->cabeca ){
        printf("\n--------------------------");
        printf("\n Paciente: %d", i);
        printf("\n Codigo do paciente: %d", i->pac.cod_pac);
        printf("\n Nome: %s", i->pac.nome);
        printf("\n CPF: %s", i->pac.cpf);
        printf("\n Idade: %d", i->pac.idade);
        i = i->proximo;
    }
}

int inserirPacienteInicio (DEQUE *d, PACIENTE novo_paciente){
    ELEMENTO *i;
    i = malloc(sizeof (ELEMENTO));
    i->pac = novo_paciente;
    i->proximo = d->cabeca->proximo;
    i->anterior = d->cabeca;
    d->cabeca->proximo = i;
    i->proximo->anterior = i;
}

int inserirPacienteFim (DEQUE *d, PACIENTE novo_paciente){
    ELEMENTO *i;
    i = malloc(sizeof (ELEMENTO));
    i->pac = novo_paciente;
    i->proximo = d->cabeca;
    i->anterior = d->cabeca->anterior;
    d->cabeca->anterior = i;
    i->anterior->proximo = i;
}

int excluirPacienteInicio (DEQUE *d){
    if (d->cabeca->proximo == d->cabeca) return 0;
    ELEMENTO *i = d->cabeca->proximo;
    d->cabeca->proximo = i->proximo;
    i->proximo->anterior = d->cabeca;
    free(i);
    return 1;
}

int excluirPacienteFim (DEQUE *d){
    if (d->cabeca->proximo == d->cabeca) return 0;
    ELEMENTO *i = d->cabeca->anterior;
    d->cabeca->anterior = i->anterior;
    i->anterior->proximo = d->cabeca;
    free(i);
    return 1;
}

PACIENTE getPacienteInicio(DEQUE *d) {
    if (d->cabeca->proximo == d->cabeca) exit(EXIT_FAILURE); // or handle the error in a different way
    return d->cabeca->proximo->pac;
}

PACIENTE getPacienteFim(DEQUE *d) {
    if (d->cabeca->anterior == d->cabeca) exit(EXIT_FAILURE); // or handle the error in a different way
    return d->cabeca->anterior->pac;
}

PACIENTE getPacienteMaiorIdade(DEQUE *d) {
    if (d->cabeca->proximo == d->cabeca)
        exit(EXIT_FAILURE); // ou trate o erro de outra forma

    DEQUE auxiliar;
    inicializarDeque(&auxiliar);

    int dequeVazio = (d->cabeca->proximo == d->cabeca); // Verifica se o deque principal está vazio

    while (!dequeVazio) {
        PACIENTE pacienteAtual = getPacienteInicio(d);
        excluirPacienteInicio(d);
        inserirPacienteInicio(&auxiliar, pacienteAtual);

        dequeVazio = (d->cabeca->proximo == d->cabeca); // Atualiza a variável dequeVazio
    }

    PACIENTE pacienteMaiorIdade = auxiliar.cabeca->proximo->pac;

    while (auxiliar.cabeca->proximo != auxiliar.cabeca) {
        PACIENTE pacienteAtual = getPacienteInicio(&auxiliar);
        excluirPacienteInicio(&auxiliar);
        if (pacienteAtual.idade > pacienteMaiorIdade.idade)
            pacienteMaiorIdade = pacienteAtual;
        inserirPacienteInicio(d, pacienteAtual);
    }

    reinicializarDeque(&auxiliar);

    return pacienteMaiorIdade;
}

PACIENTE getPacienteMenorCodigo(DEQUE *d) {
    if (d->cabeca->proximo == d->cabeca)
        exit(EXIT_FAILURE); // ou trate o erro de outra forma

    DEQUE auxiliar;
    inicializarDeque(&auxiliar);

    int dequeVazio = (d->cabeca->proximo == d->cabeca); // Verifica se o deque principal está vazio

    while (!dequeVazio) {
        PACIENTE pacienteAtual = getPacienteInicio(d);
        excluirPacienteInicio(d);
        inserirPacienteInicio(&auxiliar, pacienteAtual);

        dequeVazio = (d->cabeca->proximo == d->cabeca); // Atualiza a variável dequeVazio
    }

    PACIENTE pacienteMenorCodigo = auxiliar.cabeca->proximo->pac;

    while (auxiliar.cabeca->proximo != auxiliar.cabeca) {
        PACIENTE pacienteAtual = getPacienteInicio(&auxiliar);
        excluirPacienteInicio(&auxiliar);
        if (pacienteAtual.cod_pac < pacienteMenorCodigo.cod_pac)
            pacienteMenorCodigo = pacienteAtual;
        inserirPacienteInicio(d, pacienteAtual);
    }

    reinicializarDeque(&auxiliar);

    return pacienteMenorCodigo;
}

void calcularMediaInserirInicio(DEQUE *d) {
    if (d->cabeca->proximo == d->cabeca)
        exit(EXIT_FAILURE); // ou trate o erro de outra forma

    DEQUE auxiliar;
    inicializarDeque(&auxiliar);

    int totalIdades = 0;
    int numPacientes = 0;

    while (d->cabeca->proximo != d->cabeca) {
        PACIENTE pacienteAtual = getPacienteInicio(d);
        excluirPacienteInicio(d);
        inserirPacienteInicio(&auxiliar, pacienteAtual);

        totalIdades += pacienteAtual.idade;
        numPacientes++;
    }

    float media = totalIdades / numPacientes;

    PACIENTE pacienteMedia;
    pacienteMedia.cod_pac = 0; // Código fictício para representar a média
    pacienteMedia.nome = "Media"; // Nome vazio para representar a média
    pacienteMedia.cpf = ""; // CPF vazio para representar a média
    pacienteMedia.idade = media;

    //inserir no final
    inserirPacienteInicio(d, pacienteMedia);

    while (auxiliar.cabeca->proximo != auxiliar.cabeca) {
        PACIENTE pacienteAtual = getPacienteInicio(&auxiliar);
        excluirPacienteInicio(&auxiliar);
        inserirPacienteInicio(d, pacienteAtual);
    }

    //inserir no inicio
    inserirPacienteInicio(d, pacienteMedia);
}

int excluirPacientePorCodigo(DEQUE *d, int codigo) {
    if (d->cabeca->proximo == d->cabeca)
        return 0; // Deque vazio, não há pacientes para remover

    DEQUE auxiliar;
    inicializarDeque(&auxiliar);

    int pacienteRemovido = 0; // Flag para indicar se um paciente foi removido

    while (d->cabeca->proximo != d->cabeca) {
        PACIENTE pacienteAtual = getPacienteInicio(d);
        excluirPacienteInicio(d);

        if (pacienteAtual.cod_pac != codigo) {
            inserirPacienteInicio(&auxiliar, pacienteAtual);
        } else {
            pacienteRemovido = 1; // Paciente com o código especificado foi encontrado e removido
        }
    }

    while (auxiliar.cabeca->proximo != auxiliar.cabeca) {
        PACIENTE pacienteAtual = getPacienteInicio(&auxiliar);
        excluirPacienteInicio(&auxiliar);
        inserirPacienteInicio(d, pacienteAtual);
    }

    reinicializarDeque(&auxiliar);

    return pacienteRemovido;
}

int buscarPosicaoPorCPF(DEQUE *d, const char *cpf) {
    if (d->cabeca->proximo == d->cabeca)
        return -1; // Deque vazio, nenhum paciente para buscar

    DEQUE auxiliar;
    inicializarDeque(&auxiliar);

    int posicao = 1;
    int pacienteEncontrado = 0;

    while (d->cabeca->proximo != d->cabeca) {
        PACIENTE pacienteAtual = getPacienteInicio(d);
        excluirPacienteInicio(d);
        inserirPacienteFim(&auxiliar, pacienteAtual);

        if (strcmp(pacienteAtual.cpf, cpf) == 0) {
            pacienteEncontrado = 1;
            break;
        }

        posicao++;
    }

    while (auxiliar.cabeca->proximo != auxiliar.cabeca) {
        PACIENTE pacienteAtual = getPacienteInicio(&auxiliar);
        excluirPacienteInicio(&auxiliar);
        inserirPacienteFim(d, pacienteAtual);
    }

    reinicializarDeque(&auxiliar);

    if (pacienteEncontrado)
        return posicao;
    else
        return -1; // Paciente com o CPF não encontrado
}

int PilhasEmFila( DEQUE *pilha1, DEQUE *pilha2, DEQUE *fila){
    if (pilha1->cabeca->proximo==pilha1->cabeca || pilha2->cabeca->proximo==pilha2->cabeca) return 0;
    while (pilha1->cabeca->proximo!=pilha1->cabeca && pilha2->cabeca->proximo!=pilha2->cabeca)
    {
        inserirPacienteFim(fila, getPacienteInicio(pilha1));
        excluirPacienteInicio(pilha1);
        inserirPacienteFim(fila, getPacienteInicio(pilha2));
        excluirPacienteInicio(pilha2);
    }
    return 1;
}






