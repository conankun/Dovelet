#include<stdio.h>
#include<cmath>

int main(void)
{
	
	int a, b;
	float straight, curved, total;
	scanf("%d %d", &a, &b);
	straight = sqrtf(a*a + a*a) + sqrtf(b*b + b*b);
	curved = 3.14159*a + 3.14159*b;
	total = straight + curved;
	printf("%.3lf", total);
	
	return 0;
} 