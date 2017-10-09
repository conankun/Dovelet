#include<stdio.h>


int main(void)
{
	long long int n;
	long long Final;
	scanf("%lld", &n);
	Final = (n*n + 2*n - 1) / n;
	printf("%lld", 3 * Final - 6);

} 