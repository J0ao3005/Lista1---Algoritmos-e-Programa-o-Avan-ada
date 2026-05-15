// main.c — teste temporário
#include <stdio.h>
#include "geometria.h"

int main() {
    Point a = {0, 0};
    Point b = {3, 4};
    printf("Distancia: %.2f\n", distancia(a, b)); // esperado: 5.00

    Point c = {0, 0};
    printf("No dominio: %d\n", dentro_dominio(c, 10.0)); // esperado: 1

    // Teste intersecta
    Segment s1 = {{0,0}, {1,1}};
    Segment s2 = {{0,1}, {1,0}};
    printf("Intersecta: %d\n", intersecta(s1, s2)); // esperado: 1

    Segment s3 = {{0,0}, {1,0}};
    Segment s4 = {{0,1}, {1,1}};
    printf("Nao intersecta: %d\n", intersecta(s3, s4)); // esperado: 0

    return 0;
}