#include <stdio.h>

float potenciacao(int base, int expoente) {
    base = (float) base;
    if (expoente == 0) return 1;
    if (expoente > 0) {
        return  base * potenciacao(base, expoente - 1);
    } else {
        return 1 / (base * potenciacao(base, -expoente - 1));
    }
}

int main() {
    int base, expoente;
    scanf("%d %d", &base, &expoente);
    if (base == 0 && expoente <= 0) {printf("indefinido\n"); return 0;}
    printf("%f\n", potenciacao(base, expoente));
    return 0;
}