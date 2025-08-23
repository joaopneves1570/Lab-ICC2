#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>  // Para QueryPerformanceCounter

int ehPalindromo(const char *str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        while (i < j && !isalnum((unsigned char)str[i])) i++;
        while (i < j && !isalnum((unsigned char)str[j])) j--;

        if (tolower((unsigned char)str[i]) != tolower((unsigned char)str[j])) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    char linha[1000];
    LARGE_INTEGER inicio, fim, freq;
    double tempo_execucao;

    QueryPerformanceFrequency(&freq); // Frequência do contador

    while (fgets(linha, sizeof(linha), stdin)) {
        linha[strcspn(linha, "\n")] = '\0';

        QueryPerformanceCounter(&inicio);
        int resultado = ehPalindromo(linha);
        QueryPerformanceCounter(&fim);

        tempo_execucao = (double)(fim.QuadPart - inicio.QuadPart) / freq.QuadPart;

        if (resultado) printf("Sim\n");
        else printf("Não\n");

        printf("Tempo de execucao: %.9f segundos\n", tempo_execucao);
    }

    return 0;
}
