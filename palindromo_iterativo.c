#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// função que troca letras maiúsculas por minúsculas e "," por "backspace"
void limpafrase(char frase[], int tam){
    for (int i = 0; i < tam; i++){
        int aux = frase[i];
        if (aux > 64 && aux < 91){
            aux = aux + 32;
            frase[i] = (char)aux;
        }
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
        if (!isspace(str[j])) { 
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
    while (fgets(frase, sizeof(frase), stdin) != NULL){ //lê a string até EOF
        int tamanho = strlen(frase);
        frase[strcspn(frase, "\n")] = '\0';
        limpafrase(frase, tamanho);
        remove_espaco(frase);
        int tamanho2 = strlen(frase);
        ehpalindromo(frase, tamanho2);
    }

    return 0;
}