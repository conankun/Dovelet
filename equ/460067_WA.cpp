#include<stdio.h>
double a,b,c;
double d,e,f;
int main() {
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	double y=(c*d-a*f)/(b*d-a*e);
	double x=(c-y*b)/a;
	if(a/d == b/e && b/e == c/f) printf("not decided");
	else if(a/d == b/e && b/e != c/f) printf("impossible");
	else printf("%.2lf\n%.2lf",x,y);
}