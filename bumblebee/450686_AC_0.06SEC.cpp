#include<stdio.h>
double a,b,c,d;
int main() {
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	printf("%.6lf",(d/(a+b))*c);
}