#include<stdio.h>
#include<cmath>

int main(void)
{
	
	double a, b, possibl;
	scanf("%lf %lf", &a, &b);
	possibl = pow((double)a,b);
	printf("%lf", possibl);
	return 0;
}