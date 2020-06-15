#include <stdio.h>
#include <string.h>
#define OP '<'
#define CL '>'
#define AREIA '.'
 
int main() {
    int j;
    unsigned int i, casos, opened, temp, diamantes;
    char x[1000];
    
    scanf("%u", &casos);

    while(casos--)
    {
        opened = 0;
        diamantes = 0;
        scanf("%s", x);

        char aux[strlen(x)];
        
        for (i = 0; i < strlen(x); i++)
        {
            aux[opened] = AREIA;
            if (x[i] == OP)
            {
                aux[opened] = OP;
                opened++;
            }
            else if (x[i] == CL)
            {
                j = opened;
                while (j--)
                {
                    if(aux[j] == OP)
                    {
                        aux[j] = AREIA;
                        diamantes++;
                        opened--;
                        break;
                    }
                }
            }
        }
        
        printf("%d\n", diamantes);
    }
 
    return 0;
}
