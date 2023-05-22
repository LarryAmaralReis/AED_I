#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct {
    double real;
    double imag;
} Complexo;

Complexo* criarComplexo(double real, double imag);
void destruirComplexo(Complexo* complexo);
Complexo* somarComplexos(const Complexo* complexo1, const Complexo* complexo2);
Complexo* subtrairComplexos(const Complexo* complexo1, const Complexo* complexo2);
Complexo* multiplicarComplexos(const Complexo* complexo1, const Complexo* complexo2);
Complexo* dividirComplexos(const Complexo* complexo1, const Complexo* complexo2);

#endif /* COMPLEXO_H */
