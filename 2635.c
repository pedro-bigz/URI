#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define M 110

typedef struct historico {
    char busca[M];
    unsigned int length;
} Hist;

bool issubstr (char *str1, char *str2);

int main ()
{
    unsigned int i, j, n, q, count, maior;

    while (scanf("%u", &n) != EOF)
    {        
        Hist last[n];

        for (i = 0; i < n; i++)
        {
            scanf("%s", last[i].busca);
            last[i].length = strlen(last[i].busca);
        }

        scanf("%u", &q);

        Hist searchs[q];

        for (i = 0; i < q; i++)
        {
            maior = 0;
            count = 0;
            scanf("%s", searchs[i].busca);
            searchs[i].length = strlen(searchs[i].busca);

            for (j = 0; j < n; j++)
            {
                if (issubstr(last[j].busca, searchs[i].busca))
                {
                    count++;
                    if (last[j].length > maior)
                    {
                        maior = last[j].length;
                    }
                }                
            }

            if (count)
            {
                printf("%u %u\n", count, maior);
            }
            else
            {
                printf("-1\n");
            }
            
        }

    }

    return 0;
}

bool issubstr (char *str1, char *str2)
{
    unsigned int i;
    for (i = 0; str2[i]; i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }

    return true;
}
