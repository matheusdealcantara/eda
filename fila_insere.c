#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira (fila *f, int x){
    if (f->u == f->N){
        int novo = 2*f->N;
        int *novo_dados = malloc(novo*sizeof(int));
        if (novo_dados == NULL){
            return 0;
        }
        for (int i = f->p; i < f->u; i++) novo_dados[i - f->p] = f->dados[i];

        free(f->dados);
        f->dados = novo_dados;

        f->u -= f->p;
        f->p = 0;
        f->N = novo;
    }

    f->dados[f->u++] = x;
    return 1;
}