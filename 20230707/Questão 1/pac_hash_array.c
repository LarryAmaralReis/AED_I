#include <stdio.h>
#include <stdlib.h>
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
    for (int i = 0; i < N; i++){
        if (tab[i]!=NULL){
            printf("\nPaciente: %d \n", i);
            printf("Codigo do paciente: %d", tab[i]->cod_pac);
            printf(" Nome: %s", tab[i]->nome);
            printf(" CPF: %s", tab[i]->cpf);
            printf(" Idade: %d", tab[i]->idade);
        }else printf("\nPaciente: %d NULL\n", i);
    }
}