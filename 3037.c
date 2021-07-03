#include <stdio.h>
 
int main()
{
    int casos, d, x, joao, maria;

    scanf ("%d", &casos);

    while (casos--) {
        joao = maria = 0;

        for (unsigned int i = 0; i < 3; i++) {
            scanf("%d %d", &x, &d);
            joao += x * d;
        }
        
        for (unsigned int i = 0; i < 3; i++) {
            scanf("%d %d", &x, &d);
            maria += x * d;
        }

        printf ("%s\n", joao > maria ? "JOAO" : "MARIA");
    }    
 
    return 0;
}
