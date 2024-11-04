#include <stdio.h>

int conta(char frase[], int j) {
    char c = frase[j];
    if (c == frase[j+2]) return conta(frase, j+1) + 1;
    else if (frase[j+2] == '\0') return 0;
    else return conta(frase, j+1);
}

int main() {
    char frase[201];
    fgets(frase, 201, stdin);
    
    int i = conta(frase, 0);
    printf("%d", i);
    return 0;
}