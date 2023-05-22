#include "complexo.h"
#include <stdlib.h>

Complexo* criarComplexo(double real, double imag) {
    Complexo* complexo = (Complexo*)malloc(sizeof(Complexo));
    complexo->real = real;
    complexo->imag = imag;
    return complexo;
}

void destruirComplexo(Complexo* complexo) {
    free(complexo);
}

Complexo* somarComplexos(const Complexo* complexo1, const Complexo* complexo2) {
    double real = complexo1->real + complexo2->real;
    double imag = complexo1->imag + complexo2->imag;
    return criarComplexo(real, imag);
}

Complexo* subtrairComplexos(const Complexo* complexo1, const Complexo* complexo2) {
    double real = complexo1->real - complexo2->real;
    double imag = complexo1->imag - complexo2->imag;
    return criarComplexo(real, imag);
}

Complexo* multiplicarComplexos(const Complexo* complexo1, const Complexo* complexo2) {
    double real = complexo1->real * complexo2->real - complexo1->imag * complexo2->imag;
    double imag = complexo1->real * complexo2->imag + complexo1->imag * complexo2->real;
    return criarComplexo(real, imag);
}

Complexo* dividirComplexos(const Complexo* complexo1, const Complexo* complexo2) {
    double divisor = complexo2->real * complexo2->real + complexo2->imag * complexo2->imag;
    double real = (complexo1->real * complexo2->real + complexo1->imag * complexo2->imag) / divisor;
    double imag = (complexo1->imag * complexo2->real - complexo1->real * complexo2->imag) / divisor;
    return criarComplexo(real, imag);
}
