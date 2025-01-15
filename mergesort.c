#include <stdio.h>
#include <stdlib.h>
// Merge sort, eficiente e estável
// Complexidade O(n log n)
// Caracteristicas: estável, adaptativo e não in-place

void merge(int v[], int l, int m, int r){
    int tam = r-l+1;
    int *aux = malloc(tam*sizeof(int));

    int i = l;
    int j = m+1;
    int k = 0;

    while (i <= m && j <= r){
        if (v[i] < v[j]){
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

void mergesort(int v[], int l, int r){
    if (l >= r) return;

    int m = (l+r)/2;

    mergesort(v, l, m);
    mergesort(v, m+1, r);

    merge(v, l, m, r);
}

int main(){
    int vetor[20] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 11, 13, 15, 17, 19, 12, 14, 16, 18, 20};
    int l = 0;
    int r = 19;
    mergesort(vetor, l, r);
    for (int i = 0; i<=r; i++){
        printf("%d ", vetor[i]);
    }
}	