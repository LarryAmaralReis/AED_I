#include "fila_ligada.c"

int main(){
    FILA fila;
    inicializarFila(&fila);

    PACIENTE p;
    p = (PACIENTE){1, "Nome001", "000.000.000-01", 21};
    inserirPaciente(&fila, p);

    p = (PACIENTE){2, "Nome002", "000.000.000-02", 22};
    inserirPaciente(&fila, p);

    p = (PACIENTE){3, "Nome003", "000.000.000-03", 23};
    inserirPaciente(&fila, p);

    imprimirFila(fila);

    p = firstPACIENTE(&fila);
    printf("\nPrimeiro Paciente: %d", p.cod_pac);

    ELEMENTO e;
    e = firstELEMENTO(&fila);
    printf("\nPrimeiro Elemento: %s", e.pac.nome);

    PACIENTE pacienteMaior = pacienteMaiorIdade(&fila);

    printf("\nNome do paciente com maior idade(%d): %s", pacienteMaior.idade, pacienteMaior.nome);

    PACIENTE pacienteMenor = pacienteMenorCodigo(&fila);

    printf("\nPaciente de menor codigo: %d", pacienteMenor.cod_pac);

    inserirMediaIdades(&fila);

    imprimirFila(fila);

    removerPorCodigo(&fila, -1);

    imprimirFila(fila);

    int pos = posicaoPorCodigo(&fila, 1);

    printf("\nPosicao do paciente desejado: %d", pos);

    imprimirFila(fila);

    pos =  posicaoPorCPF(&fila, "000.000.000-03");

    printf("\nPosicao do paciente desejado: %d", pos);

    imprimirFila(fila);

}