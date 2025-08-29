#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mes
{
    int id;
    char nome[30];
    int dataLimite;
} Mes;

void inicializaMeses(Mes *meses)
{
    char nomeMeses[][15] = {"janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    for (int i = 0; i < 12; i++)
    {
        meses[i].id = i + 1;
        strcpy(meses[i].nome, nomeMeses[i]);
        if (i == 1)
        {
            meses[i].dataLimite = 28;
        }
        else if (i % 2 == 0 && i < 7)
        {
            meses[i].dataLimite = 31;
        }
        else if (i % 2 != 0 && i >= 7)
        {
            meses[i].dataLimite = 31;
        }
        else
        {
            meses[i].dataLimite = 30;
        }
    }
}

int verificaAno(int ano, Mes *meses)
{
    if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))
    {
        meses[1].dataLimite = 29;
        return 1;
    }
    else
    {
        return 0;
    }
}

int verificaMes(Mes *meses, int dia, int mes)
{
    for (int i = 0; i < 12; i++)
    {
        if (meses[i].id == mes)
        {
            if (dia > 0 && dia <= meses[i].dataLimite)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

int main()
{

    Mes *meses = (Mes *)malloc(sizeof(Mes) * 12);

    char *data = (char *)malloc(sizeof(char) * 15);
    while (fgets(data, 15, stdin) != NULL)
    {
        inicializaMeses(meses);
        int dia = (data[0] - '0') * 10 + (data[1] - '0');
        int mes = (data[3] - '0') * 10 + (data[4] - '0');
        int ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + (data[8] - '0') * 10 + (data[9] - '0');

        int eBissexto = verificaAno(ano, meses);
        int taNoMes = verificaMes(meses, dia, mes);

        char string1[50]; // espaço suficiente para o texto
        char string2[50];

        if (eBissexto)
        {
            sprintf(string1, "%d é bissexto.", ano);
        }
        else
        {
            sprintf(string1, "%d não é bissexto.", ano);
        }

        if (taNoMes)
        {
            sprintf(string2, "Existe o dia %d em %s.", dia, meses[mes - 1].nome);
        }
        else
        {
            sprintf(string2, "Não existe o dia %d em %s.", dia, meses[mes - 1].nome);
        }

        printf("%s %s\n", string1, string2);
    }
    return 0;
}