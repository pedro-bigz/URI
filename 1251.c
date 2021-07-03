#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 95
#define TAM 10000
#define TRUE 1
#define FALSE 0

typedef int bool;

typedef struct caracteres {
    unsigned int qtd;
    unsigned int code;
} Caracteres;

unsigned int getKey (char c);
int compar (const void *, const void *);

int main ()
{
    char string[TAM];
    unsigned int i, j, k, maior, aux, temp[M];
    Caracteres arr[M];
    bool first = TRUE;

    while (scanf(" %[^\n]", string) != EOF)
    {
        if (!first)
        {
            printf("\n");
        }
        
        for (i = 0; i < M; i++)
        {
            arr[i].qtd = 0;
            arr[i].code = 0;
        }

        for (i = 0; string[i] != '\0'; i++)
        {
            k = getKey(string[i]);            
            arr[k].qtd++;

            if (arr[k].qtd == 1)
            {
                arr[k].code = (unsigned int) string[i];
            }
        }

        qsort (arr, M, sizeof(Caracteres), compar);

        for (i = 0; i < M - 1 && arr[i].qtd; i++)
        {
            maior = i;
            for (j = i + 1; j < M && arr[j].qtd && arr[i].qtd == arr[j].qtd; j++)
            {
                if (arr[maior].code < arr[j].code)
                {
                    maior = j;
                }
            }

            aux = arr[i].code;
            arr[i].code = arr[maior].code;
            arr[maior].code = aux;
        }
        
        for (i = 0; i < M && arr[i].qtd; i++)
        {
            printf("%u %u\n", arr[i].code, arr[i].qtd);
        }
        
        first = FALSE;
    }

    return 0;
}

unsigned int getKey (char c)
{
    return (unsigned int) c - 33;
}

int compar (const void * a, const void * b)
{
    Caracteres *x = (Caracteres *) a;
    Caracteres *y = (Caracteres *) b;

    if (x->qtd + y->qtd == 0)
    {
        return 0;
    }
    else
    if (x->qtd == 0)
    {
        return 1;
    }
    else
    if (y->qtd == 0)
    {
        return -1;
    }
    else
    {
        return x->qtd - y->qtd;
    }
}
