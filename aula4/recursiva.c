#include <stdio.h>
#include <ctype.h>
#include <string.h>

int conta_letras(char string[]){
    char letra = string[0];
    if (letra == '-')
        return 0;
    
    return (isalnum(string[0])? 1 : 0) + conta_letras(string + 1);

  
}


int main(){
    char string[50];

    int USP[100];
    int Externa[100];

    int i = 0, j = 0;

    while (fgets(string, 50, stdin) != NULL){
        string[strcspn(string, "\n")] = '\0';
        int tamanho_string = strlen(string) - 1;
        if (string[tamanho_string] == 'a')
            Externa[i++] = conta_letras(string);
        else
            USP[j++] = conta_letras(string);
    }
    
    printf("USP - [");
    if (j > 0){
        for (int k = 0; k < j - 1; k++) printf("%d, ", USP[k]);
        printf("%d]\n", USP[j - 1]);
    } else {
        printf("]\n");
    }

    printf("Externa - [");
    if (i > 0){
        for (int k = 0; k < i - 1; k++) printf("%d, ", Externa[k]);
        printf("%d]\n", Externa[i - 1]);
    } else {
        printf("]\n");
    }
    
    return 0;
}