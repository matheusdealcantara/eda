#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;


void imprime (celula *le) {
    // celula *p;
    for (; le != NULL; le = le->prox)
        printf("%d -> ", le->dado);
    printf("NULL");
}

void imprime_rec (celula *le) {
    // celula *p = le;
    if (le == NULL) {
        printf("NULL");
        return;
    }
    printf("%d -> ", le->dado);
    imprime_rec(le->prox);
}


// int main() {
//     celula c1, c2, c3, c4;
//     c1.dado = 1; c1.prox = &c2;
//     c2.dado = 2; c2.prox = &c3;
//     c3.dado = 3; c3.prox = NULL;

//     imprime(&c1);
//     printf("\n");
//     imprime_rec(&c1);
//     printf("\n");
//     return 0;
// }