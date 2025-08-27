#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>  // para QueryPerformanceCounter

// função que troca letras maiúsculas por minúsculas e remove caracteres não alfanuméricos
void limpafrase(char frase[], int tam){
    for (int i = 0; i < tam; i++){
        int aux = frase[i];
        if (aux > 64 && aux < 91){ // maiúsculas -> minúsculas
            aux = aux + 32;
            frase[i] = (char)aux;
        }
        // se não for letra nem número, substitui por espaço
        if (!((aux >= 48 && aux <= 57) || (aux >= 97 && aux <= 122))) {
            aux = 32;
            frase[i] = (char)aux;
        }
    }
}

// função que remove espaços da string
void remove_espaco(char str[]) {
    int i = 0; 
    int j = 0; 
    while (str[j] != '\0') { 
        if (!isspace((unsigned char)str[j])) { 
            str[i] = str[j]; 
            i++; 
        }
        j++; 
    }
    str[i] = '\0'; 
}

// função que verifica se é palíndromo e printa o resultado
void ehpalindromo(char str[], int tamanho){
    int inicio = 0, fim = tamanho - 1;
    for (int i = 0; i < (tamanho/2); i++){
        if (str[inicio] != str[fim]){
            printf("Não\n");
            return;
        }
        inicio++;
        fim--;
    }
    printf("Sim\n");
    return;
}

int main(){
    char frase[1002];
    LARGE_INTEGER inicio, fim, freq;
    double tempo_execucao;

    QueryPerformanceFrequency(&freq); // pega a frequência do contador

    while (fgets(frase, sizeof(frase), stdin) != NULL){ // lê até EOF
        int tamanho = strlen(frase);
        frase[strcspn(frase, "\n")] = '\0'; // remove '\n'

        // mede tempo da limpeza + verificação
        QueryPerformanceCounter(&inicio);

        limpafrase(frase, tamanho);
        remove_espaco(frase);
        int tamanho2 = strlen(frase);
        ehpalindromo(frase, tamanho2);

        QueryPerformanceCounter(&fim);

        tempo_execucao = (double)(fim.QuadPart - inicio.QuadPart) / freq.QuadPart;
        printf("Tempo de execucao: %.9f segundos\n", tempo_execucao);
    }

    return 0;
}
