#include <stdio.h>

void regua_inglesa(int n) {
    if (n == 0) return;
    regua_inglesa(n-1);
    for (int i = 0; i < n; i++) i == 0 ? printf(".-") : printf("-");
    printf("\n");
    regua_inglesa(n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    regua_inglesa(n);
    return 0;
}