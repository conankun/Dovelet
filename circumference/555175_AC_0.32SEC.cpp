#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793
double a,b,c,d,e,f,x,y;
int main() {
	scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
	x=((-2*d+2*b)*(e*e+f*f-c*c-d*d)+(2*d-2*f)*(a*a+b*b-c*c-d*d))/((-2*c+2*e)*(-2*d+2*b)-(-2*d+2*f)*(-2*c+2*a));
	y=((2*c-2*a)*(e*e+f*f-c*c-d*d) + (-2*c+2*e)*(a*a+b*b-c*c-d*d))/((-2*c+2*e)*(-2*d+2*b)-(-2*d+2*f)*(-2*c+2*a));
	printf("%.2lf",sqrt((x-a)*(x-a) + (y-b)*(y-b))*2*PI);
}