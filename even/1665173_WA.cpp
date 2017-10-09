#include<stdio.h>
#include<cmath>

int main(void)
{
	long long int a, d;
	long long int b, c;
	
	scanf("%lld %lld", &a, &b);
	c = sqrt(b - a);
	d = (b - a) - c + 1;
	printf("%d", d);
} 