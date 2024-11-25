#include <stdio.h>

int verificaBissexto(int *ano) {
    if (*ano % 400 == 0 || (*ano % 4 == 0 && *ano % 100 != 0)) return 1;
    else return 0;
}

void calculaDiaMes(int *d, int *a, int *m) {
    int diasMeses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (verificaBissexto(a)) diasMeses[1] = 29;

    for (*m = 0; *m < 12; ++*m) {
        if (*d - diasMeses[*m] <= 0) return;
        *d -= diasMeses[*m];
    }   
}

int validarEntrada(int *diaAno, int *ano) {
    int maxDias;
    int bissexto = verificaBissexto(ano);
    maxDias = bissexto ? 366 : 365;
    return (*diaAno >= 1 && *diaAno <= maxDias);
}

int main() {
    int d, m, a;
    scanf("%d %d", &d, &a);

    if (!validarEntrada(&d, &a)) {
        printf("Entradas invalidas!\n");
        return 0;
    }

    calculaDiaMes(&d, &a, &m);
    printf("%02d/%02d/%04d\n", d, m+1, a);
    return 0;
}