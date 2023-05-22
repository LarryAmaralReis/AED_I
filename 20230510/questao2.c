#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    char data_nascimento[11];
    char cpf[15];
} Pessoa;

void preencheValor(Pessoa *p);
void imprimeValor(const Pessoa *p);

void preencheValor(Pessoa *p) {
    strcpy(p->nome, "Larry Amaral Reis");
    strcpy(p->data_nascimento, "00/00/0000");
    strcpy(p->cpf, "000.000.000-00");
}

void imprimeValor(const Pessoa *p) {
    printf("Nome: %s\n", p->nome);
    printf("Data de nascimento: %s\n", p->data_nascimento);
    printf("CPF: %s\n", p->cpf);
}

int main() {
    Pessoa Larry;
    preencheValor(&Larry);
    imprimeValor(&Larry);

    return 0;
}