#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXC 1001000

typedef struct consumo {
    unsigned int x;
    unsigned int y;
} Consumo;

int compar (const void *a, const void *b);

int main ()
{
    unsigned int count = 0;
    unsigned int i, n;
    double s_x, s_y;
    Consumo c[MAXC];
    // Consumo * c;

    for (i = 0; i < MAXC; i++)
    {
        c[i].x = 0;
        c[i].y = 0;
    }
    
    while(scanf("%u", &n) != EOF && n > 0)
    {
        if (count)
            printf("\n");

        s_x = 0;
        s_y = 0;
        // Consumo c[n];
        // c = (Consumo *) malloc(n * sizeof(Consumo));

        for (i = 0; i < n; i++)
        {
            scanf("%u %u", &c[i].x, &c[i].y);

            s_x += c[i].y;
            s_y += c[i].x;

            c[i].y /= c[i].x;
        }

        qsort (c, n, sizeof(Consumo), compar);
        
        printf("Cidade# %u:\n", ++count);
        
        for (i = 1; i < n; i++)
        {
            if (c[i - 1].y != c[i].y)
                printf("%u-%u ", c[i - 1].x, c[i - 1].y);
            else
                c[i].x += c[i - 1].x;
        }

        printf("%u-%u\n", c[i - 1].x, c[i - 1].y);
        printf("Consumo medio: %.2f m3.\n", floor(100 * (float) s_x / s_y) / 100);
    }
    
    return 0;
}

int compar (const void *a, const void *b)
{
    Consumo * a_t = (Consumo *)a;
    Consumo * b_t = (Consumo *)b;
    
    return (int) (a_t->y - b_t->y);
}
