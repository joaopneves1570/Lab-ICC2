#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *string = (char *)malloc(sizeof(char) * 150);

    while (fgets(string, 150, stdin) != NULL)
    {
        for (int i = 0; string[i] != '\0'; i++)
        {
            string[i] = string[i] + 1;
        }

        printf("%s", string);
    }

    free(string);
    return 0;
}