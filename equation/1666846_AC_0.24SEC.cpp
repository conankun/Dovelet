#include<stdio.h>
#include<cmath>

int main(void)
{
	double a, b, c, d;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	if ((a - c) == 0 && (b - d) != 0){
		printf("none\n");
	}
	else if ((a - c) == 0 && (b - d) == 0){
		printf("many\n");
	}
	else
	{
		printf("%.3lf\n", (d - b) / (a - c));
	}
}