#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define M 2000000
#define EQ "="
#define SM "+"
 
int main()
{
    int a, b, r;
    char input[M];
    char *soma, *result, *temp;
    
    while (scanf("%s%*c", input) != EOF)
    {
        soma = strtok(input, EQ);
        result = strtok(NULL, EQ);
        
        if (isdigit(result[0]))
        {
            a = atoi (result);
            temp = strtok(soma, SM);
            if (isdigit(temp[0]))
            {
                b = atoi (temp);
                r = a - b;
            }
            else
            {
                b = atoi (strtok(NULL, SM));
                r = a - b;
            }
        }
        else
        {
            a = atoi (strtok(soma, SM));
            b = atoi (strtok(NULL, SM));
            r = a + b;
        }

        printf("%d\n", r);
    }
 
    return 0;
}
