#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 20

int main () 
{
    char lang[M], old[M];
    unsigned int casos, count, n, i;

    scanf("%u", &casos);

    while (casos--)
    {
        count = 1;
        scanf("%u", &n);
        scanf("%s", old);

        i = n;
        while (--i)
        {
            scanf("%s", lang);

            if (!strcmp(lang, old))
            {
                count++;
            }
        }

        printf("%s\n", (count == n) ? lang : "ingles");
    }

    return 0;
}
