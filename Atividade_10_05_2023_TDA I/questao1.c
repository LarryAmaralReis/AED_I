#include <stdio.h>
#include <string.h>

int main() {
    char frase[50];
    char caractere = 'P';
    char *encontrado;

    fgets(frase, sizeof(frase), stdin);

    encontrado = strchr(frase, caractere);

    if (encontrado != NULL) {
        printf("SIM");
    } else {
        printf("NAO");
    }

    return 0;
}
