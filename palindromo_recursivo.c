#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


void limpaFrase(char *frase){
    int j = 0;
    for (int i = 0; frase[i] != '\0'; i++){
        if (frase[i] >= 'A' && frase[i] <= 'Z') frase[i] = frase[i] + 32;
        if ((frase[i] >= 'a' && frase[i] <= 'z') || (frase[i] >= '0' && frase[i] <= '9'))
           frase[j++] = frase[i];
    }
    frase[j] = '\0';
}

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
        char *resposta = ePalindromo(frase) ? "SIM" : "NÃO";
        printf("%s\n", resposta);
    }

    free(frase); frase = NULL;

    return 0;
}