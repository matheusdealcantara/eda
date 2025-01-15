#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct {
    Item *itens;
    int inicio, fim;
} Fila;

Fila *criar (int maxN) {
    Fila *f = malloc(sizeof(Fila));
    f->itens = malloc(maxN * sizeof(Item));
    f->inicio = f->fim = 0;
    return f;
}

int vazia (Fila *f) {
    return f->inicio == f->fim;
}

void enfilera (Fila *f, Item x) {
    f->itens[f->fim++] = x;
}

int desenfilera (Fila *f) {
    return f->itens[f->inicio++];
}

void destruir (Fila *f) {
    free(f->itens);
    free(f);
}

void imprime ( Fila *f) {
    printf ("\n FILA p=%d e u=%d\n", f->inicio , f->fim );
    for ( int i=f->inicio ; i <f->fim ; i ++) {
        printf (" F[%d] |", i) ;
    }
    printf ("\n");

    for ( int i = f->inicio ; i < f->fim ; i ++) {
        printf (" %3d |", f->itens[i]);
    }
    printf ("\n");
}

int main () {
    Fila *f = criar(10);
    for(int i=0; i<10; i++) {
        enfilera(f, i);
    }
    imprime(f);
    printf("Desenfileirando: %d\n", desenfilera(f));
    imprime(f);
    printf("Desenfileirando: %d\n", desenfilera(f));
    imprime(f);
    destruir(f);
    return 0;
}

