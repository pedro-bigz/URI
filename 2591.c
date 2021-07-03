#include <stdio.h>
#define M 300
 
int main()
{
    unsigned int a, i, casos, total;
    char golpe[M];

    scanf("%u%*c", &casos);

    while (casos--)
    {
        scanf("%s%*c", golpe);

        a = 0;
        total = 1;
        for (i = 0; golpe[i]; i++)
        {
            if (golpe[i] == 'a')
            {
                a++;
            }
            else
            if (a)
            {
                total *= a;
                a = 0;
            }
        }

        if (a)
        {
            total *= a;
        }

        printf("k");
        for (i = 0; i < total; i++)
        {
            printf("a");
        }

        printf("\n");
    }

    return 0;
}
