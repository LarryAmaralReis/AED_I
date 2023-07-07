#include "deque_aluno.c"

int main(){
    DEQUE d;
    inicializaDeque(&d);

    ALUNO p;

    p = (ALUNO) {1, "Rafael Souza"};
    inserirAlunoFim(&d, p);

    p = (ALUNO) {2, "Bruno Silva"};
    inserirAlunoFim(&d, p);

    p = (ALUNO) {3, "Marcos Santos"};
    inserirAlunoFim(&d, p);

    p = (ALUNO) {4, "Clovis Pereira"};
    inserirAlunoFim(&d, p);

    p = (ALUNO) {5, "Tania Oliveira"};
    inserirAlunoFim(&d, p);

    //mostrarDeque(&d);
    exibe(&d, 0, 'd');

    exibe(&d, 2, 'i');

    reinicializar(&d);
}