#include <stdio.h>
// Insertion sort, simples de ser implementado, mas ineficiente
// Complexidade O(n^2)
// Caracteristicas: in-place, estável e adaptativo

void insertionsort(int v[], int l, int r){
    for (int i=l+1; i<=r; i++){
        int aux = v[i];
        for (int j=i-1; j>=l; j--){
            if (v[j] > aux){
                v[j+1] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main(){
    int vetor[20] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 11, 13, 15, 17, 19, 12, 14, 16, 18, 20};
    int l = 0;
    int r = 19;
    insertionsort(vetor, l, r);
    for (int i = 0; i<=r; i++){
        printf("%d ", vetor[i]);
    }
}