#include "util.h"


void gerar_reverso(int n, int* sequencia){
    for (int i = 0; i < n; i++)
        sequencia[i] = n-i;
}

void gerar_aleatoria(int n, int* sequencia){
    int seed = 12345;
    for (int i = 0; i < n; i++){
        int random = get_random(&seed, n);
        sequencia[i] = random;
    }
}

void gerar_ordenada(int n, int* sequencia){
    for (int i = 0; i < n; i++){
        sequencia[i] = i + 1;
    }
}

// void mostrar_sequencia(int* sequencia, int n){
//     for (int i = 0; i < n; i++){
//         printf("%d", sequencia[i]);
//     }
//     printf("\n");
// }

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void combina(int s[], int inicio, int meio, int fim){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int* esq = (int*)malloc(sizeof(int)*n1);
    int* dir = (int*)malloc(sizeof(int)*n2);

    for (int i = 0; i < n1; i++)
        esq[i] = s[inicio + i];

    for (int j = 0; j < n2; j++)
        dir[j] = s[meio + 1 + j];
    
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2) {
    if (esq[i] <= dir[j])
        s[k++] = esq[i++];
    else
        s[k++] = dir[j++];
    }   

    while (i < n1)
        s[k++] = esq[i++];
    while (j < n2)
        s[k++] = dir[j++];

    free(esq);
    free(dir);

}

void merge_sort(int s[], int inicio, int fim){
    if (inicio < fim){
        int meio =  (inicio + fim)/2;
        merge_sort(s, inicio, meio);
        merge_sort(s, meio + 1, fim);
        combina(s, inicio, meio, fim);
    }
}

void heapify(int s[], int n, int i) {
    
    int pai = i; 
    int esq = 2 * i + 1; 
    int dir = 2 * i + 2;
    
    if (esq < n && s[esq] > s[pai]) {
        pai = esq;
    }

    if (dir < n && s[dir] > s[pai]) {
        pai = dir;
    }
    
    if (pai != i) {
        swap(&s[pai], &s[i]);
        heapify(s, n, pai);
    }
}

void heapSort(int s[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(s, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&s[0], &s[i]);
        heapify(s, i, 0);
    }
}

int partition(int s[], int inicio, int fim) {
    
    int pivo = s[fim];
    int i = inicio - 1;

    for (int j = inicio; j <= fim - 1; j++) {
        if (s[j] < pivo) {
            i++;
            swap(&s[i], &s[j]);
        }
    }
    
    swap(&s[i + 1], &s[fim]);  
    return i + 1;
}


void quickSort(int s[], int inicio, int fim) {
    if (inicio < fim) {
        
        int pi = partition(s, inicio, fim);
        quickSort(s, inicio, pi - 1);
        quickSort(s, pi + 1, fim);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    char* comando = (char*)malloc(sizeof(char)* 10);
    scanf("%s", comando);

    int algoritmo;
    scanf("%d", &algoritmo);

    int* sequencia = (int*)malloc(sizeof(int) * n);
    
    if (strcmp(comando, "reverse") == 0)
        gerar_reverso(n, sequencia);
    if (strcmp(comando, "random") == 0)
        gerar_aleatoria(n, sequencia);
    if (strcmp(comando, "sorted") == 0)
        gerar_ordenada(n, sequencia);


    switch(algoritmo){
        case 2:
            merge_sort(sequencia, 0, n - 1);
            break;

        case 1:
            heapSort(sequencia, n);
            break;

        case 3:
            quickSort(sequencia, 0, n-1);
            break;
    }


    init_crc32();
    uint32_t saida = crc32(0, sequencia, n * sizeof(int));
    printf("%08X", saida);

    free(comando);
    free(sequencia);

    return 0;
}