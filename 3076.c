#include <stdio.h>

int main() {
    unsigned int ano;
    while (scanf ("%u", &ano) != EOF) {
        printf("%u\n", (--ano / 100) + 1);
    }
    
    return 0;
}
