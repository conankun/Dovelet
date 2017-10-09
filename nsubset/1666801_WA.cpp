#include<stdio.h>
#include<cmath>

int main(void)
{
	
	int a, b, possibl;
	scanf("%d %d", &a, &b);
	possibl = pow((double)a, (double)b);
	printf("%d", possibl);
	return 0;
}