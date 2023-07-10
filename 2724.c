#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct string {
    char str[100];
} String;

int
is_upper(char c)
{
    return c >= 65 && c <= 90;
}

int
contains(String teste, String * perigosos, int t)
{
    int i;
    char * ret;
    for (i = 0; i < t; i++) {
        ret = strstr(teste.str, perigosos[i].str);
        if (ret != NULL && ((ret + strlen(perigosos[i].str))[0] == 0 || is_upper((ret + strlen(perigosos[i].str))[0]))) {
            return 1;
        }
    }
    return 0;
}

void
solve(String * perigosos, int t, String * testes, int u)
{
    int i;
    for (i = 0; i < u; i++) {
        if (contains(testes[i], perigosos, t)) {
            printf("Abortar\n");
        } else {   
            printf("Prossiga\n");
        }
    }
}

int
main(int argc, char * argv[])
{
    int n, i, u, t;
    String * perigosos;
    String * testes;

    scanf("%d%*c", &n);

    while (n--) {
        scanf("%d%*c", &t);
        perigosos = (String *) malloc(t * sizeof(String));

        for (i = 0; i < t; i++) {
            scanf("%s%*c", perigosos[i].str);   
        }

        scanf("%d%*c", &u);
        testes = (String *) malloc(u * sizeof(String));

        for (i = 0; i < u; i++) {
            scanf("%s%*c", testes[i].str);   
        }

        solve(perigosos, t, testes, u);

        if (n > 0) {
            printf("\n");
        }
    }
    return 0;
}