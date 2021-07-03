#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 27
#define TRUE 1
#define FALSE 0

void limpa_buffer ();
int cmp (const void * a, const void * b);

int main ()
{
    unsigned int i, j, k, n, cheater;
    char dieta[M], cafe[M + M], almoco[M];

    scanf("%u%*c", &n);
    // limpa_buffer (); 

    while (n--)
    { 
        cheater = FALSE;
        
        memset(dieta, 0, sizeof(dieta));
        memset(cafe, 0, sizeof(cafe));
        memset(almoco, 0, sizeof(almoco));

        scanf("%[^\n]", dieta);
        limpa_buffer (); 

        scanf("%[^\n]", cafe);
        limpa_buffer (); 

        scanf("%[^\n]", almoco);
        limpa_buffer (); 
        
        strcat(cafe, almoco);

        qsort(dieta, strlen(dieta), sizeof(char), cmp);

        // printf("%s\n", dieta);
        // printf("%s\n", cafe);

        for (i = 0; i < strlen(cafe); i++)
        {
            if (!strchr(dieta, cafe[i]))
            {
                printf("CHEATER");
                cheater = TRUE;
                break;
            }
        }

        for (i = 0; i < strlen(dieta); i++)
        {
            if (cheater)
            {
                break;
            }

            if (!strchr(cafe, dieta[i]))
            {
                printf("%c", dieta[i]);
            }
        }  

        printf("\n");    
    }

    return 0;
}

void limpa_buffer ()
{
    char c;
    while ((c = fgetc(stdin)) != EOF && c != '\n');
}

int cmp (const void * a, const void * b)
{
    return *(char *)a - *(char *)b;
}
