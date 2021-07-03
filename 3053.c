#include <stdio.h>

void limpa_buffer ();
int getKey (char c);
char getReverseKey (int key);
void movementOne (int * array);
void movementTwo (int * array);
void movementThree (int * array);
void exchange (int * a, int * b);
 
int main()
{
    unsigned short movement;
    int n, cupGames[] = {0, 0, 0};
    char select;

    scanf ("%d", &n);
    limpa_buffer ();
    scanf ("%c", &select);
    
    cupGames[getKey(select)] = 1;

    for (unsigned int i = 0; i < n; i++) {
        scanf ("%hu", &movement);

        if (movement == 1) movementOne (cupGames);
        if (movement == 2) movementTwo (cupGames);
        if (movement == 3) movementThree (cupGames);
    }

    for (unsigned int i = 0; i < 3; i++) {
        if (cupGames[i]) {
            printf ("%c\n", getReverseKey(i)); break;
        }
    }

    return 0;
}

void limpa_buffer ()
{
    char c;
    while ((c = fgetc(stdin)) != EOF && c != '\n');
}

int getKey (char c)
{
    return (int) c - 65;
}

char getReverseKey (int key)
{
    return (char) key + 65;
}

void movementOne (int * array)
{
    exchange (&array[0], &array[1]);
}

void movementTwo (int * array)
{
    exchange (&array[1], &array[2]);
}

void movementThree (int * array)
{
    exchange (&array[0], &array[2]);
}

void exchange (int * a, int * b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
