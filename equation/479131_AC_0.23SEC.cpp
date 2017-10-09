#include<stdio.h>
int main() {
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	a-=c,d-=b;
	if(a==0 && d==0) printf("many");
	else if(a==0 && d != 0) printf("none");
	else printf("%.3lf",d/(double)a);
}