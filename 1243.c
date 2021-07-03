#include <stdio.h>
#include <string.h>
#define M 100
#define N 50
#define TRUE 1
#define FALSE 0
#define SPC " "

typedef int bool;
typedef unsigned int u_int;
 
void limpa_buffer ();
bool isWord (char *str);
bool isAlpha (char c);

int main()
{
    unsigned int i, count, words[N], md, sum;
    char texto[M];
    char *token;
    
    while (scanf("%[^\n]", texto) != EOF)
    {
        limpa_buffer();

        for (i = 0; i < N; i++)
        {
            words[i] = 0;
        }
        
        sum = 0;
        count = 0;
        token = strtok(texto, SPC);

        md = 0;
        while (token != NULL)
        {
            if (token[strlen(token) - 1] == '.')
            {
                token[strlen(token) - 1] = 0;
            }

            if (isWord(token))
            {
                sum += strlen(token);
                count++;
            }

            token = strtok(NULL, SPC);
        }

        md = (count) ? (sum / count) : FALSE;
        
        if (md <= 3)
        {
            printf("250\n");
        }
        else
        if (md <= 5)
        {
            printf("500\n");
        }
        else
        {
            printf("1000\n");
        }
    }
 
    return 0;
}

void limpa_buffer ()
{
    char c;
    while ((c = fgetc(stdin)) != EOF && c != '\n');
}

bool isWord (char *str)
{
    unsigned int i;

    if (!strlen(str))
    {
        return FALSE;
    }

    for (i = 0; str[i]; i++)
    {
        if (!isAlpha (str[i]))
        {
            return FALSE;
        }
    }

    return TRUE;
}

bool isAlpha (char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
