#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void gerar_reverso(int n, int* sequencia) {
    for (int i = 0; i < n; i++)
        sequencia[i] = n - i;
}

void gerar_aleatoria(int n, int* sequencia) {
    int seed = 12345;
    for (int i = 0; i < n; i++)
        sequencia[i] = get_random(&seed, n);
}

void gerar_ordenada(int n, int* sequencia) {
    for (int i = 0; i < n; i++)
        sequencia[i] = i + 1;
}

static inline void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* -------------------- SHELL SORT -------------------- */
void shellSort(int s[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = s[i];
            int j;
            for (j = i; j >= gap && s[j - gap] > temp; j -= gap)
                s[j] = s[j - gap];
            s[j] = temp;
        }
    }
}

/* -------------------- QUICK SORT -------------------- */
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

/* -------------------- HEAP SORT -------------------- */
void rearranjar_heap(int v[], int i, int tamanho) {
    register int temp = v[i];
    register int filho;

    while ((filho = 2 * i + 1) < tamanho) {
        if (filho + 1 < tamanho && v[filho + 1] > v[filho])
            filho++;

        if (v[filho] > temp) {
            v[i] = v[filho];
            i = filho;
        } else {
            break;
        }
    }

    v[i] = temp;
}

void heapsort(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        rearranjar_heap(v, i, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&v[0], &v[i]);
        rearranjar_heap(v, 0, i);
    }
}

/* -------------------- MAIN -------------------- */
int main() {
    int n;
    scanf("%d", &n);

    char comando[16];
    scanf("%15s", comando);

    int algoritmo;
    scanf("%d", &algoritmo);

    int* sequencia = (int*)malloc(sizeof(int) * n);
    if (!sequencia) return 1;

    if (strcmp(comando, "reverse") == 0)
        gerar_reverso(n, sequencia);
    else if (strcmp(comando, "random") == 0)
        gerar_aleatoria(n, sequencia);
    else if (strcmp(comando, "sorted") == 0)
        gerar_ordenada(n, sequencia);


    switch (algoritmo) {
        case 1:
            quickSort(sequencia, 0, n - 1);
            break;
        case 2:
            shellSort(sequencia, n);
            break;
        case 3:
            heapsort(sequencia, n);
            break;
        }
    

    init_crc32();
    uint32_t saida = crc32(0, sequencia, n * sizeof(int));
    printf("%08X", saida);

    free(sequencia);
    return 0;
}
