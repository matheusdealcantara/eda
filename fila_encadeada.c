#include <stdlib.h>
#include <stdio.h>

typedef int Item;
typedef struct {
    Item item;
    struct no *prox;
} No;

typedef struct {
    No *inicio, *fim;
} Fila;

Fila *criar() {
    Fila *f = malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

int vazia(Fila *f) {
    return f->inicio == NULL;
}

void enfilera(Fila *f, Item x) {
    No *novo = malloc(sizeof(No));
    novo->item = x;
    novo->prox = NULL;
    if (f->inicio == NULL) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}