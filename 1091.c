#include <stdio.h>
 
int main()
{
    unsigned int i, k;
    int n, m, x, y;
    char Dx, Dy;
    
    while (scanf("%u", &k) != EOF && k)
    {
        scanf("%d %d", &n, &m);
        
        for (i = 0; i < k; i++)
        {
            scanf("%d %d", &x, &y);

            Dx = Dy = 0;

            if (y > m)
            {
                Dy = 'N';
            }
            else
            if (y < m)
            {
                Dy = 'S';
            }

            if (x > n)
            {
                Dx = 'E';
            }
            else
            if (x < n)
            {
                Dx = 'O';
            }

            if (!Dx || !Dy)
            {
                printf("divisa\n");
            }
            else
            {
                printf("%c%c\n", Dy, Dx);
            }
        }
    }
 
    return 0;
}
