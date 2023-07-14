#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_ligada.h"

void inicializarFila (FILA *f){
    f->inicio = NULL;
    f->fim = NULL;
}

void reinicializarFila (FILA *f){
    ELEMENTO *apagar;
    ELEMENTO *elemento = f->inicio;
    while (elemento != NULL){
        apagar = elemento;
        elemento = elemento->proximo;
        free(apagar);
    }
    f->inicio = NULL;
}

int inserirPaciente (FILA *f, PACIENTE novo_paciente){
    ELEMENTO *i;
    i = malloc(sizeof(ELEMENTO));
    if (i==NULL) return 0;
    i->pac = novo_paciente;
    i->proximo = NULL;
    if (f->inicio == NULL) f->inicio = i;
    else f->fim->proximo = i;
    f->fim = i;
    return 1;
}

int excluirPaciente (FILA *f){
    if (f->inicio == NULL) return 0;
    ELEMENTO *i = f->inicio;
    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL) f->fim = NULL;
    free (i);
    return 1;
}

ELEMENTO firstELEMENTO (FILA *f){
    return *(f->inicio);
}

PACIENTE firstPACIENTE (FILA *f){
    return f->inicio->pac;
}

int imprimirFila (FILA f){
    if (f.inicio == NULL) return 0;
    ELEMENTO *i = f.inicio;
    printf("\n-------------FILA-------------");
    while (i != NULL){
        printf("\nCodigo: %d", i->pac.cod_pac);
        printf("\nNome: %s", i->pac.nome);
        printf("\nCPF: %s", i->pac.cpf);
        printf("\nIdade: %d", i->pac.idade);
        printf("\n------------------------------");
        i = i->proximo;
    }
    return 1;
}

PACIENTE pacienteMaiorIdade(FILA *f) {
    FILA filaAuxiliar;
    inicializarFila(&filaAuxiliar);

    PACIENTE pacienteMaior;
    pacienteMaior.cod_pac = -1;  // Default code for an invalid patient
    pacienteMaior.nome = NULL;   // Default name for an invalid patient
    pacienteMaior.cpf = NULL;    // Default CPF for an invalid patient
    pacienteMaior.idade = -1;    // Default age for an invalid patient

    int maiorIdade = 0;

    // Verificar se a fila está vazia
    if (f->inicio == NULL) {
        printf("A fila está vazia.\n");
        return pacienteMaior;
    }

    // Percorrer a fila original para encontrar o paciente de maior idade
    while (f->inicio != NULL) {
        PACIENTE paciente = firstPACIENTE(f);
        excluirPaciente(f);

        if (paciente.idade > maiorIdade) {
            pacienteMaior = paciente;
            maiorIdade = paciente.idade;
        }

        inserirPaciente(&filaAuxiliar, paciente);
    }

    // Restaurar a fila original
    while (filaAuxiliar.inicio != NULL) {
        PACIENTE paciente = firstPACIENTE(&filaAuxiliar);
        excluirPaciente(&filaAuxiliar);
        inserirPaciente(f, paciente);
    }

    return pacienteMaior;
}

PACIENTE pacienteMenorCodigo(FILA *f) {
    FILA filaAuxiliar;
    inicializarFila(&filaAuxiliar);

    PACIENTE pacienteMenor;
    int menorCodigo = INT_MAX;  // Inicializar com um valor máximo

    // Verificar se a fila está vazia
    if (f->inicio == NULL) {
        printf("A fila está vazia.\n");
        // Retorna um paciente com código -1 para indicar que não há paciente válido
        PACIENTE pacienteInvalido = {-1, NULL, NULL, -1};
        return pacienteInvalido;
    }

    // Percorrer a fila original para encontrar o paciente de menor código
    while (f->inicio != NULL) {
        PACIENTE paciente = firstPACIENTE(f);
        excluirPaciente(f);

        if (paciente.cod_pac < menorCodigo) {
            pacienteMenor = paciente;
            menorCodigo = paciente.cod_pac;
        }

        inserirPaciente(&filaAuxiliar, paciente);
    }

    // Restaurar a fila original
    while (filaAuxiliar.inicio != NULL) {
        PACIENTE paciente = firstPACIENTE(&filaAuxiliar);
        excluirPaciente(&filaAuxiliar);
        inserirPaciente(f, paciente);
    }

    return pacienteMenor;
}

void inserirMediaIdades(FILA *f) {
    FILA filaAuxiliar;
    inicializarFila(&filaAuxiliar);

    int somaIdades = 0;
    int numPacientes = 0;

    // Verificar se a fila está vazia
    if (f->inicio == NULL) {
        printf("A fila está vazia.\n");
        return;
    }

    // Percorrer a fila original para somar as idades e contar o número de pacientes
    while (f->inicio != NULL) {
        PACIENTE paciente = firstPACIENTE(f);
        excluirPaciente(f);
        somaIdades += paciente.idade;
        numPacientes++;
        inserirPaciente(&filaAuxiliar, paciente);
    }

    // Calcular a média das idades
    float mediaIdades = (float) somaIdades / numPacientes;

    // Criar um novo paciente com a idade média
    PACIENTE pacienteMedia;
    pacienteMedia.cod_pac = -1;  // Código inválido para o paciente da média
    pacienteMedia.nome = NULL;   // Nome inválido para o paciente da média
    pacienteMedia.cpf = NULL;    // CPF inválido para o paciente da média
    pacienteMedia.idade = (int) mediaIdades;

    // Inserir o paciente da média no final da fila original
    //inserirPaciente(f, pacienteMedia);

    // Restaurar a fila original a partir da fila auxiliar
    while (filaAuxiliar.inicio != NULL) {
        PACIENTE paciente = firstPACIENTE(&filaAuxiliar);
        excluirPaciente(&filaAuxiliar);
        inserirPaciente(f, paciente);
    }

    inserirPaciente(f, pacienteMedia);
}

