#include <stdio.h>
#include <string.h>
#define OP '('
#define CL ')'
#define NEUTRO '-'
 
int main() {
    int j;
    unsigned int i, n, opened, temp;
    char x[1000];
    
    scanf("%u", &n);

    while(scanf("%s", x) != EOF)
    {
        opened = 0;

        char aux[strlen(x)];
        
        for (i = 0; i < strlen(x); i++)
        {
            aux[opened] = NEUTRO;
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
                        aux[j] = NEUTRO;
                        opened--;
                        break;
                    }
                }

                if (j < 0)
                {
                    aux[opened] = CL;
                    opened++;
                }
            }
        }
        
        if (!opened)
            printf("correct\n");
        else
            printf("incorrect\n");
    }
 
    return 0;
}
