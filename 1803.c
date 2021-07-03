#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LIN 4
#define COL 1000

int potencia (int base, int exp);

int main ()
{
    char str[COL], ascii;
    unsigned int i, j, k = 3, n, first, last;
    
    scanf("%s%*c", str);
    n = strlen(str);

    unsigned int cod[n];

    for (i = 0; i < n; i++)
    {
        cod[i] = potencia (10, k) * (str[i] - 48);
    }

    for (i = 1; i < LIN; i++)
    {
        k--;
        memset(str, 0, n);
        scanf("%s%*c", str);

        for (j = 0; j < n; j++)
        {
            cod[j] += potencia (10, k) * (str[j] - 48);
        }
    }

    first = cod[0];
    last = cod[n - 1];

    for (i = 1; i < n - 1; i++)
    {
        ascii = (first * cod[i] + last) % 257;
        printf("%c", ascii);
    }

    printf("\n");

    return 0;
}

int potencia (int base, int exp)
{
    unsigned int i, p = 1;
    for (i = 0; i < exp; i++)
    {
        p *= base;
    }

    return p;
}