void removerPorCodigo(FILA *f, int codigo) {
    FILA filaAuxiliar;
    inicializarFila(&filaAuxiliar);

    // Verificar se a fila está vazia
    if (f->inicio == NULL) {
        printf("A fila está vazia.\n");
        return;
    }

    int pacienteEncontrado = 0;  // Flag para indicar se o paciente foi encontrado

    // Percorrer a fila original para encontrar o paciente com o código
    while (f->inicio != NULL) {
        PACIENTE paciente = firstPACIENTE(f);
        excluirPaciente(f);

        if (paciente.cod_pac == codigo) {
            pacienteEncontrado = 1;  // Marcar que o paciente foi encontrado
        } else {
            inserirPaciente(&filaAuxiliar, paciente);
        }
    }

    // Restaurar a fila original a partir da fila auxiliar, caso o paciente tenha sido encontrado
    if (pacienteEncontrado) {
        while (filaAuxiliar.inicio != NULL) {
            PACIENTE paciente = firstPACIENTE(&filaAuxiliar);
            excluirPaciente(&filaAuxiliar);
            inserirPaciente(f, paciente);
        }
        printf("\nO paciente com o código %d foi removido da fila.", codigo);
    } else {
        printf("\nO paciente com o código %d não foi encontrado na fila.", codigo);
    }
}

int posicaoPorCodigo(FILA *f, int codigo) {
    FILA filaAuxiliar;
    inicializarFila(&filaAuxiliar);

    // Verificar se a fila está vazia
    if (f->inicio == NULL) {
        printf("A fila está vazia.\n");
        return -1;  // Retorna -1 para indicar que o paciente não foi encontrado
    }

    int posicao = 0;
    int pacienteEncontrado = 0;  // Flag para indicar se o paciente foi encontrado

    // Percorrer a fila original para encontrar o paciente com o código
    while (f->inicio != NULL) {
        PACIENTE paciente = firstPACIENTE(f);
        excluirPaciente(f);
        if (pacienteEncontrado != 1) posicao++;;
        if (paciente.cod_pac == codigo) pacienteEncontrado = 1;  // Marcar que o paciente foi encontrado
        inserirPaciente(&filaAuxiliar, paciente);
    }

    // Restaurar a fila original a partir da fila auxiliar
    while (filaAuxiliar.inicio != NULL) {
        PACIENTE paciente = firstPACIENTE(&filaAuxiliar);
        excluirPaciente(&filaAuxiliar);
        inserirPaciente(f, paciente); 
    }

    if (pacienteEncontrado) {
        printf("\nO paciente com o código %d está na posição %d da fila.", codigo, posicao);
        return posicao;
    } else {
        printf("\nO paciente com o código %d não foi encontrado na fila.", codigo);
        return -1;  // Retorna -1 para indicar que o paciente não foi encontrado
    }
}


int posicaoPorCPF(FILA *f, const char *cpf) {
    FILA filaAuxiliar;
    inicializarFila(&filaAuxiliar);

    // Verificar se a fila está vazia
    if (f->inicio == NULL) {
        printf("A fila está vazia.\n");
        return -1;  // Retorna -1 para indicar que o paciente não foi encontrado
    }

    int posicao = 0;
    int pacienteEncontrado = 0;  // Flag para indicar se o paciente foi encontrado

    // Percorrer a fila original para encontrar o paciente com o CPF
    while (f->inicio != NULL) {
        PACIENTE paciente = firstPACIENTE(f);
        excluirPaciente(f);
        
        if (pacienteEncontrado != 1) posicao++;;
        if (strcmp(paciente.cpf, cpf) == 0) pacienteEncontrado = 1;  // Marcar que o paciente foi encontrado

        inserirPaciente(&filaAuxiliar, paciente);
    }

    // Restaurar a fila original a partir da fila auxiliar
    while (filaAuxiliar.inicio != NULL) {
        PACIENTE paciente = firstPACIENTE(&filaAuxiliar);
        excluirPaciente(&filaAuxiliar);
        inserirPaciente(f, paciente);
    }

    if (pacienteEncontrado) {
        printf("\nO paciente com o CPF %s está na posição %d da fila.", cpf, posicao);
        return posicao;
    } else {
        printf("\nO paciente com o CPF %s não foi encontrado na fila.", cpf);
        return -1;  // Retorna -1 para indicar que o paciente não foi encontrado
    }
}
