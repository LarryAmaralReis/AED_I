#include <stdio.h>
#include <stdlib.h>
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

PACIENTE *busuca (TB_HASH tab, int cod_pac){
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
	for ( i=0; i<N; i++){
		if (tab[i] != NULL){
			e=tab[i];
			printf("\n Paciente: %d", i);
			while(e!=NULL){
				printf("Nome: %s -->", tab[i]->pac.nome);
				e=e->proximo;
			}
			printf(" NULL");
		}
		else printf("\n Paciente: %d NULL",i);
	}
}
