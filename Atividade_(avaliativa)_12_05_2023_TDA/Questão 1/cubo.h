#ifndef CUBO_H
#define CUBO_H

typedef struct {
    double lado;
} Cubo;

void inicializaCubo(Cubo *c, double lado);
double tamanhoLado(const Cubo *c);
double area(const Cubo *c);
double volume(const Cubo *c);

#endif /* CUBO_H */
