#include <stdio.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[100];
    Data data_nascimento;
    char cpf[15];
} Pessoa;

void preencheData(Data *d, int dia, int mes, int ano);
void preenchePessoa(Pessoa *p);
void imprimePessoa(const Pessoa *p);

void preencheData(Data *d, int dia, int mes, int ano) {
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
}

void preenchePessoa(Pessoa *p) {
    strcpy(p->nome, "Larry Amaral Reis");
    preencheData(&p->data_nascimento, 1, 1, 2000);
    strcpy(p->cpf, "000.000.000-00");
}

void imprimePessoa(const Pessoa *p) {
    printf("Nome: %s\n", p->nome);
    printf("Data de nascimento: %02d/%02d/%04d\n", p->data_nascimento.dia, p->data_nascimento.mes, p->data_nascimento.ano);
    printf("CPF: %s\n", p->cpf);
}

int main() {
    Pessoa Larry;
    preenchePessoa(&Larry);
    imprimePessoa(&Larry);

    return 0;
}
