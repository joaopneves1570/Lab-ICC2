#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int seed = 12345;

void gerar_aleatoria(int n, int* sequencia) {
    for (int i = 0; i < n; i++)
        sequencia[i] = get_random(&seed, n);
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void FisherYatesShuffle(int sequencia[], int n){
    int embaralhamentos;
    for (int i = n - 1; i >= 1; i--){
        int j = get_random(&seed, i) - 1;
        swap(&sequencia[i], &sequencia[j]);
    }
}

bool isSorted(int sequencia[], int n){
    for (int i = 0; i < n - 1; i++){
        if (sequencia[i] > sequencia[i + 1])
            return false;
    }

    return true;
}

void showArray(int sequencia[], int n){
    for (int i = 0; i < n - 1; i++)
        printf("%d ", sequencia[i]);

    printf("%d", sequencia[n - 1]);
}

int semSort(int sequencia[], int n){
    int tentativas = 0;
    while (!isSorted(sequencia, n)){
        FisherYatesShuffle(sequencia, n);
        tentativas++;
    }
    
    return tentativas;
}


int main(){
    int n;
    scanf("%d", &n);

    int* sequencia = (int*)malloc(sizeof(int) * n);
    gerar_aleatoria(n, sequencia);

    int tentativas = semSort(sequencia, n);

    printf("%d\n", tentativas);
    showArray(sequencia, n);

    free(sequencia);

    return 0;
}