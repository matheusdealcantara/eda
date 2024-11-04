#include <stdio.h>

typedef struct Ponto {
    int value;
} Ponto;

int main() {
    Ponto s;
    s.value = 2;
    Ponto *ptr = &s;
    
    ptr->value = 5;

    printf(sizeof(ptr));

    return 0;
};