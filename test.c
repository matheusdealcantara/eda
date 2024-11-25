#include <stdio.h>

// Função para verificar se o ano é bissexto
void verificaBissexto(int *ano, int *bissexto) {
    if ((*ano % 400 == 0) || (*ano % 4 == 0 && *ano % 100 != 0)) {
        *bissexto = 1;
    } else {
        *bissexto = 0;
    }
}

// Função para calcular o dia e o mês a partir do dia do ano
void calculaDiaMes(int *diaAno, int *ano, int *mes, int *dia) {
    int diasMeses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int bissexto;

    verificaBissexto(ano, &bissexto);
    if (bissexto) {
        diasMeses[1] = 29;  // Ajusta fevereiro para 29 dias em anos bissextos
    }

    *mes = 0;
    while (*diaAno > diasMeses[*mes]) {
        *diaAno -= diasMeses[*mes];
        (*mes)++;
    }
    *dia = *diaAno;
    (*mes)++;  // Incrementa para obter o mês corretamente (1 a 12)
}

// Função para validar as entradas
int validarEntrada(int *diaAno, int *ano) {
    int bissexto, maxDias;
    verificaBissexto(ano, &bissexto);
    maxDias = bissexto ? 366 : 365;
    return (*diaAno >= 1 && *diaAno <= maxDias);
}

int main() {
    int diaAno, ano;
    int mes, dia;

    // Leitura dos dados de entrada
    scanf("%d %d", &diaAno, &ano);

    // Validação da entrada (restrição do dia e do ano)
    if (!validarEntrada(&diaAno, &ano) || ano < 0 || ano > 9999) {
        printf("Entradas invalidas!\n");
        return 0;
    }

    // Cálculo do mês e dia correspondentes
    calculaDiaMes(&diaAno, &ano, &mes, &dia);

    // Impressão do resultado no formato DD/MM/AAAA
    printf("%02d/%02d/%04d\n", dia, mes, ano);

    return 0;
}
