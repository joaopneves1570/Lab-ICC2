#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    float nota;
    int aprovado;
} ALuno;

int buscarAprovados(ALuno *alunos, int nmrAlunos)
{
    int nmrAprovados = 0;
    for (int i = 0; i < nmrAlunos; i++)
    {
        if (alunos[i].aprovado == 1)
        {
            nmrAprovados++;
        }
    }

    return nmrAprovados;
}

float buscarMaior(ALuno *alunos, int nmrAlunos)
{
    float maior = 0.0;
    for (int i = 0; i < nmrAlunos; i++)
    {
        if (alunos[i].nota > maior)
        {
            maior = alunos[i].nota;
        }
    }

    return maior;
}

float calcularMedia(ALuno *alunos, int nmrAlunos)
{
    float media = 0;
    for (int i = 0; i < nmrAlunos; i++)
    {
        media += alunos[i].nota;
    }

    media = media / (float)nmrAlunos;

    return media;
}

int main()
{
    int nmrAlunos;
    scanf("%d\n", &nmrAlunos);

    if (nmrAlunos < 1)
        return 0;

    ALuno *alunos = (ALuno *)malloc(sizeof(ALuno) * nmrAlunos);

    for (int i = 0; i < nmrAlunos; i++)
    {
        scanf("%f", &alunos[i].nota);
        if (alunos[i].nota < 0.0 || alunos[i].nota > 10.0)
        {
            printf("Nota fora do intervalo.");
            return 0;
        }
        if (alunos[i].nota >= 5.0)
        {
            alunos[i].aprovado = 1;
        }
        else
        {
            alunos[i].aprovado = 0;
        }
    }

    int aprovados = buscarAprovados(alunos, nmrAlunos);
    float maior = buscarMaior(alunos, nmrAlunos);
    float media = calcularMedia(alunos, nmrAlunos);

    printf("Foram %d aprovado(s). Maior nota = %.2f. Nota média = %.2f.", aprovados, maior, media);
    return 0;
}