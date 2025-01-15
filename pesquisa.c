#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int v;
    char instrucao[100];
} Vetor;

void merge(Vetor v[], int l, int m, int r);

void mergesort(Vetor v[], int l, int r){
    if (l >= r) return;

    int m = (l+r)/2;

    mergesort(v, l, m);
    mergesort(v, m+1, r);

    merge(v, l, m, r);
}

void merge(Vetor v[], int l, int m, int r){
    int tam = r-l+1;
    Vetor *aux = malloc(tam*sizeof(Vetor));

    int i = l;
    int j = m+1;
    int k = 0;

    while (i <= m && j <= r){
        if (v[i].v < v[j].v){
            aux[k++] = v[i++];
        } else {
            aux[k++] = v[j++];
        }
    }

    while (i <= m) aux[k++] = v[i++];
    while (j <= r) aux[k++] = v[j++];

    for (int k = 0, i=l; i <= r; i++, k++){
        v[i] = aux[k];
    }

    free(aux);
}

int busca_binaria(Vetor v[], int l, int r, int x){
    if (l > r) return -1;

    int m = (l+r)/2;

    if (v[m].v == x) return m;
    if (v[m].v < x) return busca_binaria(v, m+1, r, x);
    return busca_binaria(v, l, m-1, x);
}


int main(){
    int size;
    scanf("%d", &size);
    Vetor vetor[size];
    getchar();
    for(int i = 0; i<size; i++){
        scanf("%d", &vetor[i].v);
        scanf("%[^\n]", vetor[i].instrucao);
    }
    mergesort(vetor, 0, size-1);
    
    int x;
    while(scanf("%d", &x) != EOF){
        int pos = busca_binaria(vetor, 0, size-1, x);
        if (pos == -1){
            printf("undefined\n");
        } else {
            printf("%s\n", vetor[pos].instrucao);
        }
    }

}