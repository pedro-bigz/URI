#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define PEDRA "pedra"
#define PAPEL "papel"
#define TESOURA "tesoura"
#define LAGARTO "lagarto"
#define SPOCK "spock"
#define QNT 5
 
int main()
{
    char sheldon[15], rajesh[15];
    char p[5][15] = {TESOURA, PAPEL, PEDRA, LAGARTO, SPOCK};
    int casos, i;
    int info[QNT][2][2] = {
      {{2, 4}, {1, 3}},
      {{0, 3}, {2, 4}},
      {{1, 4}, {3, 0}},
      {{2, 0}, {4, 1}},
      {{3, 1}, {0, 2}}
    };

    char * str1, * str2, * str3, * str4;

    scanf("%d", &casos);

    while (casos--)
    {
        scanf("%s %s", rajesh, sheldon);

        if (!strcmp(rajesh, sheldon))
            printf("empate\n");
        else
        {
            for (i = 0; i < QNT; i++)
            {
                if (!strcmp(rajesh, p[i]))
                {
                    str1 = p[info[i][FALSE][FALSE]];
                    str2 = p[info[i][FALSE][TRUE]];
                    str3 = p[info[i][TRUE][FALSE]];
                    str4 = p[info[i][TRUE][TRUE]];
                    if (!strcmp(str1, sheldon) || !strcmp(str2, sheldon))
                    {
                        printf("sheldon\n");
                        break;
                    }
                    else
                    if (!strcmp(str3, sheldon) || !strcmp(str4, sheldon))
                    {
                        printf("rajesh\n");
                        break;
                    }
                }
            }

        }
    }
 
    return 0;
}
