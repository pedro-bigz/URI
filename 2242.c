#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100
#define TRUE 1
#define FALSE 0

unsigned int isvogal(char c);
char * strrev (char *str);

int main ()
{
    unsigned int i, j;
    char r[] = {'N', 'S'};
    char str[M], vogais[M];

    scanf("%s", str);

    j = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (isvogal(str[i]))
        {
            vogais[j++] = str[i];
        }
    }

    vogais[j] = str[i];

    printf("%c\n", r[!strcmp(vogais, strrev(vogais))]);

    return 0;
}

unsigned int isvogal(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char * strrev (char *str)
{
    char * aux = (char *) malloc (M * sizeof(char));
    unsigned int i, j;
    for (i = 0, j = strlen(str) - 1; str[i] != '\0'; i++, j--)
    {
        aux[i] = str[j];
    }

    return aux;
}
