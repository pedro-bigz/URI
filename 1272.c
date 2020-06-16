#include <stdio.h>
#include <math.h>
#include <string.h>
#define CARLOS "Carlos"
#define BETO "Beto"
#define RAFAEL "Rafael"

int carlos (int x, int y);
int beto (int x, int y);
int rafael (int x, int y);
int maior (int a, int b, int c);

int main () 
{
    char names[3][10] = {CARLOS, BETO, RAFAEL};
    int x, y, casos;

    scanf ("%d", &casos);

    while (casos--)
    {
        scanf ("%d %d", &x, &y);

        printf("%s ganhou\n", names[maior (carlos(x, y), beto(x, y), rafael(x, y))]);
    }

    return 0;
}

int carlos (int x, int y)
{
    return -100 * x + pow (y, 3);
}

int beto (int x, int y)
{
    return 2 * pow(x, 2) + pow((5 * y), 2);
}

int rafael (int x, int y)
{
    return pow(3 * x, 2) + pow(y, 2);
}

int maior (int a, int b, int c)
{
    int maior = a;
    int pos = 0;

    if (maior < b)
    {
        maior = b;
        pos = 1;
    }

    if (maior < c)
    {
        maior = c;
        pos = 2;
    }

    return pos;
}
