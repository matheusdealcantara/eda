#include <stdio.h>

int partition(int v[], int l, int r);

void quicksort(int v[], int l, int r){
    if (r <= l) return;

    int p = partition(v, l, r);

    quicksort(v, l, p-1);
    quicksort(v, p+1, r);
}

int partition(int v[], int l, int r){
    int pivot = v[r];
    int i = l-1;
    int j = r;

    while (i < j){
        while (v[++i] < pivot);
        while (v[--j] > pivot && j > l);
        if (i < j){
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    v[r] = v[i];
    v[i] = pivot;
    return i;
}

int main() {
    int vetor[20] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 11, 13, 15, 17, 19, 12, 14, 16, 18, 20};
    int l = 0;
    int r = 19;
    quicksort(vetor, l, r);
    for (int i = 0; i<=r; i++){
        printf("%d ", vetor[i]);
    }
}