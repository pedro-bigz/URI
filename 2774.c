#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXD 100000
#define MAXN 1000000
#define TRUE 1
#define FALSE 0
#define SPC " "
#define HR 60
 
void limpa_buffer ();
double avg (double *v, int n);
double variancia (double *v, double media,  int n);

int main() 
{
    unsigned int i, h, m, qt;
    double x[MAXD], media, v;
    char input[MAXN];
    char *token;
    
    while (scanf("%u %u", &h, &m) != EOF)
    {
        limpa_buffer ();
        scanf(" %[^\n]", input);

        h *= HR;
        i = 0;
        token = strtok(input, SPC);

        while (token != NULL)
        {
            x[i++] = atof(token);
            token = strtok(NULL, SPC);
        }

        media = avg (x, i);
        v = variancia (x, media, i);

        printf("%.5lf\n", v);
    }
 
    return 0;
}

void limpa_buffer ()
{
    char c;
    while ((c = fgetc(stdin)) != EOF && c != '\n');
}

double avg (double *v, int n)
{
    unsigned int i;
    double sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += v[i];
    }

    return sum / n;
}

double variancia (double *v, double media,  int n)
{
    unsigned int i;
    double sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += pow((v[i] - media), 2);
    }

    return sqrt(sum/(n - 1));
}
