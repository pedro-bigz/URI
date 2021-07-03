#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 50
#define TRUE "correct"
#define FALSE "incorrect"

typedef struct submit
{
    char id;
    unsigned int tempo;
    char status[M];
    unsigned int index;
} Submit;

int cmp (const void *, const void *);

int main ()
{
    char last_id;
    unsigned int i, n, s, inc, total, peso;

    while (scanf("%u%*c", &n) != EOF && n)
    {
        Submit x[n];

        for (i = 0; i < n; i++)
        {
            scanf("%c %u %s%*c", &x[i].id, &x[i].tempo, x[i].status);
            x[i].index = i;
        }

        qsort (x, n, sizeof(Submit), cmp);

        s = 0;
        inc = 0;
        peso = 0;
        total = 0;
        last_id = '0';
        for (i = 0; i < n; i++)
        {
            // printf("%u: %c %u %s\n", x[i].index, x[i].id, x[i].tempo, x[i].status);
            if (!strcmp (x[i].status, FALSE))
            {
                inc++;
            }
            else
            if (!strcmp (x[i].status, TRUE) && last_id != x[i].id)
            {
                peso = x[i].tempo;
                last_id = x[i].id;
                s++;
            }
            
            if (x[i + 1].id != x[i].id || i == n - 1)
            {
                if (x[i].id == last_id)
                {
                    total += peso + 20 * inc;
                }
                
                inc = 0;
                peso = 0;
            }
        }

        printf("%u %u\n", s, total);
    }

    return 0;
}

int cmp (const void *x, const void *y)
{
    Submit *a = (Submit *) x;
    Submit *b = (Submit *) y;

    if (a->id == b->id)
    {
        if (!strcmp(a->status, b->status))
        {
            return a->index - b->index;
        }
        else
        {
            return strcmp(a->status, b->status);
        }        
    }
    else
    {
        return a->id - b->id;
    }    
}
