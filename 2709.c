#include <stdio.h>
#include <stdlib.h>

short
isPrime(int n)
{
    int i;
    if (n == 2) return 1;
    if (n == 1 || !(n & 1)) return 0;
    for (i = 3; i <= n / i; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void
solve(int * v, int m, int n)
{
    int i, sum = 0;
    for (i = 0; i < m; i += n) {
        sum += v[i];
    }
    // printf("%d\n", sum);
    if (isPrime(sum)) {
        printf("You’re a coastal aircraft, Robbie, a large silver aircraft.\n");
    } else {
        printf("Bad boy! I’ll hit you.\n");
    }
}

int
main(int argc, char * argv[])
{
    int n, m, i;
    int * v;
    while (scanf("%d%*c", &m) != EOF) {
        v = (int *) calloc(m, sizeof(int));
        for (i = m - 1; i >= 0; i--) {
            scanf("%d%*c", &v[i]);   
        }
        scanf("%d%*c", &n);
        solve(v, m, n);
    }
    return 0;
}