#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {
    celula *nova = malloc(sizeof(celula));
    nova->dado = x;
    nova->prox = le;
    le = nova;
}

void insere_antes(celula *le, int x, int y){
    celula *nova = malloc(sizeof(celula));
    for (celula *p = le; p != NULL; p = p->prox){
        if (p->prox->dado == y){
            nova->dado = x;
            nova->prox = le->prox;
            le->prox = nova;
            return;
        }
    }
}