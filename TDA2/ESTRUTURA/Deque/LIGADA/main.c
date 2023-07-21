#include "deque_ligado.c"

int main(){
    DEQUE pilha1, pilha2, fila;
    inicializarDeque(&pilha1);
    inicializarDeque(&pilha2);
    inicializarDeque(&fila);

    PACIENTE p;

    p = (PACIENTE){1, "Aguinaldo", "000.000.000-01", 2};
    inserirPacienteInicio(&pilha1, p);

    p = (PACIENTE){2, "Frank", "000.000.000-02", 24};
    inserirPacienteInicio(&pilha1, p);

    p = (PACIENTE){3, "Gabriel", "000.000.000-03", 25};
    inserirPacienteInicio(&pilha1, p);

    p = (PACIENTE){4, "Huanderson", "000.000.000-04", 26};
    inserirPacienteInicio(&pilha2, p);
    
    p = (PACIENTE){5, "Jefferson", "000.000.000-05", 30};
    inserirPacienteInicio(&pilha2, p);

    p = (PACIENTE){6, "Sergio", "000.000.000-06", 11};
    inserirPacienteInicio(&pilha2, p);

    PilhasEmFila(&pilha1, &pilha2, &fila);
    // [ 3 2 1 ] [ 6 5 4 ] [ 3 6 2 5 1 4 ]
    mostrarDeque(&fila);
}