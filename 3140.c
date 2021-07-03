#include <string.h>
#include <stdio.h>
#define MAXSTR 10000
#define TRUE 1
#define FALSE 0

typedef int bool;

int main()
{
    char html[MAXSTR];
    bool body = FALSE;

    while (scanf("%[^\n]%*c", html))
    {
        if (strstr(html, "<body>")) {
            body = TRUE;
            continue;
        }

        if (body && strstr(html, "</body>")) {
            body = FALSE;
            break;
        }

        if (body) {
            printf ("%s\n", html);
        }   
    }

    return 0;
}
