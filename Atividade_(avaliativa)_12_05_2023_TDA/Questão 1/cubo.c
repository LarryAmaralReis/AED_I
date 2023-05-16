#include "cubo.h"

void inicializaCubo(Cubo *c, double lado) {
    c->lado = lado;
}

double tamanhoLado(const Cubo *c) {
    return c->lado;
}

double area(const Cubo *c) {
    return 6 * c->lado * c->lado;
}

double volume(const Cubo *c) {
    return c->lado * c->lado * c->lado;
}
