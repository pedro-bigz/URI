#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define FIRST 'A'
#define LAST 'Z'

int getExcess (char c, int n);
 
int main() {
    unsigned int casos, i, n;
    char str[50], aux;
    
    scanf("%u", &casos);
    
    while (casos--)
    {
        scanf("%s", str);
        scanf("%u", &n);
        
        for (i = 0; i < strlen(str); i++)
        {
            //aux = ;
            if (isupper((char) str[i] - n))
                str[i] -= n;
            else
            {
                str[i] = LAST - getExcess (str[i], n - 1);
                //printf("Excess: %d\n", getExcess (str[i], n));
            }
            
            //printf("%d\n", str[i]);
        }

        printf("%s\n", str);
    }
 
    return 0;
}

int getExcess (char c, int n)
{
    return n + FIRST - c;
}
