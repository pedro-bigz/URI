#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MNANE 100
#define MCOR 15
#define TRUE 1
#define FALSE 0

typedef struct camisa {
    char nome[MNANE];
    char cor[MCOR];
    char tam;
} Camisas;

void limpa_buffer ();
int compar (const void *a, const void *b);

int main ()
{
    unsigned int i, n, first = TRUE;

    while (scanf("%u", &n) != EOF && n)
    {
        if (!first)
        {
            printf("\n");
        }

        Camisas cam[n];

        limpa_buffer ();
        for (i = 0; i < n; i++)
        {
            scanf("%[^\n]", cam[i].nome);
            limpa_buffer ();
            scanf("%s %c", cam[i].cor, &cam[i].tam);
            limpa_buffer ();
        }

        qsort(cam, n, sizeof(Camisas), compar);

        for (i = 0; i < n; i++)
        {
            printf("%s %c %s\n", cam[i].cor, cam[i].tam, cam[i].nome);
        }

        first = FALSE;
    }

    return 0;
}

void limpa_buffer ()
{
    char c;
    while ((c = fgetc(stdin)) != EOF && c != '\n');
}

int compar (const void *a, const void *b)
{
    Camisas *c1 = (Camisas *) a;
    Camisas *c2 = (Camisas *) b;

    if (!strcmp(c1->cor, c2->cor))
    {
        if (c1->tam == c2->tam)
        {
            return strcmp(c1->nome, c2->nome);
        }
        else
        {
            return c2->tam - c1->tam;
        }
        
    }
    else
    {
        return strcmp(c1->cor, c2->cor);
    }
    
}
