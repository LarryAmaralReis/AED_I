#include "deque_ligado.c"

int main(){
    DEQUE deque;
    inicializarDeque(&deque);

    PACIENTE p;

    p = (PACIENTE){1, "Aguinaldo", "000.000.000-01", 2};
    inserirPacienteFim(&deque, p);

    p = (PACIENTE){2, "Frank", "000.000.000-02", 24};
    inserirPacienteFim(&deque, p);

    p = (PACIENTE){3, "Gabriel", "000.000.000-03", 25};
    inserirPacienteInicio(&deque, p);

    p = (PACIENTE){4, "Huanderson", "000.000.000-04", 26};
    inserirPacienteFim(&deque, p);
    
    p = (PACIENTE){5, "Jefferson", "000.000.000-05", 1};
    inserirPacienteFim(&deque, p);

    mostrarDeque(&deque);

    p = getPacienteMaiorIdade(&deque);

    printf("\n O paciente de maior idade(%d) eh: %s", p.idade, p.nome);

    p = getPacienteMenorCodigo(&deque);

    printf("\n O paciente de menor codigo(%d) eh: %s", p.cod_pac, p.nome);

    calcularMediaInserirInicio(&deque);

    mostrarDeque(&deque);

    excluirPacientePorCodigo(&deque, 1);

    mostrarDeque(&deque);

    int posicao = buscarPosicaoPorCPF(&deque, "000.000.000-05");

    printf("\nO paciente buscado esta na posicao: %d", posicao);
}