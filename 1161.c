#include <stdio.h>
#include <stdlib.h>

long long int fat (int n);

int
main()
{
	unsigned short int m = 0 , n = 0, i;
	long long int x = 0;
	while (scanf("%hu %hu", &m, &n) != EOF)
	{
		x = fat(m) + fat(n);
		printf("%lld\n", x);
	}
	system("pause");
	return 0;
}

long long int
fat (int n)
{	
	if(n == 0)
		return 1;
	int i;
	long long int f = 1;
	for(i = 1; i <= n; i++)
		f *= i; 
	return f;
}
