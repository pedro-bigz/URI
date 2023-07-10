#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long int ull_t;

int
solve(ull_t * v, ull_t n, ull_t total)
{
    ull_t i, sum = 0, media = total / 2;
    for (i = 0; sum + v[i] <= media && i < n; i++) {
        sum += v[i];
    }

    if (sum == total - sum) {
        return printf("0\n");
    }
    if (abs(sum - media) > abs(sum + v[i] - media)) {
        sum += v[i];
    }

    return printf("%d\n", abs(2 * sum - total));
}

int
main(int argc, char * argv[])
{
    ull_t n, i, sum;
    ull_t * v;
    while (scanf("%llu%*c", &n) != EOF) {
        v = (ull_t *) calloc(n, sizeof(ull_t));
        sum = 0;
        for (i = 0; i < n; i++) {
            scanf("%llu%*c", &v[i]);   
            sum += v[i];
        }
        solve(v, n, sum);
    }
    return 0;
}