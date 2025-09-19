#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
João Pedro Neves: 14713404
Juan Pablo Tomba: 15638548
*/

int conta_letras(char string[]){
    char letra = string[0];
    if (letra == '-')
        return 0;
    
    return (isalnum(string[0])? 1 : 0) + conta_letras(string + 1);
  
}



void bubbleSort(char v[], int n, int* resultados){
    if (resultados != NULL){
        char temp;
        int trocas = 0;
        int comparacoes = 0;
        
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - i - 1; j++){
                comparacoes++;
                if (v[j] > v[j+1]){
                    temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                    trocas++;
                }
            }
        }

        resultados[0] = comparacoes;
        resultados[1] = trocas;
    }
    
}


int main(){
    char string[200];

    char USP[100000];
    char Externa[100000];

    int i = 0, j = 0;

    while (fgets(string, 201, stdin) != NULL){
        string[strcspn(string, "\n")] = '\0';
        int tamanho_string = strlen(string) - 1;
        if (string[tamanho_string] == 'a')
            Externa[i++] = (char)conta_letras(string);
        else
            USP[j++] = (char)conta_letras(string);
    }

    int resultados_USP[2];
    int resultados_Externa[2];
    
    bubbleSort(USP, j, resultados_USP);
    printf("USP - [");
    if (j > 0){
        for (int k = 0; k < j - 1; k++) printf("%d, ", USP[k]);
        printf("%d]\n", USP[j - 1]);
    } else {
        printf("]\n");
    }
    printf("Comparações: %d, Trocas: %d\n", resultados_USP[0], resultados_USP[1]);

    printf("\n");

    bubbleSort(Externa, i, resultados_Externa);
    printf("Externa - [");
    if (i > 0){
        for (int k = 0; k < i - 1; k++) printf("%d, ", Externa[k]);
        printf("%d]\n", Externa[i - 1]);
    } else {
        printf("]\n");
    }
    printf("Comparações: %d, Trocas: %d", resultados_Externa[0], resultados_Externa[1]);
    
    return 0;
}