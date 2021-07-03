#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int bool;

bool ehCaprino (int *v, int n, int num);
int mdc (int a, int b);

int main ()
{
    bool c;
    unsigned int i, n, maior = 0;

    scanf("%u", &n);

    unsigned int duendes[n];

    for (i = 0; i < n; i++)
    {
        scanf("%u", &duendes[i]);
        if (duendes[i] > maior)
        {
            maior = duendes[i];
        }
    }

    printf("%u\n", ++maior);

    // maior++;
    // while (!ehCaprino (duendes, n, maior))
    // {
    //     maior++;
    // }

    // printf("%u\n", maior);

    return 0;
}

bool ehCaprino (int *v, int n, int num)
{
    unsigned int i;
    for (i = 0; i < n; i++)
    {
        if (mdc(num, v[i]) != 1)
            return FALSE;
    }

    return TRUE;
}

int mdc (int a, int b)
{
    unsigned int tpA, tpB, q;   

    q = a / b;
    while (a % b)
    {
        tpA = a;
        tpB = b;
        a = b;
        b = tpA % tpB;  
        q = a / b;      
    }

    return q;
}
