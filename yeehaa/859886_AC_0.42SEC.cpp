#include<math.h>
#include<stdio.h>
#define PI 3.14159265358979323846264338327950288419716939937510
double a,b;//r,n
int main() {
	scanf("%lf%lf",&a,&b);
	double seta  = 2*PI / b;
	double sins = sin(seta/2);
	printf("%.3lf",(a*sins)/(1+sins));
}