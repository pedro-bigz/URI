#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define M 20

bool checkChar (char c);

int main ()
{
    unsigned int i, j, n, casos;
    char senha[M];

    scanf("%u", &casos);

    while (casos--)
    {
        scanf("%s", senha);

        n = 1;
        for (i = 0; senha[i] != '\0'; i++)
        {
            if (checkChar (tolower(senha[i])))
            {
                n *= 3;
            }
            else
            {
                n *= 2;
            }
        }

        printf("%u\n", n);
    }

    return 0;
}

bool checkChar (char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 's');
}
