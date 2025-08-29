#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cidade
{
    char cidade[50];
    int populacao;
} Cidade;

int main()
{
    int n;
    scanf("%d\n", &n);

    if (n < 2 || n > 10)
    {
        printf("n fora do intervalo.\n");
        return 0;
    }

    int maior = 0;
    Cidade *cidades = (Cidade *)malloc(sizeof(Cidade) * n);

    for (int i = 0; i < n; i++)
    {
        char *nome = (char *)malloc(sizeof(char) * 50);
        int pop;

        fgets(nome, 51, stdin);
        scanf("%d\n", &pop);

        strcpy(cidades[i].cidade, nome);
        cidades[i].cidade[strcspn(cidades[i].cidade, "\r\n")] = '\0';
        cidades[i].populacao = pop;

        if (pop > maior)
            maior = pop;

        free(nome);
    }

    for (int i = 0; i < n; i++)
    {
        if (cidades[i].populacao == maior)
        {
            printf("%s %d", cidades[i].cidade, cidades[i].populacao);
            break;
        }
    }

    free(cidades);

    return 0;
}