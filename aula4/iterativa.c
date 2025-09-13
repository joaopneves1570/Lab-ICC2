#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

//função para verificar se é usp ou externo
bool usp_externo(char str[]) {
    int i = 0;
    while (str[i] != '-' && str[i] != '\0') {
        i++;
    }

    if (str[i + 1] == 'u') {
        return true;
    } else {
        return false;
    }
}

//função que retorna o tamanho do nome da pessoa 
int tam_nome(char str[]){
    char letra;
    int tam = 0, i = 0;
    while (str[i] != '-'){
        tam++;
        i++;
    }

    return tam;
}

//função para remover espaços
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

int main(){
    char frase[102];
    int usp[11], externo[11], tamanho_nome;
    int i = 0, j = 0, k = 0, l = 0;
    while (fgets(frase, sizeof(frase), stdin) != NULL){
        frase[strcspn(frase, "\n")] = '\0';
        remove_espaco(frase);
        tamanho_nome = tam_nome(frase);
        if (usp_externo(frase)){
            usp[i] = tamanho_nome;
            i++;
        }
        else{
            externo[j] = tamanho_nome;
            j++;
        }
    }

    printf("USP - [");
    for (int k = 0; k < i; k++) {
        if (k > 0) printf(", ");
        printf("%d", usp[k]);
    }
    printf("]\n");

    printf("Externa - [");
    for (int l = 0; l < j; l++) {
        if (l > 0) printf(", ");
        printf("%d", externo[l]);
    }
    printf("]");

    return 0;
}