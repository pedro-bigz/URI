#include <stdio.h>
#include <stdlib.h>

int main ()
{
    unsigned int i, j, n, white_spaces;

    while (scanf("%u", &n) != EOF)
    {
        for (i = 1; i <= n; i += 2)
        {
            white_spaces = n - i;
            for (j = 0; j < white_spaces; j += 2)
            {
                printf(" ");
            }

            for (j = 0; j < i; j++)
            {
                printf("*");
            }
            
            printf("\n");
        }

        for (i = 1; i <= 3; i += 2)
        {
            white_spaces = n - i;
            for (j = 0; j < white_spaces; j += 2)
            {
                printf(" ");
            }

            for (j = 0; j < i; j++)
            {
                printf("*");
            } 
            
            printf("\n");
        }
        
        printf("\n");
    }

    return 0;
}
