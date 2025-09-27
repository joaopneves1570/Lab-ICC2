#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct brinquedo B;

enum peso{
    primeiro,
    segundo,
    terceiro,
    quarto,
    quinto,
    sexto,
    setimo
};

struct brinquedo{
    float tamanho;
    float nota;
    int id;
    enum peso ordem;
};

int comparaBrinquedos(B brinquedo1, B brinquedo2){
    if (brinquedo1.ordem != brinquedo2.ordem)
        return (brinquedo1.ordem > brinquedo2.ordem ? 1 : 0);
    
    if (brinquedo1.tamanho != brinquedo2.tamanho)
        return (brinquedo1.tamanho > brinquedo2.tamanho ? 1 : 0);
    
    if (brinquedo1.nota != brinquedo2.nota)
        return (brinquedo1.nota < brinquedo2.nota ? 1 : 0);

    return (brinquedo1.id > brinquedo2.id ? 1 : 0);
}

void bubbleSort(B brinquedos[], int n){
    B aux;
    for (int i = 0; i < n; i++){
        int trocou = 0;
        for (int j = 0; j < n - 1 - i; j++){
            if (comparaBrinquedos(brinquedos[j], brinquedos[j+1])){
                aux = brinquedos[j];
                brinquedos[j] = brinquedos[j+1];
                brinquedos[j+1] = aux;
                trocou = 1;
            }
        }
        if (trocou == 0) break;
    }
}

void insertionSort(B brinquedos[], int n){
    B aux;
 
    for (int i = 0; i < n; i++){
        B atual = brinquedos[i];
        int j = i - 1;
        while (j >= 0 && comparaBrinquedos(brinquedos[j], atual)){
            brinquedos[j+1] = brinquedos[j];
            j = j - 1;
        }
        brinquedos[j+1] = atual;
    }
}

void combina(B brinquedos[], int inicio, int meio, int fim){
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    B* esq = (B*)malloc(sizeof(B)*n1);
    B* dir = (B*)malloc(sizeof(B)*n2);

    for (int i = 0; i < n1; i++)
        esq[i] = brinquedos[inicio + i];
    for (int j = 0; j < n2; j++)
        dir[j] = brinquedos[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2){
        if (!comparaBrinquedos(esq[i], dir[j])){
            brinquedos[k++] = esq[i++];
        } else {
            brinquedos[k++] = dir[j++];
        }
    }

    while (i < n1){
        brinquedos[k++] = esq[i++];
    }

    while (j < n2){
        brinquedos[k++] = dir[j++];
    }

    free(esq);
    free(dir);

}

void mergeSort(B brinquedos[], int inicio, int fim){
    if (inicio < fim){
        int meio = (inicio + fim)/2;
        mergeSort(brinquedos, inicio, meio);
        mergeSort(brinquedos, meio + 1, fim);
        combina(brinquedos, inicio, meio, fim);
    }
}

int reparte(B brinquedos[], int inicio, int fim){
    B pivo = brinquedos[fim];

    B aux;

    int j = inicio;
    int i = j - 1;
    for(j; j < fim; j++){
        if (comparaBrinquedos(pivo, brinquedos[j])){
            i++;
            aux = brinquedos[i];
            brinquedos[i] = brinquedos[j];
            brinquedos[j] = aux;
        }
    }

    aux = brinquedos[i + 1];
    brinquedos[i + 1] = brinquedos[fim];
    brinquedos[fim] = aux;

    return i + 1;
}

void quickSort(B brinquedos[], int inicio, int fim){
    if (inicio < fim){
        int pivo = reparte(brinquedos, inicio, fim);

        quickSort(brinquedos, inicio, pivo - 1);
        quickSort(brinquedos, pivo + 1, fim);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char cores[7][10] = {"amarelo", "azul", "branco", "preto", "rosa", "verde", "vermelho"};

    B* brinquedos = (B*)malloc(sizeof(B)* n);
    for (int i = 0; i < n; i++){
        char cor[20];
        float tamanho, nota;
        scanf("%s %f %f", cor, &tamanho, &nota);
        
        brinquedos[i].tamanho = tamanho;
        brinquedos[i].nota = nota;
        brinquedos[i].id = i;

        for (int j = 0; j < 7; j++){
            if (strcmp(cor, cores[j]) == 0){
                brinquedos[i].ordem = j;
                break;
            }
        }        
    }
    
    int ordenador;
    scanf("%d", &ordenador);

    switch (ordenador)
    {
    case 1:
        bubbleSort(brinquedos, n);
        break;
    
        case 2:
        insertionSort(brinquedos, n);
        break;
        
        case 3:
        mergeSort(brinquedos, 0, n-1);
        break;

    default:
        quickSort(brinquedos, 0, n-1);
        break;
    }

    for (int i = 0; i < n; i++){
        printf("%d;", brinquedos[i].id);
    }

    free(brinquedos);
    return 0;
}