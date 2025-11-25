#include <stdio.h>
#include <stdlib.h>

int buscaSequencial(int v[], int n, int x){
    int* inicio = v;
    for (inicio; inicio < v + n; inicio++){
        if (*inicio == x) return 1;
    }

    return 0;
}

void twoSum(int v[], int n, int x){
    for (int i = 0; i < n; i++){
        int complemento = x - v[i];

        if (complemento == v[i]) continue;

        if(buscaSequencial(v, n, complemento) == 1){
            printf("S\n");
            return;
        }
    }

    printf("N\n");
}


int main(){
    int n;
    scanf("%d", &n);

    int* A = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

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