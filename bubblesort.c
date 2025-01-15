#include <stdio.h>
//  Bubblesort, simples de ser implementado, mas ineficiente
//  Complexidade O(n^2)
//  Caracteristicas: estável, in-place e adaptativo

void bubblesort(int v[], int l, int r){
    while (l<r){
        for(int i = 0; i<r; i++){
            for(int j = i; j<i+1; j++){
                if (v[j] > v[j+1]){
                    int aux = v[j];
                    v[j] = v[j+1];
                    v[j+1] = aux;
                }
            }
        }
        r--;
    }
}


int main(){
    int vetor[20] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 11, 13, 15, 17, 19, 12, 14, 16, 18, 20};
    int n = 20;
    bubblesort(vetor, 0, n);
    for (int i = 0; i<=n; i++){
        printf("%d ", vetor[i]);
    }
}