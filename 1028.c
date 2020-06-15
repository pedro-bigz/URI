#include <stdio.h>

unsigned int mdc (int dividendo, int divisor);

int main() {
    unsigned int casos, f1, f2;

    scanf("%u", &casos);

    while (casos--)
    {
        scanf("%u %u", &f1, &f2);
        printf("%u\n", mdc (f1, f2));
    }

    return 0;
}

unsigned int mdc (int dividendo, int divisor)
{
    int resto;

    do
    {
        resto = dividendo % divisor;

        dividendo = divisor;
        divisor = resto;
    }
    while (resto);

    return dividendo;
}
