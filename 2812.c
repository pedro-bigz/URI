#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compar1 (const void * a, const void * b);
unsigned int getKey (int length, int index);
void limpa_buffer ();

int main ()
{
    unsigned int n, m, i, j, temp;

    scanf ("%u", &n);

    while (n--)
    {
        scanf ("%u", &m);

        unsigned int v1[m];
        
        j = 0 ;
        for (i = 0; i < m; i++)
        {
            scanf (" %u", &temp);

            if (temp % 2)
            {
                v1[j++] = temp;
            }
        }

        qsort (v1, j, sizeof(unsigned int), compar1); 

        for (i = 0; i < j; i++)
        {
            printf ("%u%c", v1[getKey(j - 1, i)], (i == j - 1) ? '\n' : ' ');
        }

        if (j == 0)
        {
            printf("\n");
        }

        limpa_buffer ();
    }

    return 0;
}

int compar1 (const void * a, const void * b)
{
    return ( *(unsigned int *)a - *(unsigned int *)b );
}

unsigned int getKey (int length, int index)
{
    return (length * !(index % 2)) - pow(-1, index) * index/2;
}

void limpa_buffer ()
{
    char c;
    while ((c = fgetc(stdin)) != EOF && c != '\n');
}
