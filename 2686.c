#include <stdio.h>
#include <string.h>
#define SECC 15
#define MIN 60
#define DAY 24

typedef unsigned int u_int;

char * getSaud (char * strings[], u_int key);
 
int main()
{
    double temp_min, grau, temp_sc;
    int hr, min, sec;
    char * saudacoes[2 * SECC] = {"Bom Dia!!", "Boa Tarde!!", "Boa Noite!!", "De Madrugada!!"};
    
    while(scanf("%lf%*c", &grau) != EOF)
    {
        hr = grau / SECC;

        temp_min = (grau - (hr * SECC)) * 60;
        temp_min /= SECC;

        min = temp_min;
        
        temp_sc = temp_min - (int) temp_min;
        sec = temp_sc * MIN;

        hr += 6;

        if (hr >= DAY)
        {
            hr -= DAY;
        }

        printf("%s\n", getSaud (saudacoes, grau/90));
        printf("%02u:%02u:%02u\n", hr, min, sec);
    }
 
    return 0;
}

char * getSaud (char * strings[], u_int key)
{
    return strings[key];
}
