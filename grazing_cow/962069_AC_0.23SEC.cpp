#include<stdio.h>
#include<math.h>
int main() {
	double pi=2*acos(0.0);
	double d,l;
	scanf("%lf%lf",&d,&l);
	// a = l/2
	double b = sqrt((l/2.)*(l/2.)-(d/2.)*(d/2.));
	double a = l/2;
	printf("%.3lf",pi*a*b);
}