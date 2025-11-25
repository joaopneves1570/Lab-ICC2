#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int v[], int inicio, int fim, int x){
    int meio = (inicio + fim) / 2;

    if (inicio > fim)
        return 0;

    if (v[meio] == x)
        return 1;
    if (v[meio] > x)
        return buscaBinaria(v, inicio, meio - 1, x);
    if (v[meio] < x)
        return buscaBinaria(v, meio + 1, fim, x);
    
}

void twoSum(int v[], int n, int x){
    for (int i = 0; i < n; i++){
        int complemento = x - v[i];

        if (complemento == v[i]) continue;

        if(buscaBinaria(v, 0, n-1, complemento) == 1){
            printf("S\n");
            return;
        }
    }

    printf("N\n");
}

static inline void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(int v[], int inf, int sup) {
    if (inf >= sup) return;

    int i = inf, j = sup;
    int pivo = v[(inf + sup) / 2];

    while (i <= j) {
        while (v[i] < pivo) i++;
        while (v[j] > pivo) j--;
        if (i <= j) {
            swap(&v[i], &v[j]);
            i++;
            j--;
        }
    }

    if (inf < j) quickSort(v, inf, j);
    if (i < sup) quickSort(v, i, sup);
}

int main(){
    int n;
    scanf("%d", &n);

    int* A = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    quickSort(A, 0, n-1);

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++){
        int valor;
        scanf("%d", &valor);

        twoSum(A, n, valor);
    }
    

    free(A);
    return 0;
}