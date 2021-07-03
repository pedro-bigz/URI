#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100000

int main ()
{
    unsigned int i, casos, count;
    char s1[M], s2[M];

    scanf("%u", &casos);

    while (casos--)
    {
        scanf("%s %s", s1, s2);

        count = 0;
        for (i = 0; i < strlen(s1); i++)
        {
            if (s1[i] <= s2[i])
            {
                count += s2[i] - s1[i];
            }
            else
            {
                count += 122 - s1[i];
                count += s2[i] - 96;
            }            
        }

        printf("%u\n", count);
    }

    return 0;
}
