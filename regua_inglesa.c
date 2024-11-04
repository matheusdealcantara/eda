#include <stdio.h>

void regua_inglesa(int n) {
    if (n == 0) return;
    regua_inglesa(n-1);
    for (int i = 0; i < n; i++) i < 1 ? printf(".-") : printf("-");
    printf("\n");
    regua_inglesa(n-1);
}

int main() {
    regua_inglesa(4);
    return 0;
}