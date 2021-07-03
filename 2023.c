#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define M 100

void limpa_buffer ();
char * strtolower (char str[]);

int main ()
{
    char name[M], maior[M] = "a";

    while (scanf("%[^\n]", name) != EOF)
    {
        limpa_buffer ();

        if (strcmp(strtolower(name), strtolower(maior)) > 0)
        {
            strcpy(maior, name);
        }
        
        memset(name, 0, M);
    }

    printf("%s\n", maior);

    return 0;
}

void limpa_buffer ()
{
    char c;
    while ((c = fgetc(stdin)) != EOF && c != '\n');
}

char * strtolower (char str[])
{
    char * aux = (char *) malloc ((strlen(str) + 1) * sizeof(char));
    unsigned int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        aux[i] = tolower(str[i]);
    }

    aux[i] = '\0';

    return aux;
}
