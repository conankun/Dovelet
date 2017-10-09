#include<stdio.h>
int main() {
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	double d = a+(a/100*b);
	double e = d - (d/100*c);
	if(a > e) printf("loss");
	else printf("%.0lf",e/a);
}