#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//Função que "limpa a frase", retira caracteres não alfanuméricos.
void limpaFrase(char *frase){
    int j = 0;
    for (int i = 0; frase[i] != '\0'; i++){
        if (frase[i] >= 'A' && frase[i] <= 'Z') frase[i] = frase[i] + 32;
        if ((frase[i] >= 'a' && frase[i] <= 'z') || (frase[i] >= '0' && frase[i] <= '9'))
           frase[j++] = frase[i];
    }
    frase[j] = '\0';
}

//Função recursiva que verifica se é palíndromo ou não
//A função compara o primeiro caractere da string limpa com o último e retorna falso caso sejam diferentes
//Caso sejam iguais, ela cria uma nova string sem esses mesmos caracteres e chama a função de novo para essa nova string
bool ePalindromo(char *frase){
    if (((int)(strlen(frase) - 1 )< 1)){
        return true;
    }

    if (frase[0] == frase[strlen(frase)-1]){
        char *novaFrase = (char*)malloc(sizeof(char)*(strlen(frase)));
        int j = 0;
        for (int i = 1; i < strlen(frase) - 1; i++){
            novaFrase[j] = frase[i];
            j++;
        }
        novaFrase[j] = '\0';
        strcpy(frase, novaFrase);
        free(novaFrase); novaFrase = NULL;
        return ePalindromo(frase);
    } else {
        return false;
    }
    
}

int main(){
    char *frase = (char*)malloc(sizeof(char)* 1002);
    while (fgets(frase, 1002, stdin) != NULL){
        limpaFrase(frase);
        char *resposta = ePalindromo(frase) ? "Sim" : "Não";
        printf("%s\n", resposta);
    }

    free(frase); frase = NULL;

    return 0;
}