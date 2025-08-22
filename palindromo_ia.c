#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se a string é palíndromo
int ehPalindromo(const char *str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        // Ignorar não alfanuméricos
        while (i < j && !isalnum((unsigned char)str[i])) i++;
        while (i < j && !isalnum((unsigned char)str[j])) j--;

        // Comparar em minúsculas
        if (tolower((unsigned char)str[i]) != tolower((unsigned char)str[j])) {
            return 0; // Não é palíndromo
        }

        i++;
        j--;
    }

    return 1; // É palíndromo
}

int main() {
    char linha[1000];

    // Lê até EOF
    while (fgets(linha, sizeof(linha), stdin)) {
        // Remove '\n' do final, se houver
        linha[strcspn(linha, "\n")] = '\0';

        if (ehPalindromo(linha)) {
            printf("Sim\n");
        } else {
            printf("Não\n");
        }
    }

    return 0;
}
