#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pac_hash_ligado.h"

void inicializahash (TB_HASH tab){
	int i;
	for (i=0;i<N;i++){
		tab[i]=NULL;
	}
}

int m_hash(int cod_pac){
	return (cod_pac%N);
}

int inserir (TB_HASH tab, PACIENTE pac){
	int h = m_hash(pac.cod_pac);
	ELEMENTO *anterior=NULL;
	ELEMENTO *e=tab[h];
	while(e!=NULL){
		if (e->pac.cod_pac == pac.cod_pac) return 0;
		anterior = e;
		e = e->proximo;
		}
	if(e==NULL){
		e = malloc(sizeof(ELEMENTO));
		e->pac=pac;
		e->proximo = NULL;
		if(anterior == NULL) tab[h]=e;
		else anterior->proximo=e;
	}
	return 1;
}

PACIENTE *busca (TB_HASH tab, int cod_pac){
	int h = m_hash(cod_pac);
	ELEMENTO *e=tab[h];
	while(e!=NULL){
		if(e->pac.cod_pac==cod_pac) return &e->pac;
		e=e->proximo;
	}
	return NULL;
}

void mostrarHash(TB_HASH tab){
	ELEMENTO *e;
	int i;
	printf("\n--------------------------------------------------");
	for (i=0; i<N; i++){
		if (tab[i] != NULL){
			e=tab[i];
			printf("\n Paciente: %d ", i);
			while(e!=NULL){
				printf("Nome: %s -->", e->pac.nome); // tab[i]->pac.nome esta errado
				e=e->proximo;
			}
			printf(" NULL");
		}
		else printf("\n Paciente: %d NULL",i);
	}
}

int excluir (TB_HASH tab, int cod_pac) {
    int h = m_hash(cod_pac);
    ELEMENTO *anterior = NULL;
    ELEMENTO *e = tab[h];
    while (e != NULL) {
        if (e->pac.cod_pac == cod_pac) {
            if (anterior == NULL) tab[h] = e->proximo;
            else anterior->proximo = e->proximo;
            free(e);
            return 1;
        }
        anterior = e;
        e = e->proximo;
    }
    return 0;
}

int excluirPosicao (TB_HASH tab, int pos) {
	ELEMENTO *anterior = NULL;
    ELEMENTO *e = tab[pos];
    if (pos < 0 || pos >= N) return 0;
    if (e == NULL) return 0;
    if (anterior == NULL) tab[pos] = e->proximo;
	else anterior->proximo = e->proximo;
    free(e);
    return 1;
}

PACIENTE* obterPacienteMaiorIdade(TB_HASH tab) {
    int i;
    PACIENTE* pacienteMaisVelho = NULL;
    for (i = 0; i < N; i++) {
        ELEMENTO* elemento = tab[i];
        while (elemento != NULL) {
            if (pacienteMaisVelho == NULL || elemento->pac.idade > pacienteMaisVelho->idade) {
                pacienteMaisVelho = &elemento->pac;
            }
            elemento = elemento->proximo;
        }
    }
    return pacienteMaisVelho;
}

PACIENTE* obterPacienteMenorCodigo(TB_HASH tab) {
    int i;
    PACIENTE* pacienteMenorCodigo = NULL;
    for (i = 0; i < N; i++) {
        ELEMENTO* elemento = tab[i];
        while (elemento != NULL) {
            if (pacienteMenorCodigo == NULL || elemento->pac.cod_pac < pacienteMenorCodigo->cod_pac) {
                pacienteMenorCodigo = &elemento->pac;
            }
            elemento = elemento->proximo;
        }
    }
    return pacienteMenorCodigo;
}

float calcularMediaIdades(TB_HASH tab) {
    int i, totalPacientes = 0;
    int somaIdades = 0;
    for (i = 0; i < N; i++) {
        ELEMENTO* elemento = tab[i];
        while (elemento != NULL) {
            totalPacientes++;
            somaIdades += elemento->pac.idade;
            elemento = elemento->proximo;
        }
    }
    if (totalPacientes > 0) {
        return (float) somaIdades / totalPacientes;
    }
    return 0;
}

int removerPorCpf(TB_HASH tab, char* cpf) {
    int i;
    for (i = 0; i < N; i++) {
        ELEMENTO* elemento = tab[i];
        ELEMENTO* elementoAnterior = NULL;
        while (elemento != NULL) {
            if (strcmp(elemento->pac.cpf, cpf) == 0) {
                if (elementoAnterior == NULL) {
                    tab[i] = elemento->proximo;
                } else {
                    elementoAnterior->proximo = elemento->proximo;
                }
                free(elemento->pac.nome);
                free(elemento->pac.cpf);
                free(elemento);
                return 1; // Indicate success
            }
            elementoAnterior = elemento;
            elemento = elemento->proximo;
        }
    }
    return 0; // Indicate failure (CPF not found)
}

int buscarPosicaoPorCodigo(TB_HASH tab, int cod_pac) {
    int posicao = m_hash(cod_pac);
    ELEMENTO* elemento = tab[posicao];
    int contador = 0;
    while (elemento != NULL) {
        if (elemento->pac.cod_pac == cod_pac) {
			printf("\nPosicao na tabela: %d e posicao na fila desta tabela: %d", posicao, contador);
            return contador;
        }
        contador++;
        elemento = elemento->proximo;
    }
    return -1; // Indicate failure (patient code not found)
}

int buscarPosicaoPorCPF(TB_HASH tab, char* cpf) {
    int i;
    for (i = 0; i < N; i++) {
        ELEMENTO* elemento = tab[i];
        int contador = 0;
        while (elemento != NULL) {
            if (strcmp(elemento->pac.cpf, cpf) == 0) {
				printf("\nPosicao na tabela: %d e posicao na fila desta tabela: %d", i, contador);
                return contador;
            }
            contador++;
            elemento = elemento->proximo;
        }
    }
    return -1; // Indicate failure (CPF not found)
}


