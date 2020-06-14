#include <stdio.h>
#include <string.h>

int menor_str (char str1[], char str2[]);
int maior_str (char str1[], char str2[]);
 
int main() {
    unsigned int casos, i, j, menor, maior;
    char str1[50], str2[50], response[100];
    
    scanf("%u", &casos);
    
    while(casos--)
    {
        scanf("%s %s", str1, str2);
        
        menor = menor_str(str1, str2);
        maior = maior_str(str1, str2);
        
        j = 0;
        for (i = 0; i < menor; i++)
        {
            response[j++] = str1[i];
            response[j++] = str2[i];
        }
        
        for (i = menor; i < maior; i++)
        {
            if (strlen(str1) == menor)
                response[j++] = str2[i];
            else
                response[j++] = str1[i];
        }
    }
 
    return 0;
}

int menor_str (char str1[], char str2[])
{
    return (strlen(str1) < strlen(str2)) ? strlen(str1) : strlen(str2);
}

int maior_str (char str1[], char str2[])
{
    return (strlen(str1) > strlen(str2)) ? strlen(str1) : strlen(str2);
}
