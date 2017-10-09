#include<stdio.h>
double a,b,c;
double d,e,f;
int main() {
	scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
	double y=(c*d-a*f)/(b*d-a*e);
	double x=(c-y*b)/a;
	double ad=(d==0?0:a/d);
	double be=(e==0?0:b/e);
	double cf=(f==0?0:c/f);
	if(ad== be && be == cf) printf("not decided");
	else if(ad == be && be != cf) printf("impossible");
	else printf("%.2lf\n%.2lf",x,y);
}