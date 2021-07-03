#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100000

void limpa_buffer ();

int main ()
{
    unsigned int i, j, casos, count_t1, count_t2;
    char original[M], team1[M], team2[M];

    scanf("%u", &casos);

    for (i = 1; i <= casos; i++)
    {
        limpa_buffer ();
        scanf("%[^\n]", original);

        limpa_buffer ();
        scanf("%[^\n]", team1);

        limpa_buffer ();
        scanf("%[^\n]", team2);

        count_t1 = count_t2 = 0;
        for (j = 0; original[j] != '\0'; j++)
        {
            if (original[j] == team1[j])
            {
                count_t1++;
            }

            if (original[j] == team2[j])
            {
                count_t2++;
            }
        }

        printf("Instancia %u\n", i);

        if (count_t1 > count_t2)
        {
            printf("time 1\n");
        }
        else
        if (count_t1 < count_t2)
        {
            printf("time 2\n");
        }
        else
        {
            j = 0;
            while (j < strlen(original) && ((original[j] == team1[j] && original[j] == team2[j]) || (original[j] != team1[j] && original[j] != team2[j])))
            {
                j++;
            }

            if (j == strlen(original))
            {
                printf("empate\n");
            }
            else
            if (original[j] == team1[j])
            {
                printf("time 1\n");
            }
            else
            if (original[j] == team2[j])
            {
                printf("time 2\n");
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
