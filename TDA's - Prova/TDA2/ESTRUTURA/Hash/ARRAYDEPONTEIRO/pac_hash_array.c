#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pac_hash_array.h"

void inicializaHash (TB_HASH tab){
    int i;
    for (i = 0; i < N; i++){
        tab[i] = NULL;
    }
}

int m_Hash (int cod_pac){
    return (cod_pac%N);
}

int inserir (TB_HASH tab, PACIENTE pac){
    int h = m_Hash (pac.cod_pac);
    while (tab[h] != NULL){
        if(tab[h]->cod_pac == pac.cod_pac) return 0;
        h = (h+1)%N;
    }
    if (tab[h] == NULL){
        tab[h] = malloc(sizeof(PACIENTE));
        *(tab[h])=pac;
    }
    return 1;
}

PACIENTE *busca (TB_HASH tab, int cod_pac){
    int h = m_Hash(cod_pac);
    while (tab[h]!=NULL){
        if(tab[h]->cod_pac == cod_pac) return tab[h];
        h=(h+1)%N;
    }
    return NULL;
}

void mostrarHash (TB_HASH tab){
    printf("\n--------------------------------------------------");
    for (int i = 0; i < N; i++){
        if (tab[i]!=NULL){
            printf("\nPaciente: %d \t", i);
            printf("Codigo do paciente: %d", tab[i]->cod_pac);
            printf(" Nome: %s", tab[i]->nome);
            printf(" CPF: %s", tab[i]->cpf);
            printf(" Idade: %d", tab[i]->idade);
        }else printf("\nPaciente: %d NULL", i);
    }
}
// excluir pelo código do paciente
int excluir (TB_HASH tab, int cod_pac) {
    int h = m_Hash(cod_pac);
    while (tab[h] != NULL) {
        if (tab[h]->cod_pac == cod_pac) {
            free(tab[h]);
            tab[h] = NULL;
            return 1;
        }
        h = (h + 1) % N;
    }
    return 0;
}
// excluir pela posição no array
int excluirPosicao (TB_HASH tab, int pos){
    if (pos < 0 || pos >= N) return 0;
    if (tab[pos] == NULL) return 0;
    free(tab[pos]);
    tab[pos] = NULL;
    return 1;
}

PACIENTE *obterPacienteMaiorIdade(TB_HASH tab) {
    PACIENTE *maiorIdade = NULL;
    int i;
    for (i = 0; i < N; i++) {
        if (tab[i] != NULL) {
            if (maiorIdade == NULL || tab[i]->idade > maiorIdade->idade) {
                maiorIdade = tab[i];
            }
        }
    }
    return maiorIdade;
}

PACIENTE *obterPacienteMenorCodigo(TB_HASH tab) {
    PACIENTE *menorCodigo = NULL;
    int i;
    for (i = 0; i < N; i++) {
        if (tab[i] != NULL) {
            if (menorCodigo == NULL || tab[i]->cod_pac < menorCodigo->cod_pac) {
                menorCodigo = tab[i];
            }
        }
    }
    return menorCodigo;
}

float calcularMediaIdades(TB_HASH tab) {
    int totalIdades = 0;
    int numPacientes = 0;
    int i;
    for (i = 0; i < N; i++) {
        if (tab[i] != NULL) {
            totalIdades += tab[i]->idade;
            numPacientes++;
        }
    }
    if (numPacientes == 0) {
        return 0.0;
    } else {
        return (float)totalIdades / numPacientes;
    }
}

int removerPorCPF(TB_HASH tab, char* cpf) {
    int i;
    for (i = 0; i < N; i++) {
        if (tab[i] != NULL && strcmp(tab[i]->cpf, cpf) == 0) {
            free(tab[i]);
            tab[i] = NULL;
            return 1; // Remoção bem-sucedida
        }
    }
    return 0; // CPF não encontrado para remoção
}

int buscarPosicaoPorCodigo(TB_HASH tab, int cod_pac) {
    int h = m_Hash(cod_pac);
    int pos = -1;
    
    while (tab[h] != NULL) {
        if (tab[h]->cod_pac == cod_pac) {
            pos = h;
            break;
        }
        h = (h + 1) % N;
    }

    return pos;
}



