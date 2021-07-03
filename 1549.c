#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

#define PI M_PI

using namespace std;


int main()
{
    unsigned int casos;
    
    double n, l, r, R, H, x1, tmp;
    
    scanf("%u", &casos);
    
    while (casos--)
    {
        scanf("%lf %lf", &n, &l);
        scanf("%lf %lf %lf", &r, &R, &H);
        
        x1 = (l / n); 
        
        tmp = pow(x1 * 3.0 * (R - r)/ (PI  * H) + r * r * r, 1.0 / 3.0);
        
        cout << setprecision(2) << fixed << x1 * 3.0 / (PI *(tmp * tmp + tmp * r + r * r)) << endl;
    }
}
