#include <stdio.h>
// Selectionsort, simples de ser implementado, mas ineficiente
// Complexidade O(n^2)
// Caracteristicas: in-place


void selectionsort(int v[], int l, int r){
    for (int i = 0; i<r; i++){
        int min = i;
        for (int j = i+1; j<r; j++){
            if (v[j] < v[min]){
                min = j;
            }
        }
        int aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}

int main(){
    int vetor[20] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 11, 13, 15, 17, 19, 12, 14, 16, 18, 20};
    int l = 0;
    int r = 19;
    selectionsort(vetor, l, r);
    for (int i = 0; i<=r; i++){
        printf("%d ", vetor[i]);
    }
}